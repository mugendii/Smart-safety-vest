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
const int rightButtonPin = 26;  // the number of the right pushbutton pin
const int leftButtonPin = 27;  // the number of the left pushbutton pin

// variables will change:
bool rightButtonState = false;  // variable for reading the pushbutton status
bool leftButtonState = false;  // variable for reading the pushbutton status

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2 , 1);
  lcd.print('Hello rider');

  pinMode(rightButtonPin, INPUT_PULLUP);
  pinMode(leftButtonPin, INPUT_PULLUP);

  //initialize ESP_NOW

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_peer_info_t peerInfo;
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Error adding peer");
    return;
  }

}

  void operationMode(){
 

  }


void rightTurn(){
  /*code to send signal through esp now to blink the leds
  void SendToReceiver(){

  }*/
  //create message
  uint8_t messageright[1];
  messageright[0] = rightButtonState;

    // Send the message
  esp_err_t resultright = esp_now_send(broadcastAddress, messageright, sizeof(messageright));

  if (resultright == ESP_OK) {
    Serial.println("Message sent successfully");
  } else {
    Serial.println("Error sending message");
  }

  delay(1000);



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

   //create message
  uint8_t messageleft[1];
  messageleft[0] = leftButtonState;

    // Send the message
  esp_err_t resultleft = esp_now_send(broadcastAddress, messageleft, sizeof(messageleft));

  if (resultleft == ESP_OK) {
    Serial.println("Message sent successfully");
  } else {
    Serial.println("Error sending message");
  }

  delay(1000);




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
  // read the state of the pushbutton value:
  rightButtonState = digitalRead(rightButtonPin);
  leftButtonState = digitalRead(leftButtonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (rightButtonState == HIGH) {
    // initiate right turn
    rightTurn();
    return;
  } 
    
  if (leftButtonState == HIGH){
    // initiate left turn
    leftTurn();
    return;
  } 
}
