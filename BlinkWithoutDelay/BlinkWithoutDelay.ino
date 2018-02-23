const int pinA = 1;
const int pinB = 2;
const int pinC = 5;
const int pinD = 6;
const int pinE = 7;
const int pinF = 3;
const int pinG = 4;
const int pinDP = 0;

const int pinDigit0 = 8;
const int pinDigit1 = 9;
const int pinDigit2 = 10;

void setup() {
  // set the digital pin as output:
  pinMode(pinA, OUTPUT); 
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDP, OUTPUT);
  
  pinMode(pinDigit0, OUTPUT);
  pinMode(pinDigit1, OUTPUT);
  pinMode(pinDigit2, OUTPUT);
  
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(pinDigit0, LOW);
  digitalWrite(pinDigit1, LOW);
  digitalWrite(pinDigit2, LOW);
  
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
  digitalWrite(pinDP, HIGH);
  
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
  
}

