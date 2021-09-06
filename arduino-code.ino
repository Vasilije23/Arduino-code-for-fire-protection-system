#include <LiquidCrystal.h>

int blueLed = 13;
int redLed = 12;
int greenLed = 11;
int buzzer = 10;
int smoke = A5;
int sensorThres = 350;
int flameSensor = 8;
int button = 9;
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int data;

void setup()
{
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(smoke, INPUT);
  pinMode(flameSensor, INPUT);
  
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
}
void loop()
{
  while(Serial.available())
  {
    data = Serial.read();
  }
  int flameDetected = digitalRead(flameSensor);
  int smokeDetected = analogRead(smoke);
  int stateButton = digitalRead(button);
  lcd.display();
  delay(250);
  
  if ((flameDetected == 1 && smokeDetected > sensorThres) || (stateButton == 1) || (data == 3))
  {
    Serial.println("flame & smoke detected! high alert! take action immediately!");
    lcd.print("high alert!");
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, HIGH);
    digitalWrite(blueLed, LOW);
    tone(buzzer, 1000);
    delay(1500);
    lcd.clear();
  }
  else if ((flameDetected == 1) || (data == 2))
  {
    Serial.println("flame detected! be careful!");
    lcd.print("flame detected!");
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(blueLed, LOW);
    tone(buzzer, 1000);
    delay(1200);
    lcd.clear();
  }
  else if ((smokeDetected > sensorThres) || (data == 1))
  {
    Serial.println("smoke detected! be careful!");
    lcd.print("smoke detected!");
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(blueLed, LOW);
    tone(buzzer, 1000);
    delay(1200);
    lcd.clear();
  }
  else
  {
    Serial.println("no flame or smoke.. stay cool");
    lcd.print("stay cool..");
    digitalWrite(blueLed, HIGH);
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, LOW);
    noTone(buzzer);
    delay(1000);
    lcd.clear();
  }
  lcd.noDisplay();
  delay(1000);
}
