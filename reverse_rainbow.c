#include<FastLED.h> // header file

#define NUM_LEDS 50 // number of led present in your strip
#define DATA_PIN 7 // digital pin of your arduino
#define COLOUR_FORMAT

CRGB leds[NUM_LEDS];
uint8_t delta_hue = (255 / NUM_LEDS);
int steps = 25;

void setup() {
  FastLED.addLeds<WS2811, DATA_PIN, COLOUR_FORMAT>(leds, NUM_LEDS);
  //FastLED.setBrightness(64);
}

void loop() {
  my_rainbow();
  FastLED.show();

  // I just wanna check that it's running
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)

  my_rainbow();
  FastLED.show();

  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
}

// fill_rainbow seems to have a compiler optimisation bug that inserts red LEDs
// in the wrong place, so we'll just hack it
// This version creates a rainbow, then reverses it so that I can fold my LED
// in half and hang it in the window
void my_rainbow() {
  for (int i = 0; i < steps; i++) {
    leds[i].setHue(CRGB::Red + i * (255 / steps));
  }
  for (int i = 0; i < steps; i++) {
    leds[i + steps].setHue(255 - (1 + i) * (255 / steps));
  }
}

