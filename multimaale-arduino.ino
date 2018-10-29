#include <LiquidCrystal.h>

const int rs = 12, e = 11, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
const int buttonPin = 2;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

int biggest = 734;
int smallest = 37;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int mesurement = analogRead(A0);
//  if (ting < smallest) {
//    smallest = ting;
//    Serial.println(smallest);
//  }
  long temp = map(mesurement, smallest, biggest, 0, 100);
  // float finalTemp = temp / 100.0f;
  Serial.println(temp);
}




