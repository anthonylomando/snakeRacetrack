const int sensorPins[] = {2, 3, 4};
const int numSensors = 3;

void setup() {
  Serial.begin(9600);
  // initialize all sensors
  for (int i = 0; i < numSensors; i++) {
    // INPUT_PULLUP instead of INPUT uses in-board resistor to regulate current
    pinMode(sensorPins[i], INPUT_PULLUP);
  }
}

void loop() {
  // poll the state of each pin constantly
  for (int i = 0; i < numSensors; i++) {
    int sensorState = digitalRead(sensorPins[i]);
      // print only when state changes / explicitly show what it reads
    if (sensorState == LOW) {
      Serial.println("Beam BROKEN (0)");
    } else {
      Serial.println("Beam CLEAR (1)");
    }
  }
  Serial.println();
  delay(500);
}