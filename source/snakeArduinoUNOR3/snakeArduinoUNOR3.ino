
// define sensor pins, number of sensors
const int sensorPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
const int numSensors = 10;

void setup() {
  // initialize all ten sensors in one loop
  for (i = 0; i < numSensors; i++) {
    pinMode(sensorPins[i], INPUT);
  }
}

void loop() {
  // poll all sensors
  for (i = 0; i < numSensors; i++) {
    if (digitalRead(sensorPins[i]) == LOW) {
      
    }
  }
}
