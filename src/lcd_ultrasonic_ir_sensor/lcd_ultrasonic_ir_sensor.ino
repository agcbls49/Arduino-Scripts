#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

const int trigPin = 10;
const int echoPin = 11;
const int irPin = 7;

long duration;
float distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(irPin, INPUT);

  Serial.begin(115200);

  lcd.init();
  lcd.backlight();
}

void loop() {

  if (digitalRead(irPin) == LOW) {

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH, 30000);

    if (duration > 0) {
      distance = duration * 0.0343 / 2.0;

      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println(" cm");

      lcd.setCursor(0, 0);
      lcd.print("Distance:       ");

      lcd.setCursor(0, 1);
      lcd.print("                "); // Clear line
      lcd.setCursor(0, 1);
      lcd.print(distance, 1); // 1 decimal place
      lcd.print(" cm");
    }

  } else {

    Serial.println("No object");

    lcd.setCursor(0, 0);
    lcd.print("No object       ");

    lcd.setCursor(0, 1);
    lcd.print("                ");
  }

  delay(50);
}