#include <Adafruit_NeoPixel.h>

#define PIN        12
#define NUMPIXELS 8

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500

void setup() {

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
}