#include <LiquidCrystal.h>

const int TempPin = 0;

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;

const int UpButton = 12;
const int DownButton = 11;

const int Relay = 10;

float SetPoint = 0.00;

const unsigned long eventInterval = 3000;
unsigned long previousTime = 0;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  pinMode(UpButton, INPUT);
  pinMode(DownButton, INPUT);

  digitalWrite(UpButton,HIGH);
  digitalWrite(DownButton,HIGH);

  pinMode(Relay, OUTPUT);

  digitalWrite(Relay, HIGH);
}

void loop() 
{
  int val = analogRead(TempPin);
  float Vout = val * (5/1024.0);

  float TempC = Vout * 100;

  unsigned long currentTime = millis(); 

  if (digitalRead(UpButton) == LOW)
  {
    SetPoint = SetPoint + 1.00;
  }

  if (digitalRead(DownButton) == LOW)
  {
    SetPoint = SetPoint - 1.00;
  }

  lcd.print("Temp: ");
  lcd.print(TempC);
  lcd.print("*C");

  lcd.setCursor(0, 1);
  
  lcd.print("Set: ");
  lcd.print(SetPoint);
  lcd.print("*C");

  if ((currentTime - previousTime >= eventInterval)) {
    
    if (SetPoint < TempC && digitalRead(Relay) == LOW)
    {
      digitalWrite(Relay, HIGH);
      delay(300);
    }
    
    else if (SetPoint >= TempC && digitalRead(Relay) == HIGH)
    {
      digitalWrite(Relay, LOW);
      delay(300);
    }
    previousTime = currentTime;
  }

  delay(250);
  lcd.clear();
  lcd.setCursor(0, 0);
  
}


