# 🚒 ESP32 Bluetooth Fire Fighting Car

A Bluetooth-controlled firefighting robot car built using **ESP32**, **L298N Motor Driver**, DC motors, and a buzzer. The car can be controlled wirelessly from an Android Bluetooth terminal or custom mobile application.

## ✨ Features

* 📱 Bluetooth Control using ESP32 Classic Bluetooth
* ⬆️ Move Forward
* ⬇️ Move Backward
* ⬅️ Turn Left
* ➡️ Turn Right
* 🛑 Stop Motors
* 🔊 Trigger Buzzer
* ⚡ Easy to Flash and Deploy

---

## 🛠 Hardware Requirements

| Component               | Quantity    |
| ----------------------- | ----------- |
| ESP32 Development Board | 1           |
| L298N Motor Driver      | 1           |
| DC Gear Motors          | 2           |
| Robot Chassis           | 1           |
| Buzzer                  | 1           |
| Battery Pack (7.4V/12V) | 1           |
| Jumper Wires            | As Required |

---

## 🔌 Wiring Connections

### Motor Driver → ESP32

| L298N Pin | ESP32 Pin |
| --------- | --------- |
| ENA       | GPIO 27   |
| IN1       | GPIO 25   |
| IN2       | GPIO 26   |
| ENB       | GPIO 13   |
| IN3       | GPIO 14   |
| IN4       | GPIO 23   |

### Buzzer

| Component | ESP32 Pin |
| --------- | --------- |
| Buzzer +  | GPIO 33   |
| Buzzer -  | GND       |

### Power

* L298N Motor Supply → Battery Pack
* ESP32 → USB or regulated 5V supply
* Common Ground between ESP32 and L298N

---

## 📂 Project Structure

```text
ESP32-FireFighting-Car/
│
├── ESP32_FireFighting_Car.ino
├── README.md
└── images/
```

---

## 📥 Software Requirements

### Arduino IDE

Install:

* Arduino IDE 2.x
* ESP32 Board Package

---

## 🚀 Installing ESP32 Board Package

1. Open Arduino IDE
2. Go to:

```text
Arduino IDE → Settings
```

3. Add the following URL to **Additional Boards Manager URLs**

```text
https://espressif.github.io/arduino-esp32/package_esp32_index.json
```

4. Open:

```text
Tools → Board → Boards Manager
```

5. Search:

```text
esp32
```

6. Install:

```text
ESP32 by Espressif Systems
```

---

## 📦 Required Library

The sketch uses:

```cpp
#include <BluetoothSerial.h>
```

This library comes pre-installed with the ESP32 board package.

No additional libraries are required.

---

## 🔥 Uploading the Code

### Step 1

Clone the repository

```bash
git clone https://github.com/your-username/ESP32-FireFighting-Car.git
```

### Step 2

Open:

```text
ESP32_FireFighting_Car.ino
```

in Arduino IDE.

### Step 3

Select your board:

```text
Tools → Board → ESP32 Dev Module
```

(or your specific ESP32 model)

### Step 4

Select the correct COM/Serial Port:

```text
Tools → Port
```

### Step 5

Click:

```text
Verify ✓
```

to compile the project.

### Step 6

Click:

```text
Upload →
```

to flash the firmware.

### Step 7

Open Serial Monitor:

```text
115200 baud
```

Expected output:

```text
Starting ESP32...
Bluetooth Started Successfully
Device Name: ESP32_CAR
Bluetooth Car Ready
```

---

## 📱 Bluetooth Pairing

1. Power on ESP32.
2. Enable Bluetooth on your phone.
3. Search for devices.
4. Connect to:

```text
ESP32_CAR
```

5. Open a Bluetooth Terminal App or your custom controller app.
6. Send commands listed below.

---

## 🎮 Control Commands

| Command | Action          |
| ------- | --------------- |
| F       | Move Forward    |
| B       | Move Backward   |
| L       | Turn Left       |
| R       | Turn Right      |
| S       | Stop            |
| Y       | Activate Buzzer |

Both uppercase and lowercase commands are supported.

Examples:

```text
F
```

Forward

```text
B
```

Backward

```text
S
```

Stop

---

## 📋 Serial Monitor Logs

Example:

```text
Received Command: F
Moving Forward

Received Command: L
Turning Left

Received Command: S
Stopped
```

---

## 🔧 Pin Configuration

```cpp
#define ENA 27
#define IN1 25
#define IN2 26

#define ENB 13
#define IN3 14
#define IN4 23

#define BUZZER_PIN 33
```

Modify these values if your wiring differs.

---

## 🧪 Troubleshooting

### Bluetooth Device Not Visible

* Ensure ESP32 is powered.
* Reset ESP32.
* Check Serial Monitor for startup logs.

### Upload Failed

Try holding the **BOOT** button while clicking Upload.

### Motors Not Moving

* Verify motor power supply.
* Check L298N wiring.
* Ensure common GND between ESP32 and motor driver.

### Wrong Motor Direction

Swap motor wires or modify motor control logic in the code.

---

## 🚀 Future Improvements

* Fire detection sensor
* Water pump control
* Obstacle avoidance
* Wi-Fi control
* Camera streaming
* Mobile app interface
* PWM speed control
