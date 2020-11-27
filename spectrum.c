/*
   LED spectrum

   Just a static spectrum of colour along your LED strip.
   */

#define FASTLED_ALLOW_INTERRUPTS 0            // Used for ESP8266.
#include "FastLED.h"

#define LED_DT 12                             // Serial data pin
#define LED_CK 11                             // Clock pin for WS2801 or APA102
#define COLOR_ORDER GRB                       // It's GRB for WS2812B and GBR for APA102
#define LED_TYPE WS2811                       // What kind of strip are you using (APA102, WS2801 or WS2812B)?
#define NUM_LEDS 30

// Initialize changeable global variables.
uint8_t max_bright = 255;                     // Overall brightness definition. It can be changed on the fly.

struct CRGB leds[NUM_LEDS];                   // Initialize our LED array.

void setup() {
  Serial.begin(115200);

  LEDS.addLeds<LED_TYPE, LED_DT, COLOR_ORDER>(leds, NUM_LEDS);         // For WS2812B
  //  LEDS.addLeds<LED_TYPE, LED_DT, LED_CK, COLOR_ORDER>(leds, NUM_LEDS);   // For APA102 or WS2801

  FastLED.setBrightness(max_bright);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 1000); // FastLED power management set at 5V, 500mA

}

void loop () {

  rainbow_wave(10, 10);                       // Speed, delta hue values.
  FastLED.show();

}

void rainbow_wave(uint8_t thisSpeed, uint8_t deltaHue) {  // The fill_rainbow call doesn't support brightness levels.
  // uint8_t thisHue = beatsin8(thisSpeed,0,255);   // A simple rainbow wave.
  uint8_t thisHue = beat8(thisSpeed,255);          // A simple rainbow march.

  fill_rainbow(leds, NUM_LEDS, thisHue, deltaHue); // Use FastLED's fill_rainbow routine.

}

