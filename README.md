# 📡 ESP32 Wireless Communication Device

![ESP32](https://img.shields.io/badge/ESP32-Project-blue)
![Protocol](https://img.shields.io/badge/ESP--NOW-Wireless-green)
![Status](https://img.shields.io/badge/status-active-success)

---

## 📖 Overview

This project implements a compact wireless communication system using two ESP32 microcontrollers.  
The devices communicate directly using the **ESP-NOW protocol**, enabling fast, low-power, peer-to-peer messaging without requiring a Wi-Fi network or internet connection.

The system is designed as a simple, portable communication device, similar to a minimal walkie-talkie, with visual and audio feedback.

---

## 🧰 Hardware Components

Each device is equipped with:

- 📺 SSD1306 OLED display (128x64) for real-time message visualization  
- 🔘 Push button for message transmission  
- 🔊 Buzzer for audio notifications  
- 💡 LED for visual feedback  
- 📡 ESP32 microcontroller

---

## 🚀 Features

### 📡 ESP-NOW Communication
- Sends and receives short text messages instantly  
- No router, Wi-Fi network, or internet required  

### 🖥️ Real-Time Display
- Incoming and outgoing messages are displayed on the OLED screen  

### 🎮 User Interaction
- Button press triggers message transmission  

### 🔔 Feedback System
- LED and buzzer activate upon message reception  

### 🎬 Startup Animation
- Custom bitmap icons are displayed during boot for a simple UI experience  

---

## ⚙️ How It Works

- ESP32 operates in **WIFI_STA mode** and initializes ESP-NOW  
- Devices are paired using each other's MAC addresses  

### 📤 Sending
- Button press → predefined message is sent via ESP-NOW  

### 📥 Receiving
- Message is received via callback  
- Buzzer and LED are triggered  
- Message is displayed on the OLED  

All communication events are handled using **ESP-NOW callbacks** for efficiency and responsiveness.

---

## 🧠 Technologies Used

- ESP32 (Arduino framework)  
- ESP-NOW wireless protocol  
- I2C communication (OLED display)  
- Adafruit GFX & SSD1306 libraries  

---

## 📸 Preview

![Prototype](prototype_version_2.jpeg)

---

## 🔧 Future Improvements (Contributions Welcome 🚀)

### 🧑‍💻 Software
- ⌨️ Dynamic message input (keyboard module / serial input)  
- 📋 Menu-based UI (multi-screen navigation, **U8g2 library**)  
- 💾 Message history storage (EEPROM / SPIFFS)  
- 🔒 Encrypted ESP-NOW communication  
- 🔋 Power optimization & sleep modes  

### 🔌 Hardware & PCB
- 🧩 Custom PCB integrating all components  
- 📦 Compact enclosure (3D printed case)  
- 🔋 Battery charging circuit (TP4056 or similar)  

### 📍 Advanced Features
- 📡 GPS module → send real-time location  
- 📷 ESP32-CAM → image capture & transmission  
- 🎤 Microphone → voice messages  
- 🔊 Speaker → audio playback  

### 🌐 Connectivity Expansion
- 📶 Hybrid communication: ESP-NOW + Wi-Fi  
- ☁️ Cloud sync when Wi-Fi is available  

### 🤖 AI Integration
- 🔍 Image recognition (object / person detection)  
- 🗣️ Voice-to-text messaging  

---

## 📡 Long-Range Communication (LoRa / Antenna Integration)

- 📶 External antenna integration to improve ESP-NOW/Wi-Fi range  
- 🛰️ LoRa / LoRaWAN module (e.g., SX1276, RFM95) for **km-range communication**  

---

## 📌 Use Cases

- 📡 Walkie-talkie style communication device  
- 🌍 Offline communication in remote areas  
- 🚨 Emergency communication system  
- 🏠 IoT notification system  
- 🎓 Educational embedded systems project  

---

## ⚡ Getting Started

## ⚡ Getting Started

1. Install Arduino IDE  
2. Install required libraries:
   - Adafruit GFX  
   - Adafruit SSD1306  
3. Clone or download this repository  
4. Upload the code to both ESP32 devices  
5. Set the correct **peer MAC address** in the code for each device  
6. Connect all components using I2C (Wire) and GPIO pins  
7. Power both devices and test communication   
8. Open Serial Monitor (115200 baud) for debugging
---

## 💡 Project Vision

This project can evolve into a fully standalone **portable communication device**, combining messaging, location tracking, AI features, and multimedia capabilities in a compact embedded system.
