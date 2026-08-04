# 🌱 EcoSense: IoT-Based Smart Environmental Monitoring and Gas Detection System Using ESP32

## 📖 Overview

EcoSense is an IoT-based environmental monitoring system developed using the ESP32 microcontroller. The system continuously monitors environmental parameters such as **temperature**, **humidity**, and **gas levels**, providing real-time visual and audible alerts whenever unsafe conditions are detected.

Sensor data is displayed on an OLED display and is designed to be integrated with the ThingSpeak cloud platform for remote monitoring and data visualization.

This project was developed to strengthen practical skills in **Embedded Systems**, **IoT**, **sensor interfacing**, and **microcontroller programming**.

---
## 🔗 Live Simulation

Experience the project in your browser using Wokwi:

**▶ Wokwi Simulation:** https://wokwi.com/projects/471080600462922753



## 🚀 Project Highlights

- ESP32-based Embedded System
- Real-time Environmental Monitoring
- OLED Display Interface
- Gas Detection using MQ-2
- Temperature & Humidity Monitoring
- RGB LED Status Indicators
- Active Buzzer Alerts
- Cloud Integration with ThingSpeak (In Progress)

## ✨ Features

- 🌡️ Real-time Temperature Monitoring (DHT22)
- 💧 Humidity Monitoring
- 🚨 Gas Detection using MQ-2 Sensor
- 📟 OLED Display for Live Sensor Data
- 🔴🟢🔵 RGB LED Status Indication
- 🔔 Buzzer Alert for Dangerous Conditions
- 📊 Serial Monitor Output for Debugging
- ☁️ Designed for ThingSpeak IoT Integration
- 🔧 Modular and Well-Structured Code

---

## 🛠️ Hardware Components

| Component | Quantity |
|-----------|----------|
| ESP32 DevKit V1 | 1 |
| DHT22 Temperature & Humidity Sensor | 1 |
| MQ-2 Gas Sensor | 1 |
| SSD1306 OLED Display (128×64 I2C) | 1 |
| RGB LED | 1 |
| Active Buzzer | 1 |
| Breadboard | 1 |
| Jumper Wires | As Required |

---

## 💻 Software Used

- Arduino IDE
- ESP32 Board Package
- Wokwi Simulator
- ThingSpeak (Cloud Platform)
- Git & GitHub

---

## 🔌 Pin Connections

| Component | ESP32 Pin |
|-----------|-----------|
| DHT22 Data | GPIO 4 |
| MQ-2 Analog Output | GPIO 34 |
| OLED SDA | GPIO 21 |
| OLED SCL | GPIO 22 |
| Red LED | GPIO 25 |
| Green LED | GPIO 26 |
| Blue LED | GPIO 27 |
| Buzzer | GPIO 13 |

---

## ⚙️ Working Principle

1. ESP32 continuously reads temperature and humidity from the DHT22 sensor.
2. Gas concentration is monitored using the MQ-2 sensor.
3. Sensor values are displayed on the OLED display.
4. The firmware classifies environmental conditions into:
   - ✅ NORMAL
   - ⚠️ WARNING
   - 🚨 DANGER
5. According to the detected condition:
   - RGB LED changes color
   - Buzzer is activated (Danger state)
   - Data is displayed on the Serial Monitor
6. The project is designed for cloud integration using ThingSpeak for remote monitoring.

---

## 🚦 Status Logic

| Condition | RGB LED | Buzzer |
|------------|---------|---------|
| Normal | 🟢 Green | OFF |
| Warning | 🔵 Blue | OFF |
| Danger | 🔴 Red | ON |

---

## 📂 Project Structure

```
EcoSense/
│
├── EcoSense.ino
├── README.md
├── images/
│   ├── circuit.png
│   ├── oled_output.png
│   ├── serial_monitor.png
│   └── thingspeak_dashboard.png
└── LICENSE
```



## 🚀 Future Enhancements

- Wi-Fi connectivity using ESP32
- Live data upload to ThingSpeak
- Mobile dashboard integration
- Email/Telegram alert notifications
- Historical data visualization
- Additional environmental sensors
- Low-power operation with Deep Sleep Mode

---

## 📚 Concepts Demonstrated

- Embedded Systems Programming
- ESP32 Development
- GPIO Configuration
- Analog & Digital Sensor Interfacing
- I2C Communication
- OLED Display Control
- Decision-Based Embedded Logic
- IoT Fundamentals
- Serial Communication
- Modular Firmware Development

---

## Author

**Satvika Saraswathi**

B.Tech – Electronics and Communication Engineering (ECE)

Interested in Embedded Systems • IoT • Edge Computing

GitHub: https://github.com/SATVIKASARASWATHI-08

LinkedIn: https://www.linkedin.com/in/satvika-saraswathi

---

## ⭐ If you found this project interesting, feel free to star the repository!
