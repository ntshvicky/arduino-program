//Check room temprature using LM 35 Sensor
/*
 * Need Arduino UNO, LM35 Sensor, jumper wire
 * need to work on Analog port A0
 */
 float temp = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  //Read from analog port A0 sensor data
  temp = analogRead(A0);
  Serial.print("Current room temprature:- ADC Count:");
  Serial.print(temp);
  Serial.print(" & Degree/Centigrade: ");
  Serial.println(temp * 0.48828125);
  delay(1000);
}
