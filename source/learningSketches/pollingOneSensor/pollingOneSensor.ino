const int sensorPin = 2;

void setup() {
  Serial.begin(9600);
  // INPUT_PULLUP instead of INPUT uses in-board resistor to regulate current
  pinMode(sensorPin, INPUT_PULLUP); 
}

void loop() {
  int sensorState = digitalRead(sensorPin);

  // print only when state changes / explicitly show what it reads
  if (sensorState == LOW) {
    Serial.println("Beam BROKEN (0)");
  } else {
    Serial.println("Beam CLEAR (1)");
  }
  
  delay(250); // slow down read rate
}