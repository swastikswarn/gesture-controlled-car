# 🤖 Gesture Controlled Car using Arduino

Control a robotic car using **hand gestures** instead of a joystick!  
This project uses an **accelerometer (BMI160)** and **Bluetooth (HC-05)** to send motion commands wirelessly to a 4-wheel drive robot car.

📹 Project demo available on YouTube (link in description).

---

## 🚀 Features
- ✋ Real-time hand gesture control
- 📡 Wireless Bluetooth communication
- ⚙️ Simple direction commands (F, B, L, R, S)
- 🔧 Easy to build with basic Arduino components
- 🧠 Raw I²C communication (no sensor library used)

---

## 🧩 Project Overview

### Transmitter (Hand Controller)
- Reads hand tilt using **BMI160 accelerometer**
- Converts motion into commands:
  - `F` – Forward  
  - `B` – Backward  
  - `L` – Left  
  - `R` – Right  
  - `S` – Stop
- Sends commands via **HC-05 (Master mode)**

### Receiver (Car)
- Receives commands via **HC-05 (Slave mode)**
- Controls motors using **Adafruit Motor Shield v1**

---

## 🛠️ Components Required

### 🔹 Transmitter Side
- Arduino Nano
- BMI160 Accelerometer
- HC-05 Bluetooth Module
- Battery (3.7V / 5V)
- Connecting wires

### 🔹 Receiver Side
- Arduino Uno R3
- Adafruit Motor Shield v1
- 4 × DC BO Motors
- Robot chassis + wheels
- HC-05 Bluetooth Module
- Battery pack

---

## 🔌 Connections

### BMI160 (I²C Mode)
| BMI160 Pin | Arduino Nano |
|----------|--------------|
| VCC | 3.3V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |
| CS  | 3.3V |
| SA0 | GND |

### HC-05 (Both Sides)
| HC-05 | Arduino |
|-----|---------|
| TX | RX |
| RX | TX (via voltage divider) |
| VCC | 5V |
| GND | GND |

---

## 📂 Code Structure

```text
.
├── transmitter/
│   └── gesture_transmitter.ino
├── receiver/
│   └── bluetooth_car_receiver.ino
└── README.md
