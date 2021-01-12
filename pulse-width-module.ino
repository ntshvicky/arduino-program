//Example Pulse Width Moulation :- Light brightness controll
/*
 * put -ve in ground pin and -9 pin as positive led
 */
void setup() {
  // put your setup code here, to run once:

}

void loop() {
 analogWrite(9, 64); //9 as pin and brightness as 64
 delay(1000);
 analogWrite(9, 127); //9 as pin and brightness as 127
 delay(1000);
 analogWrite(9, 191); //9 as pin and brightness as 191
 delay(1000);
 analogWrite(9, 255); //9 as pin and brightness as 255
 delay(1000);
 analogWrite(9, 0); //9 as pin and brightness as 0 as not view (not off)
 delay(1000);
}
