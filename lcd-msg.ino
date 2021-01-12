//Connect LCD
/*
 * GND to power port GND
 * VCC to power port 5V
 * SDA to analog port A4
 * SCL to analog port A5
 * New LiquidCrystal library
 * for multiple lcd we can use Breadboard and jumper wires
 */
 #include <Wire.h>
 #include <LiquidCrystal_I2C.h>

 LiquidCrystal_I2C lcd(0x27,20,4);
 int count = 0;
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(4,0);
 lcd.print("Starting");
 for(count=0; count<=10; count++){
  lcd.setCursor(8,1);
  lcd.print(count);
  delay(1000);
 }
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("Nitish");
  lcd.setCursor(3,1);
  lcd.print("Srivastava");
  delay(1000);
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("Kya???");
  delay(1000);
 lcd.clear();
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("I LOVE YOU");
  for(int i=0;i<6;i++)
  {
    lcd.scrollDisplayRight();
    delay(250);
  }
  for(int i=6;i>0;i--)
  {
    lcd.scrollDisplayLeft();
    delay(250);
  }
}
