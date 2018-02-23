//expect the following segment to pin mapping
//const int pinA = 1;
//const int pinB = 2;
//const int pinC = 5;
//const int pinD = 6;
//const int pinE = 7;
//const int pinF = 3;
//const int pinG = 4;
const int pinDP = 0;

const int pinDigit0 = 9;
const int pinDigit1 = 10;
const int pinDigit2 = 11;

byte digits[] = {
  0b11101110,
  0b00100100,
  0b11010110,
  0b01110110,
  0b00111100,
  0b01111010,
  0b11111010,
  0b11111010,
  0b11111110,
  0b01111110,
  0b00010000   
};

void setup() {
  DDRD = 0xFF; //Set D0 up to D7 as Output
  
  pinMode(pinDigit0, OUTPUT);
  pinMode(pinDigit1, OUTPUT);
  pinMode(pinDigit2, OUTPUT);
  
  pinMode(13, OUTPUT);
  
  digitalWrite(pinDigit0, HIGH);
  digitalWrite(pinDigit1, HIGH);
  digitalWrite(pinDigit2, HIGH);
  
  PORTD = 0;
}

void loop()
{
  digitalWrite(13, LOW);
  float increment = 0.1;
  for(int x=0; x<1000; x++){
    displayValue(increment*x);
  }
}

void displayValue(float value){
  writeDigitToPosition((int)(value/10), false, 2);
  writeDigitToPosition((int)value, true, 1);
  writeDigitToPosition((int)(value*10), false, 0);
}

void writeDigitToPosition(int value, boolean dp, int pos){
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
   writeDigit(value, dp);
   delay(10);
}

void writeDigit(int value, boolean dp){
  PORTD = digits[value%10];
  if(dp){
      digitalWrite(pinDP, HIGH); 
  }else{
      digitalWrite(pinDP, LOW);
  }
}

