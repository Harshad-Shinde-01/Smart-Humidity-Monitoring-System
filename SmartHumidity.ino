// SmartHumidity.ino
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define DHTPIN D4
#define DHTTYPE DHT11
#define BUZZER D5
#define IN1 D0
#define IN2 D3
#define ENA D6

char auth[] = "YourAuthToken";
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

WidgetTerminal terminal(V1);

bool manualMode = false;
int fanSpeed = 255;

BLYNK_WRITE(V0) {
  manualMode = param.asInt();
}

BLYNK_WRITE(V2) {
  fanSpeed = param.asInt();
  analogWrite(ENA, fanSpeed);
}

void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  lcd.begin();
  lcd.backlight();
}

void loop() {
  Blynk.run();

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  lcd.setCursor(0, 0);
  lcd.print("Temp: " + String(t) + "C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: " + String(h) + "%");

  if (!manualMode) {
    if (h < 40) {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, 255);
      digitalWrite(BUZZER, HIGH);
    } else if (h > 70) {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(BUZZER, HIGH);
    } else {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(BUZZER, LOW);
    }
  }
}