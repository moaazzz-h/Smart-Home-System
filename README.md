# Smart Home System 🏠

## ATmega32-Based Embedded Control Project

A password-protected smart home control system based on the **ATmega32 microcontroller**.

The system is designed to combine manual and automatic control of home appliances, temperature monitoring, door access control, and security alarms through a **4x4 keypad** and **20x4 LCD**.

---

## 🚀 Project Status

The project is currently under development.

### Completed
- [x] DIO Driver
- [x] LCD Driver
- [x] Keypad Driver
- [x] ADC Driver
- [x] LM35 Temperature Sensor Driver
- [x] LM35 Temperature Reading on LCD

### In Progress
- [ ] LDR Light Sensor
- [ ] Automatic Lighting
- [ ] LEDs Control
- [ ] Buzzer Alarm
- [ ] Timer/PWM Driver
- [ ] Servo Motor Control
- [ ] Password System
- [ ] Main Menu
- [ ] Full System Integration

---

## 🧰 Hardware Components

| Component | Function |
|---|---|
| ATmega32 | Main microcontroller |
| 16x2 LCD | User interface and system information |
| 4x4 Keypad | User input and system control |
| LM35 | Temperature sensing |
| LDR | Ambient light sensing |
| LEDs | Represent room lighting |
| Buzzer | Security and temperature alarms |
| Servo Motor | Door lock/unlock simulation |
| 10K Resistor | LDR voltage divider |

---

## ⚙️ System Features

### 🔐 Password Protection
The user must enter the correct password through the keypad to access the smart home control system.

### 💡 Automatic Lighting
The LDR monitors the ambient light level and allows the system to automatically control the room lights.

### 🌡️ Temperature Monitoring
The LM35 measures the room temperature through the ATmega32 ADC and displays the temperature on the LCD.

### 🚪 Door Control
A servo motor is used to simulate a door locking and unlocking mechanism.

### 🚨 Alarm System
The buzzer provides audible alerts for security events and abnormal temperature conditions.

### 🎛️ Manual Control
The user can manually control system functions through the keypad and LCD menu.

---

## 🏗️ Project Architecture

The project follows a layered embedded software architecture:

```text
Application Layer
       │
       ▼
     HAL
       │
       ▼
     MCAL
       │
       ▼
   ATmega32
