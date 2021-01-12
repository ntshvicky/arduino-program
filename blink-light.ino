//code to blink light
/*
 * Need to connect light bulb with 13digital port 
 * and write to blink light on every 1000 milisecond
 * Need: light bulb, 128 resistant, breadboard, arduino kit and 
 * usb connector
 */
void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(1000);
}
