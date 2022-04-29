
#include <Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(1,2,3,4,5,6);
int ledPin = 13;               
int pirPin = 8;                 
int pirStat = 0;
int pirStat2 = 0;
int distance;
int duration;
Servo servo1;
Servo servo2;
int pos=0;
#define echo 11
#define trig 12
#define tap 7
#define san A0

void setup() 
{
 lcd.begin(16,2);
 
 pinMode(ledPin, OUTPUT);     
 pinMode(pirPin, INPUT);     
 pinMode(trig, OUTPUT);
 pinMode(echo, INPUT);
 pinMode(tap, OUTPUT);
 pinMode(san, OUTPUT);
 //Serial.begin(9600);
 servo1.attach(9); 
 servo2.attach(10); 

}

void loop()
{
 lcd.clear();
 lcd.setCursor(3, 0);
 lcd.print("WELCOME TO");
 lcd.setCursor(2, 1);
 lcd.print("SMART TOILET");
 pirStat = digitalRead(pirPin); 
 if (pirStat == HIGH) 
 {  
  
  lcd.clear();
  //Serial.print("HEY IM HERE \n");          
  digitalWrite(ledPin, HIGH); 
  lcd.setCursor(6,0);
  lcd.print("DOOR");
  lcd.setCursor(4,1);
  lcd.print("OPENNING");
     
        for (pos = 10; pos <= 100; pos += 1) 
        {
          servo1.write(pos);
          servo2.write(pos);               
          delay(80);
        }
        lcd.clear();
        delay(2000);
        lcd.setCursor(6,0);
        lcd.print("DOOR");
        lcd.setCursor(5,1);
        lcd.print("CLOSING");
        
        for (pos = 100; pos >= 10; pos -= 1) 
        {
          servo1.write(pos); 
          delay(40);                      
        }
        lcd.clear();
        long cm = 21;
        long t =0;
        do
        {
          
          delay(1000);
          digitalWrite(trig,HIGH);
          delay(10);
          digitalWrite(trig,LOW);
           t=pulseIn(echo,HIGH);
          cm=t*0/2;
          delay(100);
          if(cm<20)
                {
                   lcd.clear();
                   lcd.setCursor(4,0);
                   lcd.print("FLUSHING");       
                  //Serial.print(cm);
                  //Serial.print("cm \n");
                  digitalWrite(tap,HIGH);
                  delay(3000);
                  digitalWrite(tap,LOW);
                  lcd.clear();
                  lcd.setCursor(6,0);
                  lcd.print("DONE");
                  for (pos = 100; pos >= 0; pos -= 1) 
                  {
                    servo2.write(pos); 
                    delay(80);                     
                  }
                  delay(100);        
                  lcd.clear(); 
                  
                }
                else
                {
                  digitalWrite(tap,LOW);
                }
                delay(100);        
          lcd.clear(); 
          
          lcd.setCursor(4,0);
          lcd.print("WHEN YOU");
           lcd.setCursor(4,1);
          lcd.print("FINISHED");           
          delay(2000); 
          digitalWrite(trig,LOW);
          delayMicroseconds(2);
          digitalWrite(trig,HIGH);
          delay(10);
          digitalWrite(trig,LOW);
           t=pulseIn(echo,HIGH);
          cm=t*0/2;
          delay(10);
          if(cm<20)
                {
                   lcd.clear();
                   lcd.setCursor(4,0);
                   lcd.print("FLUSHING");       
                  //Serial.print(cm);
                  //Serial.print("cm \n");
                  digitalWrite(tap,HIGH);
                  delay(5000);
                  digitalWrite(tap,LOW);
                  lcd.clear();
                  lcd.setCursor(6,0);
                  lcd.print("DONE");
                  for (pos = 100; pos >= 0; pos -= 1) 
                  {
                    servo2.write(pos); 
                    delay(80);                     
                  }
                  delay(100);        
                  lcd.clear(); 
                  
                }
                else
                {
                  digitalWrite(tap,LOW);
                } 
                delay(100);        
          lcd.clear();
                 
          lcd.clear();
          lcd.setCursor(1,0);
          lcd.print("HOLD YOUR HAND");
          lcd.setCursor(3,1);
          lcd.print("ON SENSOR");
          delay(2000);
           digitalWrite(trig,LOW);
          delayMicroseconds(2);
          digitalWrite(trig,HIGH);
          delay(10);
          digitalWrite(trig,LOW);
           t=pulseIn(echo,HIGH);
          cm=t*0/2;
          delay(10);
          if(cm<20)
                {
                   lcd.clear();
                   lcd.setCursor(4,0);
                   lcd.print("FLUSHING");       
                  //Serial.print(cm);
                  //Serial.print("cm \n");
                  digitalWrite(tap,HIGH);
                  delay(5000);
                  digitalWrite(tap,LOW);
                  lcd.clear();
                  lcd.setCursor(6,0);
                  lcd.print("DONE");
                  for (pos = 100; pos >= 0; pos -= 1) 
                  {
                    servo2.write(pos); 
                    delay(80);                     
                  }
                  delay(100);        
                  lcd.clear(); 
                  
                }
                else
                {
                  digitalWrite(tap,LOW);
                } 
                delay(100);        
          lcd.clear();
     
          lcd.clear();
          lcd.setCursor(6,0);
          lcd.print("FOR");
          lcd.setCursor(3,1);
          lcd.print("2 SECONDS");
          delay(2000);
           digitalWrite(trig,LOW);
          delayMicroseconds(2);
          digitalWrite(trig,HIGH);
          delay(10);
          digitalWrite(trig,LOW);
           t=pulseIn(echo,HIGH);
          cm=t*0/2;
          delay(10);
          if(cm<20)
                {
                   lcd.clear();
                   lcd.setCursor(4,0);
                   lcd.print("FLUSHING");       
                  //Serial.print(cm);
                  //Serial.print("cm \n");
                  digitalWrite(tap,HIGH);
                  delay(5000);
                  digitalWrite(tap,LOW);
                  lcd.clear();
                  lcd.setCursor(6,0);
                  lcd.print("DONE");
                  for (pos = 100; pos >= 0; pos -= 1) 
                  {
                    servo2.write(pos); 
                    delay(80);                     
                  }
                  delay(100);        
                  lcd.clear(); 
                  
                }
                else
                {
                  digitalWrite(tap,LOW);
                } 
                delay(100);        
          lcd.clear();
        }
        while(cm>20);

        delay(1000);
        lcd.setCursor(6,0);
        lcd.print("DOOR");
        lcd.setCursor(4,1);
        lcd.print("OPENNING");
        
        for (pos = 10; pos <= 100; pos += 1) 
        {
          servo1.write(pos);               
          delay(80);
        }
        lcd.clear();
        delay(2000);
        lcd.setCursor(6,0);
        lcd.print("DOOR");
        lcd.setCursor(5,1);
        lcd.print("CLOSING");
        for (pos = 100; pos >= 10; pos -= 1) 
        {
          servo1.write(pos); 
          delay(80);                      
        }
        digitalWrite(san,HIGH);
        lcd.clear();
        lcd.setCursor(3,0);
        lcd.print("SANITIZER");
        lcd.setCursor(3,1);
        lcd.print("PROCESSING");
        delay(5000);
        lcd.clear();
        lcd.setCursor(6,0);
        lcd.print("DONE");
        delay(2000);
        lcd.clear();
        digitalWrite(san,LOW);
        
  }
  else 
  {
     digitalWrite(ledPin, LOW);     
  }
delay(100);
} void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
