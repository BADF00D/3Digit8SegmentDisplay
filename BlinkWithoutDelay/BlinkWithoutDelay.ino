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
  
  digitalWrite(pinDigit0, HIGH);
  digitalWrite(pinDigit1, HIGH);
  digitalWrite(pinDigit2, HIGH);
  
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
  digitalWrite(pinDP, LOW);
}

void loop()
{
  digitalWrite(13, LOW);
  float increment = 0.1;
  for(int x=0; x<999; x++){
    displayValue(increment*x);
  }
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
  digitalWrite(13, HIGH);
  delay(1000);
}

void displayValue(float value){
  for(int j; j<99; j++){
    writeDigitToPosition((int)(value/10), false, 2);
    delay(1);
    writeDigitToPosition((int)value, true, 1);
    delay(1);
    writeDigitToPosition((int)(value*10), false, 0);
    delay(1); 
  }
}


void writeDigitToPosition(int digit, boolean dp, int pos){
   digitalWrite(pinDigit0, HIGH);
   digitalWrite(pinDigit1, HIGH);
   digitalWrite(pinDigit2, HIGH);
   switch(pos){
      case 0: 
           digitalWrite(pinDigit0, LOW);
           break;
      case 1: 
           digitalWrite(pinDigit1, LOW);
           break;
      case 2: 
           digitalWrite(pinDigit2, LOW);
           break;
   } 
   writeDigit(digit, dp);
}

void writeDigit(int digit, boolean dp){
  digit = digit % 10;
  switch(digit){
      case 0: 
        digitalWrite(pinA, HIGH);
        digitalWrite(pinB, HIGH);
        digitalWrite(pinC, HIGH);
        digitalWrite(pinD, HIGH);
        digitalWrite(pinE, HIGH);
        digitalWrite(pinF, HIGH);
        digitalWrite(pinG, LOW);
        break;
     case 1: 
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, HIGH);
        digitalWrite(pinC, HIGH);
        digitalWrite(pinD, LOW);
        digitalWrite(pinE, LOW);
        digitalWrite(pinF, LOW);
        digitalWrite(pinG, LOW);
        break;
     case 2: 
        digitalWrite(pinA, HIGH);
        digitalWrite(pinB, HIGH);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, HIGH);
        digitalWrite(pinE, HIGH);
        digitalWrite(pinF, LOW);
        digitalWrite(pinG, HIGH);
        break;
     case 3: 
        digitalWrite(pinA, HIGH);
        digitalWrite(pinB, HIGH);
        digitalWrite(pinC, HIGH);
        digitalWrite(pinD, HIGH);
        digitalWrite(pinE, LOW);
        digitalWrite(pinF, LOW);
        digitalWrite(pinG, HIGH);
        break;
     case 4: 
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, HIGH);
        digitalWrite(pinC, HIGH);
        digitalWrite(pinD, LOW);
        digitalWrite(pinE, LOW);
        digitalWrite(pinF, HIGH);
        digitalWrite(pinG, HIGH);
        break;
     case 5: 
        digitalWrite(pinA, HIGH);
        digitalWrite(pinB, LOW);
        digitalWrite(pinC, HIGH);
        digitalWrite(pinD, HIGH);
        digitalWrite(pinE, LOW);
        digitalWrite(pinF, HIGH);
        digitalWrite(pinG, HIGH);
        break;
     case 6: 
        digitalWrite(pinA, HIGH);
        digitalWrite(pinB, LOW);
        digitalWrite(pinC, HIGH);
        digitalWrite(pinD, HIGH);
        digitalWrite(pinE, HIGH);
        digitalWrite(pinF, HIGH);
        digitalWrite(pinG, HIGH);
        break;
     case 7: 
        digitalWrite(pinA, HIGH);
        digitalWrite(pinB, HIGH);
        digitalWrite(pinC, HIGH);
        digitalWrite(pinD, LOW);
        digitalWrite(pinE, LOW);
        digitalWrite(pinF, LOW);
        digitalWrite(pinG, LOW);
        break;
     case 8: 
        digitalWrite(pinA, HIGH);
        digitalWrite(pinB, HIGH);
        digitalWrite(pinC, HIGH);
        digitalWrite(pinD, HIGH);
        digitalWrite(pinE, HIGH);
        digitalWrite(pinF, HIGH);
        digitalWrite(pinG, HIGH);
        break;
     case 9: 
        digitalWrite(pinA, HIGH);
        digitalWrite(pinB, HIGH);
        digitalWrite(pinC, HIGH);
        digitalWrite(pinD, HIGH);
        digitalWrite(pinE, LOW);
        digitalWrite(pinF, HIGH);
        digitalWrite(pinG, HIGH);
        break;
     default:
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, LOW);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, LOW);
        digitalWrite(pinE, LOW);
        digitalWrite(pinF, LOW);
        digitalWrite(pinG, HIGH);
        break;
  }
  if(dp){
      digitalWrite(pinDP, HIGH); 
  }else{
      digitalWrite(pinDP, LOW);
  }
}

