//code to blink light and on off manage on button input
/*
 * Need to connect light bulb with 13digital port 
 * and write to light on button click
 * Need: light bulb,  128 resistant, breadboard, arduino kit and 
 * usb connector
 */
 int led = 13;
 int swc = 8;
 int flag = 1;
 int svalue = 0;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(swc, INPUT);
}

void loop() {
  //digitalRead used to get input
  //readVal reaturn HIGH or LOW value based on switch click
  int readVal = digitalRead(swc);

  if(readVal == HIGH)
  {
    if(flag == 1)
    {
      //digitalWrite used to show output
      digitalWrite(led, HIGH);
      delay(100);
      digitalWrite(led, LOW);
      delay(100);
      digitalWrite(led, HIGH);
      delay(100);
      digitalWrite(led, LOW);
      delay(100);
      flag = 0;
    }
    else
    {
       digitalWrite(led, LOW);
       delay(1000);
       flag = 1;
    }
  }
  
}
