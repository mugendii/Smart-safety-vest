// Pin to use to send signals to WS2812B
#define REDLEDSTRIP_PIN 25
#define BLUELEDSTRIP_PIN 26
#define GREENLEDSTRIP_PIN 27


// overall bright ness value
int brightness = 255;
// Individual brightness value 
int g_bright =0;
int r_bright = 0;
int b_bright = 0;

int fadeSpeed = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(REDLEDSTRIP_PIN, OUTPUT);
  pinMode(BLUELEDSTRIP_PIN, OUTPUT);
  pinMode(GREENLEDSTRIP_PIN, OUTPUT);
}
//CALL THE METHODS
TurnOn();
delay(5000);
TurnOff();


void TurnOn(){
  for(int i=0; i<256; i++){
    analogWrite(REDLEDSTRIP_PIN, r_bright);
    r_bright +=1;
    delay(fadeSpeed)

  }
  for(int i=0; i<256; i++){
    analogWrite(BLUELEDSTRIP_PIN, b_bright);
    b_bright +=1;
    delay(fadeSpeed)

  }
  for(int i=0; i<256; i++){
    analogWrite(GREENLEDSTRIP_PIN, g_bright);
    g_bright +=1;
    delay(fadeSpeed)

  }
}
void TurnOff(){
  for(int i=0;i<256; I++){
    analogWrite(GREENLEDSTRIP_PIN,brightness);
    analogWrite(BLUELEDSTRIP_PIN,brightness);
    analogWrite(REDLEDSTRIP_PIN,brightness);
  brightness -= 1;
  delay(delay(fadeSpeed))
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
