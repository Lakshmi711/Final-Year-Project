# Final-Year-Project

# 🌱 Smart Tomato Growth Monitoring System using IoT

## 📌 Overview
This is an **IoT-based agriculture monitoring system** designed to track **tomato plant growth** in red soil under **high temperature and humidity**.  
It measures **NPK nutrients, pH, soil moisture, temperature, and humidity**, and sends real-time data to **Ubidots** and **Google Sheets** for visualization and analysis.

---

## 🚀 Features
- 🌱 **Soil NPK Sensor (RS485)** — Measures Nitrogen, Phosphorus, Potassium levels
- 🌡️ **DHT22 Sensor** — Measures temperature and humidity
- 💧 **Analog Soil Moisture Sensor** — Tracks soil water content
- 📊 **Ubidots Dashboard** — Real-time monitoring with visual charts
- 📑 **Google Sheets Integration** — Stores historical data for analysis
- 📶 **ESP32 Wi-Fi Microcontroller** — Wireless IoT data transmission

---

## 🛠️ Hardware Used
| Component | Quantity | Purpose |
|-----------|----------|---------|
| ESP32 Development Board | 1 | Main IoT controller |
| Soil NPK Sensor (RS485) | 1 | Nutrient measurement |
| RS485 to TTL Converter  | 1 | Communication with ESP32 |
| DHT22 Temperature/Humidity Sensor | 1 | Climate monitoring |
| Analog Soil Moisture Sensor | 1 | Irrigation monitoring |
| Breadboard & Jumper Wires | - | Circuit assembly |
| Power Supply (5V) | 1 | Device powering |

---

## 🔌 Wiring Diagram
| ESP32 Pin | Device | Description |
|-----------|--------|-------------|
| 16        | RS485  | RX |
| 17        | RS485  | TX |
| 4         | RS485  | RE |
| 5         | RS485  | DE |
| 23        | DHT22  | Data |
| 34        | Soil Moisture | Analog Output |

---

## 📜 How It Works
1. **ESP32** reads sensor data:
   - NPK & pH via **RS485**
   - Temperature & humidity via **DHT22**
   - Soil moisture via **analog sensor**
2. Data is sent to:
   - **Ubidots IoT Platform** — Live visualization & alerts
   - **Google Sheets** — Historical data logging
3. Farmers or researchers can **remotely monitor** and decide nutrient or water adjustments.

---

## 📂 Project Structure
