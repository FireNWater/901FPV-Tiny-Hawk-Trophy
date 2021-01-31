#include <Adafruit_NeoPixel.h>

#define PIN        12
#define NUMPIXELS 8

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500

void setup() {
  Serial.begin(9600);
  pixels.begin();
}

void loop() {
  pixels.clear();

  delay(DELAYVAL);

  for(int i=0; i<NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(255, 250, 255));
    pixels.show();
    delay(DELAYVAL);
  }

  Serial.print("Congratulations Dream_Z!!!\n");
  delay(1000);
  Serial.print("Current 901FPV Tiny Hawk Champiom!!!\n");
}
