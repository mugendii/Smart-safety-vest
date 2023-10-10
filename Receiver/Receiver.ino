/*
  This is the code to be uploaded to the receiver controller on the wearable vest
  I recommend using using esp8266 for the following code though further changes can be done to make it compatible with esp32
*/
#include <Adafruit_NeoPixel.h>
//#include <fastLED.h>
#include <esp_now.h>
#include <WiFi.h>


// Replace with the MAC address of the transmitter ESP32
uint8_t transmitterMacAddress[] = {0xA0, 0xB7, 0x65, 0x60, 0x1B, 0x70};
/* for prototyping we started with LEDs*/
const int LED_PINRIGHT = 13;  // Pin connected to the LED
const int LED_PINLEFT = 12;

// Pin to use to send signals to WS2812B
#define REDLEDSTRIP_PIN 25
#define BLUELEDSTRIP_PIN 26
#define GREENLEDSTRIP_PIN 27

// Number of WS2812B LEDs attached to the Arduino
#define LED_COUNT 12

// Setting up the NeoPixel library
//Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  //strip.begin();           // Initialize NeoPixel object
  //strip.setBrightness(10); // Set BRIGHTNESS to about 4% (max = 255)

  Serial.begin(115200);
  pinMode(LED_PINRIGHT, OUTPUT);
  pinMode(LED_PINLEFT, OUTPUT);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }


   esp_now_peer_info_t peerInfo;
  memcpy(peerInfo.peer_addr, transmitterMacAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Error adding peer");
    return;
  }

  esp_now_register_recv_cb(uint8_t *mac, uint8_t *data, uint8_t *len) {
    if (len == 1) {
      if (data[0] == HIGH) {
        digitalWrite(LED_PINRIGHT, HIGH);  // Turn on the first LED
      } else {
        digitalWrite(LED_PINRIGHT, LOW);   // Turn off the first LED
      }
      
    } 
    if (len == 2) {
      if (data[1] == HIGH) {
        digitalWrite(LED_PINLEFT, HIGH);  // Turn on the second LED
      } else {
        digitalWrite(LED_PINLEFT, LOW);   // Turn off the second LED
      }
    }
  }


}

void loop() {
 
}

/*
 strip.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<LED_COUNT; i++) {
    // Set the i-th LED to pure green:
    strip.setPixelColor(i, 0, 255, 0);
  
    strip.show();   // Send the updated pixel colors to the hardware.
  
    delay(500); // Pause before next pass through loop
  }*/