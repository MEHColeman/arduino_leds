#include<FastLED.h> // header file

#define NUM_LEDS 50 // number of led present in your strip
#define DATA_PIN 7 // digital pin of your arduino

CRGB leds[NUM_LEDS];
uint8_t delta_hue = (255 / NUM_LEDS);

void setup() {
  FastLED.addLeds<WS2811, DATA_PIN, BRG>(leds, NUM_LEDS);
  //FastLED.setBrightness(64);
}

void loop() {
  leds[0] = CRGB::Red;
  leds[1] = CRGB::Orange;
  leds[2] = CRGB::Yellow;
  leds[3] = CRGB::Green;
  leds[4] = CRGB::Blue;
  leds[5] = CRGB::Indigo;
  leds[6] = CRGB::Violet;
  leds[49] = CRGB::Red;

  FastLED.show();
}

void loop_test_2() {
  for(int dot=(NUM_LEDS-1) ; dot >=0 ; dot--) {
    leds[dot] = CRGB::HotPink;
  }

  FastLED.show();

  delay(300);
}

void loop_test_3() {
  fill_rainbow(leds, NUM_LEDS, CRGB::Red, delta_hue);
  FastLED.show();
}
