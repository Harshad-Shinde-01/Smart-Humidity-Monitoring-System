# Smart Humidity & Temperature Monitoring System

A **remotely operated humidity and temperature tracking system** powered by **cloud technology** using NodeMCU ESP8266, DHT11 sensor, and Blynk app. This project allows **real-time environmental monitoring**, alerting, and remote control.

---

##  Components Used

| Component                 | Description                          |
|---------------------------|--------------------------------------|
| NodeMCU ESP8266 (30-pin)  | Wi-Fi-enabled microcontroller        |
| DHT11 Sensor              | Measures temperature and humidity    |
| I2C LCD 16x2 Display      | Displays real-time sensor data       |
| Buzzer                    | Alerts on threshold breach           |
| L298N / L293D Driver      | Controls motor (fan/humidifier)      |
| 3V DC Motor / Actuator    | Airflow/humidity control             |
| Power Supply (MB102/12V)  | Powers the system                    |

---

##  Modes of Operation

###  **Automatic Mode**
- System automatically controls motor and buzzer based on sensor data.
- System controls the Humidifier based on the humidity.
### 🎛️ **Manual Mode**
- User controls fan speed and humidifier via Blynk app sliders and buttons.

---

## 🧠 Features

- 🌡️ Real-time temperature & humidity monitoring
- 📲 Cloud integration with Blynk for remote access
- 🚨 Alerts via buzzer and LED
- 💡 LCD display for local status
- 🔄 Auto/Manual mode toggle for flexibility

---

## 📂 Folder Structure

Smart-Humidity-Monitor/
├── SmartHumidity.ino
├── README.md
├── circuit_diagram.png
├── Blynk_config.txt
└── libraries/
├── DHT.h
└── LiquidCrystal_I2C.h






----------------------

## 🚀 Getting Started

1. **Install Libraries:**
   - `DHT sensor library`
         Arduino IDE: Sketch → Include Library → Manage Libraries → Search "DHT"
   - `LiquidCrystal_I2C`
         Arduino IDE: Manage Libraries → Search "LiquidCrystal I2C"
   - `Blynk`
        Arduino IDE: Manage Libraries → Search "Blynk"

2. **Configure Blynk:**
   - Add your `AUTH_TOKEN`, Wi-Fi SSID, and password in the code.
   - Set up the app with:
     - Buttons: Mode toggle
     - Sliders: Fan speed / Manual control

3. **Upload Code:**
   - Use Arduino IDE
   - Select board: `NodeMCU 1.0 (ESP-12E Module)`
   - Upload the `.ino` file

---



## 🤝 Contributing

Pull requests are welcome! Feel free to fork the repo and submit your improvements.

---

## ✍️ Author

**Shinde Harshad , Shinde Tushar , Shinde Vrunda , Sonawane Hardik , Sonawane Kartik**  
`Students | Developers | Embedded Systems Enthusiast's`

---

