// define sensor pins, number of sensors
const int sensorPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
const int numSensors = 10;

void setup() {
  Serial.begin(9600);
  // initialize all sensors
  for (int i = 0; i < numSensors; i++) {
    // INPUT_PULLUP instead of INPUT uses in-board resistor to regulate current
    pinMode(sensorPins[i], INPUT_PULLUP);
  }
}

void loop() {
  // zero the output array
  unsigned long sensorOutputs[numSensors];
  for (int i = 0; i < numSensors; i++) {
    sensorOutputs[i] = 0;
  }

  // initialize time var
  unsigned long initialTime = 0;
  // poll the state of pin two constantly to initialize timestamp variable
  bool startPinState = false;
  // poll the pin constantly until it's triggered, then advance
  while (startPinState == false) {
    int startPinSensorState = digitalRead(sensorPins[0]);
    if (startPinSensorState == LOW) {
      // set time variable
      initialTime = millis();
      // set the break state to true to break out of the loop
      startPinState = true;
    }
  }

  // poll the state of each pin constantly while sensorsTriggered is less than the number of sensors
  int sensorsTriggered = 1;
  while (sensorsTriggered < numSensors) {
    for (int i = 1; i < numSensors; i++) {
      int sensorState = digitalRead(sensorPins[i]);
      // record only when state changes
      if (sensorState == LOW) {
        if (sensorOutputs[i] == 0) {
          sensorOutputs[i] = millis();
          sensorsTriggered++;
      }
    }
  }

  // print sensors
  for (int i = 0; i < numSensors; i++) {
    Serial.print(sensorPins[i]);
    if (i < numSensors - 1) {
      Serial.print(",");
    }
  }
  Serial.println("");
  // then, print sensorOutput timestamps
  for (int i = 0; i < numSensors; i++) {
    Serial.print(sensorOutputs[i] - initialTime);
    if (i < numSensors - 1) {
      Serial.print(",");
    }
  }
  Serial.println("");
  delay(2000);
}