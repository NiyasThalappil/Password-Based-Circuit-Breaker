
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int led = 7;
int relay = 6;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  digitalWrite(led,HIGH);
  pinMode(relay,OUTPUT);
  digitalWrite(relay,LOW);
  lcd.print("PASSWORD BASED");
  delay(1000);
  lcd.clear();
  lcd.print("CIRCUIT BREAKERS");
  delay(1000);
  lcd.clear();
  lcd.print("ENTER PIN NUMBER");
  delay(500);
 

}

void loop() {


 if(Serial.available())
{
  String value=Serial.readStringUntil('\n');
  Serial.println(value); 
  
  if(value=="123off")
  {
    
    lcd.clear();
    lcd.print("PASSWORD MATCH");
    delay(500);
    lcd.clear();
    lcd.print("ACCESS GRANTED");
    delay(1000);
    lcd.clear();
    digitalWrite(relay,HIGH);
    digitalWrite(led,LOW);
    lcd.print("CIRCUIT BREAKED");
   
  }
  else if(value=="123on")
  {
    
    lcd.clear();
    lcd.print("PASSWORD MATCH");
    delay(500);
    lcd.clear();
    lcd.print("ACCESS GRANTED");
    delay(1000);
    lcd.clear();
    digitalWrite(relay,LOW);
    digitalWrite(led,HIGH);
    lcd.print("SUPPLY ON");
   
  }
  else
  {
    digitalWrite(relay,LOW);
    lcd.clear();
    lcd.print("WRONG PASSWORD");
    delay(500);
    lcd.clear();
    lcd.print("TRY AGAIN");
    delay(5000);
    lcd.clear();
  }
   
 
}
}
  
