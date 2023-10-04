
#include "WiFi.h"
#include <esp_wifi.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  //put esp32 intostation mode
  WiFi.mode(WIFI_MODE_STA);
  //print MAC address
  Serial.println(WiFi.macAddress());
}

void loop() {
  // put your main code here, to run repeatedly:

}
