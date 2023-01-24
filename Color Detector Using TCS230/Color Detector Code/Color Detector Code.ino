#include <LiquidCrystal.h>  

const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int OutPut = 4; //OUT of TCS230 goes to Arduino Pin 4

int minRed = 23;
int maxRed = 260;
int minGreen = 22;
int maxGreen = 250;
int minBlue = 16;
int maxBlue = 190;

int frequency;

void setup()
{
  lcd.begin(16,2);

  //PINS 0, 1, 2, 3 as OUTPUT
  pinMode(0, OUTPUT); //S0
  pinMode(1, OUTPUT); //S1
  pinMode(2, OUTPUT); //S2
  pinMode(3, OUTPUT); //S3
  
  //PIN 4 as input
  pinMode(4, INPUT); //OUT

  //setting frequency selection to 20%
  digitalWrite(0,HIGH);
  digitalWrite(1,LOW);
  
}

void loop()
{
  lcd.print("R=");
  //setting for RED color sensor
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  frequency = pulseIn(OutPut, LOW);
  
  int RedVal = map(frequency, minRed, maxRed, 255, 0);
  if (RedVal <= 0)
  {
    RedVal = 0;
  }
  else if (RedVal >= 255)
  {
    RedVal = 255;
  }
  
  lcd.print(RedVal);
  lcd.print("   ");



  lcd.print("G=");

  //setting for GREEN color sensor
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  frequency = pulseIn(OutPut, LOW);

  int GreenVal = map(frequency, minGreen, maxGreen, 255, 0);
  if (GreenVal <= 0)
  {
    GreenVal = 0;
  }
  else if (GreenVal >= 255)
  {
    GreenVal = 255;
  }
  
  lcd.print(GreenVal);
  lcd.print(" ");


  lcd.setCursor(0,1);
  lcd.print("B=");

  //setting for BLUE color sensor
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  frequency = pulseIn(OutPut, LOW);
  
  int BlueVal = map(frequency, minBlue, maxBlue, 255, 0);
  if (BlueVal <= 0)
  {
    BlueVal = 0;
  }
  else if (BlueVal >= 255)
  {
    BlueVal = 255;
  }
  
  lcd.print(BlueVal);
  lcd.print("   ");

  if(RedVal <= 10 && GreenVal <= 10 && BlueVal <= 10)
  {
    lcd.print("BLACK");
  }
  else if(RedVal >= 245 && GreenVal >= 245 && BlueVal >= 245)
  {
    lcd.print("WHITE");
  }
  else if(RedVal >= 237 && RedVal <= 247 && GreenVal >= 175 && GreenVal <= 195 && BlueVal >= 175 && BlueVal <= 195)
  {
    lcd.print("RED");
  }
  else if(RedVal >= 145 && RedVal <= 165 && GreenVal >= 185 && GreenVal <= 205 && BlueVal >= 215 && BlueVal <= 235)
  {
    lcd.print("BLUE");
  }
  else if(RedVal >= 155 && RedVal <= 175 && GreenVal >= 171 && GreenVal <= 191 && BlueVal >= 135 && BlueVal <= 155)
  {
    lcd.print("GREEN");
  }
  else if(RedVal >= 245 && GreenVal >= 230 && GreenVal <= 250 && BlueVal >= 190 && BlueVal <= 210)
  {
    lcd.print("YELLOW");
  }
  else if(RedVal >= 244 && GreenVal >= 223 && GreenVal <= 243 && BlueVal >= 180 && BlueVal <= 200)
  {
    lcd.print("ORANGE");
  }
  else if(RedVal >= 190 && RedVal <= 210 && GreenVal >= 134 && GreenVal <= 154 && BlueVal >= 165 && BlueVal <= 185)
  {
    lcd.print("PURPLE");
  }
  else
  {
    lcd.print("NO COLOR");
  }

  //lcd.setCursor(0,0);
  delay(500);
  lcd.clear();
}
