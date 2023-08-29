/* 
This is the code that will be uploaded on the esp32 board on the transmitter controller
*/
#include "LiquidCrystal_I2C.h"
#include "esp_now.h"
#include "WiFi.h"
  

/*MAC Address of the receiver controller
  edit the address as required

*/
uint8_t broadastAddress[] = {0xFF, 0xFF,0xFF, 0xFF, 0xFF, 0xFF};
 
LiquidCrystal_I2C lcd(0x3F , 16, 2);
// variables
const int rightButtonPin = 2;  // the number of the right pushbutton pin
const int leftButtonPin = 2;  // the number of the left pushbutton pin

// variables will change:
int rightButtonState = 0;  // variable for reading the pushbutton status
int leftButtonState = 0;  // variable for reading the pushbutton status

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2 , 1);
  lcd.print('Hello rider');

  pinMode(rightButtonPin, INPUT);
  pinMode(leftButtonPin, INPUT);

}

  void operationMode(){
 // read the state of the pushbutton value:
  rightButtonState = digitalRead(rightButtonPin);
  leftButtonState = digitalRead(leftButtonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (rightButtonState == HIGH) 
  {
    // initiate right turn
    rightTurn();
  } 
  else {
    // turn off:
    
  }
  if (leftButtonState == HIGH)
  {
    // initiate left turn
    leftTurn();
  } 
  else {
    // turn off:
    
  }

  }


void rightTurn(){
  /*code to send signal through esp now to blink the leds
  void SendToReceiver(){

  }*/

  lcd.setCursor(0 , 0);
  lcd.print('Right turn');
  delay(1000);
  lcd.clear();
  delay(1000);
  lcd.print('Right turn');
  lcd.clear();
  delay(1000);
  lcd.print('Right turn');
  lcd.clear();
  delay(1000);
  lcd.print('Right turn');
  lcd.clear();
  delay(1000);
  lcd.print('Right turn');
  lcd.clear();
  delay(1000);
  lcd.print('Right turn');


}
void leftTurn(){
  /*code to send signal through esp now to blink the leds
  void SendToReceiver(){

  }*/

  lcd.setCursor(0 , 0);
  lcd.print('Left turn');
  delay(1000);
  lcd.clear();
  delay(1000);
  lcd.print('left turn');
  lcd.clear();
  delay(1000);
  lcd.print('left turn');
  lcd.clear();
  delay(1000);
  lcd.print('left turn');
  lcd.clear();
  delay(1000);
  lcd.print('left turn');
  lcd.clear();
  delay(1000);
  lcd.print('left turn');

}


void loop() {
  // put your main code here, to run repeatedly:

}
