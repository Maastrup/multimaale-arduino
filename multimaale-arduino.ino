#include <LiquidCrystal.h>

const int rs = 12, e = 11, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

// For debouncing button
unsigned int lastTime = 0;

//the temp sensor Pin
const int tempSensor = A0;
//temp sensor configuration
const int tempBig = 734;
const int tempSmall = 37;
const int tempMaxValue = 100;
const int tempMinValue = 0;

//current sensor Pin
int readPin;
//"current" configuration
int big;
int small;
int maxValue;
int minValue;

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
  attachInterrupt(digitalPinToInterrupt(2), buttonPressed, FALLING);
}

void loop() {
  if(buttonPressed){
    buttonPressed = false;
    switch(menuIndex){
      case 0: // temperature sensor
        readPin = tempSensor; // A0
        big = tempBig; // 734
        small = tempSmall; // 34
        maxValue = tempMaxValue;
        minValue = tempMinValue;
        break;
      case 1: // strain gauge
        readPin = A1;
        /* * * * * *
          not yet known 
        * * * * * */
        big = 1023; 
        small = 0;
        maxValue = 100;
        minValue = 0;
        /* * * * * * */
    }
  }

  long mesurement = analogRead(readPin);
//  if (ting < smallest) {
//    smallest = ting;
//    Serial.println(smallest);
//  }
  long sensorValue = map(mesurement, small, big, minValue, maxValue);
  // float finalTemp = temp / 100.0f;
  Serial.println(sensorValue);

}

void ButtonPressed(){
  unsigned int currTime = millis();
  if (currTime - lastTime > 200) {
    if (0 <= menuIndex && menuIndex < 2){
      menuIndex++;
    } else if (menuIndex == 2){
      menuIndex = 0;
    } else {
      lcd.clear();
      lcd.print("Error: See");
      lcd.setCursor(0, 1);
      lcd.print("serial output.");
      Serial.println("Error: menuIndex increment failed in ButtonPressed()");
    }
    buttonPressed = true;
    lcd.print(menu[])
    lastTime = currTime;
  }
}

void UpdateScreen(int sensorValue, String currentMenu){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(currentMenu);
  lcd.setCursor(0,1);
  lcd.print(sensorValue);
}




