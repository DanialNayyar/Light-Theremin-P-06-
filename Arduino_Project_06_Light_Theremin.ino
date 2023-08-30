int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;


const int ledPin =13; // indicator that sensor has finished calibrating


void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
 
  while (millis() < 5000){ // while loop runs untill condition is met. millis() reports how long the arduino has been running since it was last powered on or reset.
 
  sensorValue = analogRead (A0);
  if (sensorValue > sensorHigh) {
    sensorHigh = sensorValue;
  }
  if (sensorValue < sensorLow) {
    sensorLow = sensorValue;
  }
 }
 digitalWrite(ledPin,LOW);


}




void loop() {
  sensorValue = analogRead(A0);
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000); // value of pitch is to be mapped from sensor value. sensorLow and sensorHigh are the bounds for the incomming values (starting values are 50 and 4000)
  tone(8,pitch,20); // plays sound, the 8 = pin the sound it will play on. the frequency is determined by the pitch variable. the 20 is how long to play the note
  delay(100);
}
