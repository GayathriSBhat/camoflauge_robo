# Camouflage Robo

**Camouflage Robo** is an Arduino-based robotic system designed to detect **heat, smoke, and motion** in challenging environments such as warzones or high-risk areas. When the robot detects any abnormal signature (fire, heat, motion), it sends alerts to a remote controller for monitoring and response.

This project uses **Arduino and Embedded C** to interface sensors and communication modules to build an autonomous alert system.

---

## 🎯 Features

- **Heat Detection**  
  Uses thermal/temperature sensor modules to identify potentially dangerous heat sources.

- **Smoke Detection**  
  Integrates smoke / gas sensors to ensure early detection of smoke or hazardous leaks.

- **Motion Detection**  
  Tracks movement in the environment, which can help detect intruders or activity.

- **Remote Alerts**  
  Sends alerts to a controller or monitoring system when threats are detected.

- **Camouflage Deployment**  
  Designed for use in rugged and covert applications, useful for surveillance and safety in hostile or inaccessible areas.

---

## 📦 Repository Contents

| File | Description |
|------|-------------|
| `blynk.ino` | Example sketch showing integration with Blynk (mobile IoT control) |
| `camouflageA.ino` | Primary control sketch for robot A implementation |
| `camouflageB.ino` | Control sketch for robot B (alternate configuration) |

---

## 🛠️ Hardware Requirements

To build and run this project, typical components include:

- Arduino board (e.g., **Arduino Uno / NodeMCU**)
- Thermal or heat sensor (e.g., **MLX90614**, **LM35**, etc.)
- Smoke / gas sensor (e.g., **MQ-2 / MQ-135**)
- PIR motion sensor
- Communication module (Wi-Fi / Bluetooth module or Blynk)
- Power supply and chassis for the robot

---

## 🚀 Getting Started

1. **Clone the repo**

   ```bash
   git clone https://github.com/GayathriSBhat/camoflauge_robo.git
