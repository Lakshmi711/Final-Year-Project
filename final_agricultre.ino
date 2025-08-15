#include <WiFi.h>
#include <HTTPClient.h>
#include <HardwareSerial.h>
#include <DHT.h>
#define RE 4
#define DE 5
#define DHTPIN 23
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
#define SOIL_MOISTURE_PIN 34

const byte nitro[] = {0x01, 0x03, 0x00, 0x1E, 0x00, 0x01, 0xE4, 0x0C};
const byte phos[]  = {0x01, 0x03, 0x00, 0x1F, 0x00, 0x01, 0xB5, 0xCC};
const byte pota[]  = {0x01, 0x03, 0x00, 0x20, 0x00, 0x01, 0x85, 0xC0};
const byte phVal[] = {0x01, 0x03, 0x00, 0x21, 0x00, 0x01, 0xF5, 0xC3};

byte values[7];
HardwareSerial mod(1); 

const char* ssid = "YOUR WIFI NAME";
const char* password = "YOUR WIFI PASSWORD";

const char* ubidotsToken = "ENTER YOU UBIDOTS KEY";
const char* deviceLabel = "tomato";
const char* ubidotsServer = "http://industrial.api.ubidots.com/api/v1.6/devices/";

const char* googleScriptURL = "https://script.google.com/macros/s/AKfycbzxy4crZupFDmho1d3R_9Z7PeOZgGI9oxk11eSUWhNGiSDsG7Abt6eeX3zLUVIZX4Mn0Q/exec";  // Replace with actual script URL

void setup() {
    Serial.begin(115200);
    mod.begin(9600, SERIAL_8N1, 16, 17);  // UART1: RX=16, TX=17

    pinMode(RE, OUTPUT);
    pinMode(DE, OUTPUT);
    digitalWrite(DE, LOW);
    digitalWrite(RE, LOW);

    pinMode(SOIL_MOISTURE_PIN, INPUT);

    dht.begin();
    delay(500);

    WiFi.begin(ssid, password);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nConnected to Wi-Fi");
}

void loop() {
    int nitrogen = readSensor(nitro);
    int phosphorus = readSensor(phos);
    int potassium = readSensor(pota);
    float pH = readSensor(phVal) / 100.0;

    int soilMoistureRaw = analogRead(SOIL_MOISTURE_PIN);
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    int DRY_VALUE = 3000;
    int WET_VALUE = 1000;
    int soilMoisture = map(soilMoistureRaw, DRY_VALUE, WET_VALUE, 0, 100);
    soilMoisture = constrain(soilMoisture, 0, 100);

    Serial.println("\n=== SENSOR DATA ===");
    Serial.printf("Nitrogen: %d mg/kg\n", nitrogen);
    Serial.printf("Phosphorous: %d mg/kg\n", phosphorus);
    Serial.printf("Potassium: %d mg/kg\n", potassium);
    Serial.printf("pH Level: %.2f\n", pH);
    Serial.printf("Soil Moisture: %d%%\n", soilMoisture);
    Serial.printf("Temperature: %.2f°C\n", temperature);
    Serial.printf("Humidity: %.2f%%\n", humidity);
    Serial.println("====================");

    sendToUbidots(temperature, humidity, soilMoistureRaw, soilMoisture, nitrogen, phosphorus, potassium, pH);
    sendToGoogleSheets(temperature, humidity, soilMoistureRaw, soilMoisture, nitrogen, phosphorus, potassium, pH);

    delay(12000); // 12 seconds delay
}

int readSensor(const byte *command) {
    mod.flush();
    digitalWrite(DE, HIGH);
    digitalWrite(RE, HIGH);
    delay(2);

    for (uint8_t i = 0; i < 8; i++) mod.write(command[i]);
    mod.flush();

    digitalWrite(DE, LOW);
    digitalWrite(RE, LOW);
    delay(200);

    int bytesReceived = mod.available();
    if (bytesReceived < 7) {
        Serial.println("Error: No response from sensor!");
        return 0;
    }

    for (byte i = 0; i < 7; i++) {
        values[i] = mod.read();
    }

    int value = (values[3] << 8) | values[4];

    if (command == phVal) {
        return constrain(value, 0, 700);
    }

    return constrain(value, 0, 1999);
}

void sendToUbidots(float temp, float hum, int soilRaw, int soilMoisture, float n, float p, float k, float ph) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        String url = String(ubidotsServer) + deviceLabel + "?token=" + ubidotsToken;
        String payload = "{";
        payload += "\"temperature\":" + String(temp) + ",";
        payload += "\"humidity\":" + String(hum) + ",";
        payload += "\"soil_moisture_raw\":" + String(soilRaw) + ",";
        payload += "\"soil_moisture\":" + String(soilMoisture) + ",";
        payload += "\"nitrogen\":" + String(n) + ",";
        payload += "\"phosphorus\":" + String(p) + ",";
        payload += "\"potassium\":" + String(k) + ",";
        payload += "\"ph_level\":" + String(ph);
        payload += "}";

        http.begin(url);
        http.addHeader("Content-Type", "application/json");
        int response = http.POST(payload);

        Serial.println("\nData sent to Ubidots:");
        Serial.println(payload);
        Serial.println("HTTP Response: " + String(response));
        http.end();
    }
}

void sendToGoogleSheets(float temp, float hum, int soilRaw, int soilMoisture, float n, float p, float k, float ph) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        http.begin(googleScriptURL);
        http.addHeader("Content-Type", "application/json");

        String payload = "{";
        payload += "\"temperature\":" + String(temp) + ",";
        payload += "\"humidity\":" + String(hum) + ",";
        payload += "\"soil_moisture_raw\":" + String(soilRaw) + ",";
        payload += "\"soil_moisture\":" + String(soilMoisture) + ",";
        payload += "\"nitrogen\":" + String(n) + ",";
        payload += "\"phosphorus\":" + String(p) + ",";
        payload += "\"potassium\":" + String(k) + ",";
        payload += "\"ph_level\":" + String(ph);
        payload += "}";

        int responseCode = http.POST(payload);
        Serial.println("\nData sent to Google Sheets:");
        Serial.println(payload);
        Serial.println("HTTP Response: " + String(responseCode));
        http.end();
    }
}
