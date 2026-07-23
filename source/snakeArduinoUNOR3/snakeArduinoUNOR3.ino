
// define sensor pins, number of sensors
// const int sensorPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
// const int numSensors = 10;

// testing vars, delete from prod
const int sensorPins[] = {2, 3, 4};
const int numSensors = 3;

void setup() {
  // initialize serial line
  Serial.begin(9600);
  // initialize all ten sensors in one loop
  for (int i = 0; i < numSensors; i++) {
    pinMode(sensorPins[i], INPUT); // INPUT_PULLUP enables internal resistor
  }
}

void loop() {
  // poll all sensors, print if beam breaks on one
  for (int i = 0; i < numSensors; i++) {
    if (digitalRead(sensorPins[i]) == LOW) {
      int tempSensor = i + 1;

      Serial.print("Sensor ");
      Serial.print(tempSensor);
      Serial.println(" beam break.");
      delay(200);
    }
  }
}
