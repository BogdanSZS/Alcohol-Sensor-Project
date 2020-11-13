#include<LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int sensorPin=A0;
int led1Pin=2;
int led2Pin=3;
int led3Pin=4;
int led4Pin=5;

  

void setup()
{

  Serial.begin(5000);
  lcd.begin();
  lcd.backlight();
  pinMode(led1Pin,OUTPUT);
  pinMode(led2Pin,OUTPUT);
  pinMode(led3Pin,OUTPUT);
  pinMode(led4Pin,OUTPUT);
  

}
int readAlcohol()
{ ///pt aproximare(3 valori la 10 0 ms)
  int val = 0;
  int val1, val2, val3;
  val1 = analogRead(sensorPin);
  delay(100);
  val2 = analogRead(sensorPin);
  delay(100);
  val3 = analogRead(sensorPin);
  val = (val1 + val2 + val3) / 3;
  return val;
}


void loop()
{

  int sensorValue;
  sensorValue = readAlcohol();
  int o=1;
    
    if(sensorValue<=100)
    {
      if(o==1)
      {
        lcd.clear();
        o=0;
       }
       
    lcd.setCursor(3,0);
     lcd.print("INSERT PROBE");
    
     lcd.setCursor(6,1);
     digitalWrite(led1Pin,LOW);
     digitalWrite(led2Pin,LOW);
     digitalWrite(led3Pin,LOW);
     digitalWrite(led4Pin,LOW);
     
      Serial.print("INSERT   PROBE");
      Serial.print("sensorValue=");
      Serial.print(sensorValue);
     delay(1000);
    }
    if(sensorValue<200 and sensorValue>100)
    {
      if(o==1)
      {
        lcd.clear();
        o=0;
       }
      lcd.setCursor(3,0);
      lcd.print(" SOBER");
      lcd.setCursor(6,1);
      lcd.print(sensorValue);
      digitalWrite(led1Pin,HIGH);
     digitalWrite(led2Pin,LOW);
     digitalWrite(led3Pin,LOW);
     digitalWrite(led4Pin,LOW);
     delay(1000);
      
    }
    if(sensorValue<=300 &&  sensorValue>200)
    {
      if(o==1)
      {
      lcd.clear();
      o=0;
     }
      lcd.setCursor(0,0);
      lcd.print("MEDIUM EBRIETY");
      lcd.setCursor(6,1);
      lcd.print(sensorValue);
      Serial.print("MEDIUM EBRIETY");
      Serial.print(sensorValue);
      
      digitalWrite(led1Pin,HIGH);
       delay(1000);
      digitalWrite(led2Pin,HIGH);
      digitalWrite(led3Pin,LOW);
      digitalWrite(led4Pin,LOW);  
        
    }
      if(sensorValue<=400 &&  sensorValue>300)
    {
      if(o==1)
      {
      lcd.clear();
      
      o=0;
     }
      lcd.setCursor(2,0);
      lcd.print(" HIGH EBRIETY");
      lcd.setCursor(6,1);
      lcd.print(sensorValue);
      Serial.print("HIGH EBRIETY");
      Serial.print(sensorValue);
      
      digitalWrite(led1Pin,HIGH);
       delay(1000);
      digitalWrite(led2Pin,HIGH);
      digitalWrite(led3Pin,HIGH);
      digitalWrite(led4Pin,LOW);  
        
    }
      if(sensorValue>400)
    {
      if(o==1)
      {
      lcd.clear();
      
      o=0;
     }
      lcd.setCursor(2,0);
      lcd.print("EXTREME EBRIETY");
      lcd.setCursor(6,1);
      lcd.print(sensorValue);
      Serial.println("EXTREME EBRIETY");
      Serial.println(sensorValue);
      
      digitalWrite(led1Pin,HIGH);
       delay(1000);
      digitalWrite(led2Pin,HIGH);
      digitalWrite(led3Pin,HIGH);
      digitalWrite(led4Pin,HIGH);  
        
    }
 
    lcd.clear();
}
