#define IR_PIN 7

void setup() {
  pinMode(IR_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(IR_PIN) == LOW) {
    Serial.println("Object detected");
  } else {
    Serial.println("No object");
  }

  delay(500);
}