//Read human presence in PIR motion senser
/*
 * For this we need 
 * 1.Arduino Uno
 * 2.PIR sensor (VCC-5V,GND-GND,OUTPUT-2(DigitalPin)
 * 3.LED (Led blink on motion) 13&GND
 */
 int led = 13;
 int pin = 2;//OUTPUT for PIR senseor
 int value = 0; //Read initial data comes from sensor
 int pirState = LOW; //status of PIR sensor Reading HIGH or LOW
void setup() {
  pinMode(led, OUTPUT);
  pinMode(pin, INPUT);
  Serial.begin(9600);

}

void loop() {
  value = digitalRead(pin);//reading data from sensor
  //if Human body comes in sensor range
  if(value==HIGH){
    digitalWrite(led, HIGH);//led blink on human motion
    
    if(pirState == LOW){
      Serial.println("Motion Detecting!");
      pirState = HIGH;
    }
  }
  else{
    digitalWrite(led, LOW);
    if(pirState == HIGH){
      Serial.println("Motion Ended!");
      pirState = LOW;
    }
  }

}
