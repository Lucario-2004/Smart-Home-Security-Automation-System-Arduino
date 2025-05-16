# Smart-Home-Security-Automation-System-Arduino
This Arduino-based project combines RFID access control, PIR motion detection, DHT11 temperature monitoring, and relay-controlled appliances ⚡. It secures entry via RFID scanning, automates lights, fans, and AC based on motion &amp; temperature 📡. Ideal for home security &amp; automation 🚀. 

🔐 Smart Home Security & Automation System 🏡
This Arduino-based security and automation system integrates RFID access control, motion detection, temperature monitoring, and relay-controlled appliances. It enhances home security by restricting entry with RFID scanning, automates lights, fans, and AC based on motion & temperature, and provides real-time feedback on an LCD display.

🛠️ Components Overview
🔑 RFID Module (MFRC522) – Secure Access Control
- Reads RFID cards & tags to grant or deny entry 🚪.
- Uses predefined UID verification for authorized users.
- Controlled via SPI communication with Arduino.
🚶 PIR Sensor – Motion Detection
- Detects human presence using infrared sensing 📡.
- Activates lights & fans based on room occupancy.
- Used for security alarms & automation.
🌡️ DHT11 Sensor – Temperature & Humidity Monitoring
- Measures room temperature and humidity 📊.
- Controls AC relay based on climate conditions 🔄.
- Helps maintain energy efficiency.
⚙️ Relay Modules – Appliance Control
- 3 relays control lights (Pin 25), fan (Pin 26), AC (Pin 27).
- Automatically activates devices based on user preferences ⚡.
- Supports manual or automated switching.
📟 LCD Display (I2C) – Real-Time Status Updates
- Displays access status, temperature, humidity, and motion detection 📊.
- Helps users monitor home automation in real time.
- Uses I2C protocol (SDA: 21, SCL: 22) for simplified wiring.
🏡 Servo Motor – Automated Door Lock
- Unlocks door upon authorized RFID scan 🔓.
- Ensures secure entry & auto-closing mechanism 🚪.
- Helps prevent unauthorized access.

📌 Pin Configuration Diagram
| Component | Arduino Pin | Type | 
| RFID - SS | 5 | SPI (Chip Select) | 
| RFID - RST | 4 | SPI (Reset) | 
| Servo Door Lock | 13 | PWM Output | 
| PIR Sensor | 14 | Digital Input | 
| DHT11 Sensor | 15 | Digital Input | 
| Relay - Light | 25 | Digital Output | 
| Relay - Fan | 26 | Digital Output | 
| Relay - AC | 27 | Digital Output | 



📚 Libraries Used
- Adafruit_Sensor.h – Sensor abstraction for DHT11 monitoring.
- LiquidCrystal_I2C.h – Handles LCD display communication.
- SPI.h – Enables RFID module interaction.
- MFRC522.h – Controls RFID card scanning & authentication.
- Servo.h – Manages door locking and unlocking mechanisms.
- DHT.h – Reads temperature & humidity from the DHT11 sensor.

🔄 Step-by-Step Approach
🏗️ Step 1: Hardware Setup
🔌 Connect RFID Module – Wire SPI pins (SS: 5, RST: 4) for secure access control.
🌡️ Attach DHT11 Sensor – Monitor temperature & humidity (Pin 15).
🚶 Set Up PIR Sensor – Detect motion & adjust room lighting (Pin 14).
🔦 Integrate Relay Controls – Assign light, fan & AC operations.
🖥️ Step 2: Software Configuration
📜 Initialize RFID Module – Enable card scanning for authentication.
🛠️ Setup Relays – Define appliance control logic.
📟 Activate LCD Display – Show real-time home status.
📡 Step 3: Security & Automation
🔑 Scan RFID Card – Authenticate entry & activate servo motor.
🚶 Detect Motion – If movement detected, turn ON lights & fan.
🌡️ Temperature-Based AC Control – If temperature exceeds 25°C, activate cooling.
🚀 Step 4: Optimization & Future Enhancements
📢 Expand RFID Access Levels – Add guest, admin & restricted zones.
🔄 Introduce AI-Based Learning – Implement smart room preferences using machine learning 🤖.
🌍 IoT Connectivity – Enable remote access & voice control via Alexa or Google Assistant.

🚀 Final Thoughts
This Smart Home Security & Automation System revolutionizes home safety & convenience 🏡🔐. With RFID authentication, PIR motion tracking, temperature monitoring, and relay-controlled appliances, it ensures energy efficiency & seamless automation ⚡.
