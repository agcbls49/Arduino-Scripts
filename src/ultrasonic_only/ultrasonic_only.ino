long duration;
int distance;

const int trigPin = 10;
const int echoPin = 11;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // Serial.begin(115200);
  Serial.begin(500000);

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // duration = pulseIn(echoPin, HIGH);
  // distance = duration * 0.034 / 2;

  // Serial.print("Distance: ");
  // Serial.println(distance);

  // duration = pulseIn(echoPin, HIGH, 50000);

  duration = pulseIn(echoPin, HIGH);

Serial.println(duration);

delay(500);

  Serial.print("Duration: ");
  Serial.println(duration);

  delay(500);
}
