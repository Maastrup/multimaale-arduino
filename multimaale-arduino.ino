#include <LiquidCrystal.h>

const int rs = 12, e = 11, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

//the temp sensor Pin
const int tempSensor = A0;
//temp sensor configuration
const int tempBig = 734;
const int tempSmall = 37;
const int tempMaxValue = 100;
const int tempMinValue = 0;

//current sensor Pin
int readPin = tempSensor;
//"current" configuration
int big = tempBig;
int small = tempSmall;
int maxValue = tempMaxValue;
int minValue = tempMinValue;

int menuIndex = 0;
String menu[] = {"Temp", "Strain"};

volatile bool buttonPressed = false;

//setup code
void setup() {
  Serial.begin(9600);

  // set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  // Turn on the display
  lcd.display();

  //setup inputs
  pinMode(tempSensor, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), ButtonPressed, RISING)
}

void loop() {
  if(buttonPressed){
    
  }

  int mesurement = analogRead(readPin);
//  if (ting < smallest) {
//    smallest = ting;
//    Serial.println(smallest);
//  }
  long sensorValue = map(mesurement, small, big, minValue, maxValue);
  // float finalTemp = temp / 100.0f;
  Serial.println(sensorValue);

}

void ButtonPressed(){
  buttonPressed = true;
}

void UpdateScreen(int sensorValue, String currentMenu){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(currentMenu);
  lcd.setCursor(0,1);
  lcd.print(sensorValue);
}




