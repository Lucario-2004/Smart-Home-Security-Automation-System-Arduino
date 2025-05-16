#include <Adafruit_Sensor.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>
#include <DHT.h>

// RFID Module
#define SS_PIN 5  
#define RST_PIN 4  

// Servo Motor (Door)
#define SERVO_PIN 13  

// PIR Sensor
#define PIR_PIN 14  

// DHT11 Sensor
#define DHT_PIN 15  
#define DHT_TYPE DHT11  

// Relays for appliances
#define RELAY_LIGHT 25  
#define RELAY_FAN 26  
#define RELAY_AC 27  

// Initialize components
Servo doorServo;
LiquidCrystal_I2C lcd(0x27, 16, 2);
MFRC522 rfid(SS_PIN, RST_PIN);
DHT dht(DHT_PIN, DHT_TYPE);

// Authorized RFID UID (Replace with actual UID)
byte authorizedUID[4] = {0x12, 0x34, 0x56, 0x78};  

void setup() {
    Wire.begin(21, 22);  // Initialize I2C for LCD
    SPI.begin();         // Start SPI for RFID
    rfid.PCD_Init();     // Initialize RFID module
    lcd.init();
    lcd.backlight();
    doorServo.attach(SERVO_PIN);
    doorServo.write(0); // Ensure door starts closed
    dht.begin();

    // Set up pins
    pinMode(PIR_PIN, INPUT);
    pinMode(RELAY_LIGHT, OUTPUT);
    pinMode(RELAY_FAN, OUTPUT);
    pinMode(RELAY_AC, OUTPUT);

    lcd.setCursor(0, 0);
    lcd.print("Scan Here...");
}

void loop() {
    // RFID-based smart lock functionality
    if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Scanning...");

        bool authorized = true;
        for (byte i = 0; i < 4; i++) {
            if (rfid.uid.uidByte[i] != authorizedUID[i]) {
                authorized = false;
                break;
            }
        }

        if (authorized) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Access Granted!");
            doorServo.write(180); // Open door
            delay(5000); // Wait for 5 seconds
            doorServo.write(0); // Close door
        } else {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Access Denied!");
        }

        delay(2000); // Delay before resuming display
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Scan Here...");
        
        rfid.PICC_HaltA();
        rfid.PCD_StopCrypto1();
    }

    // Home automation functionality
    bool motionDetected = digitalRead(PIR_PIN);
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    // Control light & fan based on motion
    if (motionDetected) {
        digitalWrite(RELAY_LIGHT, HIGH);
        digitalWrite(RELAY_FAN, HIGH);
    } else {
        digitalWrite(RELAY_LIGHT, LOW);
        digitalWrite(RELAY_FAN, LOW);
    }

    // Control AC based on temperature
    if (temperature > 25.0) {
        digitalWrite(RELAY_AC, HIGH); // Turn ON AC
    } else {
        digitalWrite(RELAY_AC, LOW); // Turn OFF AC
    }

    // Display updated home automation data on LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print(temperature);
    lcd.print("C H:");
    lcd.print(humidity);
    lcd.print("%");

    lcd.setCursor(0, 1);
    lcd.print("Obj: ");
    lcd.print(motionDetected ? "YES" : "NO");

    delay(2000);
}