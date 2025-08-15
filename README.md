# Final-Year-Project

# 🌱 Smart Tomato Growth Monitoring System using IoT

ESP32-based smart agriculture monitoring system for tomato crops in red soil conditions, integrating NPK, pH, soil moisture, temperature, and humidity sensors with Ubidots and Google Sheets for real-time and historical data tracking.

## Table of Contents
- [About](#about)
- [Features](#features)
- [Components Used](#components-used)
- [How It Works](#how-it-works)
- [How to Run](#how-to-run)
- [Technologies Used](#technologies-used)
- [Author](#author)

## About
This project is an **IoT-based agriculture monitoring system** that uses ESP32 to collect environmental and soil nutrient data for tomato plants.  
It works under **high temperature and humidity** conditions and is optimized for **red soil cultivation**.  
The data is sent to **Ubidots** for live monitoring and **Google Sheets** for historical analysis.

## Features
- 🌱 **NPK Sensor (RS485)** for nutrient measurement (Nitrogen, Phosphorus, Potassium)
- 🌡️ **DHT22** for temperature and humidity monitoring
- 💧 **Analog Soil Moisture Sensor** for irrigation tracking
- 📊 **Ubidots Dashboard** for real-time data visualization
- 📑 **Google Sheets Integration** for data logging
- 📶 **ESP32 Wi-Fi** connectivity for wireless data transmission

## Components Used
| Component | Quantity | Purpose |
|-----------|----------|---------|
| ESP32 Development Board | 1 | IoT microcontroller |
| Soil NPK Sensor (RS485) | 1 | Nutrient measurement |
| RS485 to TTL Converter | 1 | Serial communication |
| DHT22 Sensor | 1 | Temperature & humidity |
| Analog Soil Moisture Sensor | 1 | Irrigation monitoring |
| Breadboard & Jumper Wires | - | Circuit assembly |
| Power Supply (5V) | 1 | Device powering |

## How It Works
1. **ESP32** collects data from:
   - RS485 NPK sensor for Nitrogen, Phosphorus, and Potassium
   - DHT22 sensor for temperature and humidity
   - Analog soil moisture sensor
2. Data is sent to:
   - **Ubidots** for real-time visualization and alerts
   - **Google Sheets** for historical tracking
3. The system allows farmers and researchers to monitor crops remotely and make informed decisions.

## How to Run
1. **Install Arduino IDE** and add **ESP32 board support**.
2. **Install required libraries**:
   - `WiFi.h`
   - `HTTPClient.h`
   - `HardwareSerial.h`
   - `DHT.h`
3. **Clone this repository**:
   ```bash
   git clone https://github.com/Lakshmi711/Smart-Agriculture-Growth-Monitoring-IoT.git
4.Open final_agriculture.ino in Arduino IDE.

5.Update the following in the code:

6.Wi-Fi SSID & Password

7.Ubidots Token

8.Google Script URL

9.Upload the code to the ESP32.

10.Open Serial Monitor to check live readings and confirm data transmission.

## 🛠 Technologies Used

- ESP32 (Wi-Fi enabled microcontroller)

- Ubidots (IoT dashboard for visualization)

- Google Sheets (data logging)

- Arduino IDE (programming environment)

- Sensors: NPK RS485, DHT22, Analog Soil Moisture Sensor

## Author
**Lakshmi K**  
- GitHub: [Lakshmi711](https://github.com/Lakshmi711)  
- LinkedIn: [Lakshmi711](https://www.linkedin.com/in/lakshmi-ramesh07/)  

