# Final-Year-Project

# 🌱 Smart Tomato Growth Monitoring System using IoT

ESP32-Based Smart Agriculture Monitoring System

An IoT-based agriculture monitoring system using ESP32 to collect and send soil nutrient, environmental, and weather data to Ubidots and Google Sheets for real-time analysis.

Table of Contents

About

Features

Components Used

How It Works

How to Run

Technologies Used

Author

About

This project is a smart agriculture monitoring system that helps farmers track key parameters like Soil NPK values, Temperature, Humidity, and Soil Moisture.
The data is sent to Ubidots for IoT dashboard visualization and stored in Google Sheets for long-term analysis.
It uses RS485-to-TTL communication for the NPK sensor and a hardened ESP32 firmware with Wi-Fi reconnection, Modbus CRC checking, and non-blocking data acquisition.

Features

Reads Soil NPK values using an RS485-to-TTL interface.

Measures temperature and humidity with DHT sensor.

Measures soil moisture with an analog soil sensor.

Sends data to Ubidots IoT cloud.

Logs data into Google Sheets via Apps Script Webhook.

Built-in CRC and timeout handling for stable sensor reading.

Wi-Fi auto-reconnect for reliability.

Components Used

ESP32 Dev Board

Soil NPK Sensor (RS485)

RS485 to TTL Converter

DHT11/DHT22 Temperature & Humidity Sensor

Analog Soil Moisture Sensor

Jumper Wires & Breadboard

Power Supply (5V)

How It Works

The ESP32 reads NPK values from the sensor via RS485 protocol.

The DHT sensor reads temperature and humidity.

The analog sensor measures soil moisture and converts it to percentage.

Data is pushed to Ubidots via HTTPS and sent to Google Sheets for storage.

The system automatically retries in case of sensor or Wi-Fi failure.

How to Run

Clone this repository:

git clone https://github.com/YourUsername/esp32-smart-agriculture.git
cd esp32-smart-agriculture


Open the .ino file in Arduino IDE.

Install required libraries:

WiFi.h (Built-in)

HTTPClient.h (Built-in)

DHT.h (DHT sensor library)

ModbusMaster.h (RS485 communication)

Update the following in the code:

Wi-Fi SSID & Password

Ubidots Token & Variable IDs

Google Sheets Webhook URL

Connect your ESP32 and upload the code.

Technologies Used

Arduino IDE for firmware development

ESP32 Wi-Fi Module for connectivity

Ubidots for IoT dashboard visualization

Google Sheets for data logging

RS485 Modbus Protocol for NPK sensor communication

Author

Lakshmi K

GitHub: Lakshmi711

LinkedIn: Lakshmi711
