#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_AUTH_TOKEN "V5Qyeqn5z6fGa8zPMMsQCe9u2oAAGlSn"

const int ENA = D7;
const int IN1 = D1;
const int IN2 = D2;

const int ENB = D8;
const int IN3 = D3;
const int IN4 = D4;

bool forward;
bool backward;
bool left;
bool right;

bool frontRight;
bool frontLeft;
bool backRight;
bool backLeft;

int speed;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "F41";
char pass[] = "witg4898";


BLYNK_WRITE(V0) {
  forward = param.asInt();
}

BLYNK_WRITE(V1) {
  backward = param.asInt();
}

BLYNK_WRITE(V2) {
  left = param.asInt();
}

BLYNK_WRITE(V3) {
  right = param.asInt();
}

BLYNK_WRITE(V4) {
  frontRight = param.asInt();
}

BLYNK_WRITE(V5) {
  frontLeft = param.asInt();
}

BLYNK_WRITE(V6) {
  backRight = param.asInt();
}

BLYNK_WRITE(V7) {
  backLeft = param.asInt();
}

BLYNK_WRITE(V8) {
  speed = param.asInt();
}


void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT); 
 
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT); 
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {

  Blynk.run();

  analogWrite(ENA, speed);
  analogWrite(ENB, speed );

  if (forward){
    //Forward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);    
  }

  else if (backward) {
    //Backward
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }

  else if (left) {
    //Left
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }

  else if (right) {
    //Right
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }

  else if (frontRight) {
    //Front Right
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }

  else if (frontLeft) {
    //Front Left
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }

  else if (backRight) {
    //Backward Right
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }

  else if (backLeft) {
    //Backward Left
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }

  else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
}
