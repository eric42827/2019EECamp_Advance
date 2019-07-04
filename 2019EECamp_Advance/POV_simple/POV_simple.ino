


#include <FastLED.h>

#define NUM_LEDS 10
#define LED_PIN     8
#define BRIGHTNESS  30
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

// How many leds in your strip?


// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
//#define DATA_PIN 10 
//#define DATA_PIN 4
//#define CLOCK_PIN 4

// Define the array of leds

void setup() { 
      delay( 3000 ); // power-up safety delay
      FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
      FastLED.setBrightness(  BRIGHTNESS );
      //FastLED.addLeds<NEOPIXEL, 10>(leds, NUM_LEDS);
      //FastLED.addLeds<NEOPIXEL, 4>(leds, NUM_LEDS);
       

  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(LED_BUILTIN, OUTPUT);



}

void loop() { 
// the loop function 1
  for(unsigned int _i=0; _i<(unsigned int)(20); _i++)
    {
  // Turn the LED on, then pause
  leds[0] = CRGB::Yellow;
  leds[1] = CRGB::White;
  leds[2] = CRGB::White; 
  leds[3] = CRGB::White;
  leds[4] = CRGB::White;
  leds[5] = CRGB::White;
  leds[6] = CRGB::White;
  leds[7] = CRGB::White;
  leds[8] = CRGB::White;
  leds[9] = CRGB::Yellow;
 FastLED.show();
delay(2);

  leds[0] = CRGB::Blue;
  leds[1] = CRGB::White;
  leds[2] = CRGB::White; 
  leds[3] = CRGB::White;
  leds[4] = CRGB::Yellow;
  leds[5] = CRGB::Yellow;
  leds[6] = CRGB::White;
  leds[7] = CRGB::White;
  leds[8] = CRGB::White;
  leds[9] = CRGB::Red;
 FastLED.show();
delay(2);

  // Now turn the LED off, then pause
  leds[0] = CRGB::Blue;
  leds[1] = CRGB::Blue;
  leds[2] = CRGB::White;
  leds[3] = CRGB::White;
  leds[4] = CRGB::White;
  leds[5] = CRGB::White;
  leds[6] = CRGB::White;
  leds[7] = CRGB::White;
  leds[8] = CRGB::Red;
  leds[9] = CRGB::Red;
FastLED.show();
delay(2);

  leds[0] = CRGB::Blue;
  leds[1] = CRGB::Blue;
  leds[2] = CRGB::Blue;
  leds[3] = CRGB::White;
  leds[4] = CRGB::White;
  leds[5] = CRGB::White;
  leds[6] = CRGB::White;
  leds[7] = CRGB::Red;
  leds[8] = CRGB::Red;
  leds[9] = CRGB::Red;
FastLED.show();
delay(2);


  leds[0] = CRGB::Blue;
  leds[1] = CRGB::Blue;
  leds[2] = CRGB::Blue;
  leds[3] = CRGB::Blue;
  leds[4] = CRGB::Yellow;
  leds[5] = CRGB::Yellow;
  leds[6] = CRGB::Red;
  leds[7] = CRGB::Red;
  leds[8] = CRGB::Red;
  leds[9] = CRGB::Red;
FastLED.show();
delay(2);

  leds[0] = CRGB::Blue;
  leds[1] = CRGB::Blue;
  leds[2] = CRGB::Blue;
  leds[3] = CRGB::Blue;
  leds[4] = CRGB::Blue;
  leds[5] = CRGB::Red;
  leds[6] = CRGB::Red;
  leds[7] = CRGB::Red;
  leds[8] = CRGB::Red;
  leds[9] = CRGB::Red;
FastLED.show();
delay(21);

  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  leds[3] = CRGB::Black;
  leds[4] = CRGB::Black;
  leds[5] = CRGB::Black;
  leds[6] = CRGB::Black;
  leds[7] = CRGB::Black;
  leds[8] = CRGB::Black;
  leds[9] = CRGB::Black;
FastLED.show();
delay(44);
      }
      /*
// the loop function 2
  for(unsigned int _i=0; _i<(unsigned int)(20); _i++)
    {

// Turn the LED on, then pause
  leds[0] = CRGB::Red;
  leds[1] = CRGB::Red;
  leds[2] = CRGB::Red; 
  leds[3] = CRGB::Red;
  leds[4] = CRGB::Red;
  leds[5] = CRGB::Red;
  leds[6] = CRGB::Red;
  leds[7] = CRGB::Red;
  leds[8] = CRGB::Red;
  leds[9] = CRGB::Red;
 FastLED.show();
delay(2);

  leds[0] = CRGB::Red;
  leds[1] = CRGB::Red;
  leds[2] = CRGB::Black; 
  leds[3] = CRGB::Black;
  leds[4] = CRGB::Black;
  leds[5] = CRGB::Black;
  leds[6] = CRGB::Black;
  leds[7] = CRGB::Black;
  leds[8] = CRGB::Red;
  leds[9] = CRGB::Red;
 FastLED.show();
delay(2);

  // Now turn the LED off, then pause
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Red; 
  leds[3] = CRGB::Red;
  leds[4] = CRGB::Red;
  leds[5] = CRGB::Red;
  leds[6] = CRGB::Red;
  leds[7] = CRGB::Red;
  leds[8] = CRGB::Black;
  leds[9] = CRGB::Black;
FastLED.show();
delay(2);

  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  leds[3] = CRGB::Black;
  leds[4] = CRGB::Black;
  leds[5] = CRGB::Black;
  leds[6] = CRGB::Black;
  leds[7] = CRGB::Black;
  leds[8] = CRGB::Black;
  leds[9] = CRGB::Black;
FastLED.show();
delay(2);


  leds[0] = CRGB::Red;
  leds[1] = CRGB::Red;
  leds[2] = CRGB::Red; 
  leds[3] = CRGB::Red;
  leds[4] = CRGB::Red;
  leds[5] = CRGB::Red;
  leds[6] = CRGB::Red;
  leds[7] = CRGB::Red;
  leds[8] = CRGB::Red;
  leds[9] = CRGB::Red;
FastLED.show();
delay(2);

  leds[0] = CRGB::Red;
  leds[1] = CRGB::Red;
  leds[2] = CRGB::Black; 
  leds[3] = CRGB::Black;
  leds[4] = CRGB::Red;
  leds[5] = CRGB::Red;
  leds[6] = CRGB::Black;
  leds[7] = CRGB::Black;
  leds[8] = CRGB::Black;
  leds[9] = CRGB::Black;
FastLED.show();
delay(2);

  leds[0] = CRGB::Red;
  leds[1] = CRGB::Red;
  leds[2] = CRGB::Black; 
  leds[3] = CRGB::Black;
  leds[4] = CRGB::Red;
  leds[5] = CRGB::Red;
  leds[6] = CRGB::Black;
  leds[7] = CRGB::Black;
  leds[8] = CRGB::Black;
  leds[9] = CRGB::Black;
FastLED.show();
delay(2);


  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Red;
  leds[3] = CRGB::Red;
  leds[4] = CRGB::Black;
  leds[5] = CRGB::Black;
  leds[6] = CRGB::Black;
  leds[7] = CRGB::Black;
  leds[8] = CRGB::Black;
  leds[9] = CRGB::Black;
FastLED.show();
delay(2);

  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  leds[3] = CRGB::Black;
  leds[4] = CRGB::Black;
  leds[5] = CRGB::Black;
  leds[6] = CRGB::Black;
  leds[7] = CRGB::Black;
  leds[8] = CRGB::Black;
  leds[9] = CRGB::Black;
  FastLED.show();
delay(2);


  leds[0] = CRGB::Red;
  leds[1] = CRGB::Red;
  leds[2] = CRGB::Red; 
  leds[3] = CRGB::Red;
  leds[4] = CRGB::Red;
  leds[5] = CRGB::Red;
  leds[6] = CRGB::Red;
  leds[7] = CRGB::Red;
  leds[8] = CRGB::Red;
  leds[9] = CRGB::Red;
FastLED.show();
delay(2);

  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  leds[3] = CRGB::Black;
  leds[4] = CRGB::Red;
  leds[5] = CRGB::Red;
  leds[6] = CRGB::Black;
  leds[7] = CRGB::Black;
  leds[8] = CRGB::Black;
  leds[9] = CRGB::Black;
  FastLED.show();
delay(2);

  leds[0] = CRGB::Red;
  leds[1] = CRGB::Red;
  leds[2] = CRGB::Red; 
  leds[3] = CRGB::Red;
  leds[4] = CRGB::Red;
  leds[5] = CRGB::Red;
  leds[6] = CRGB::Red;
  leds[7] = CRGB::Red;
  leds[8] = CRGB::Red;
  leds[9] = CRGB::Red;
FastLED.show();
delay(2);

  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  leds[3] = CRGB::Black;
  leds[4] = CRGB::Black;
  leds[5] = CRGB::Black;
  leds[6] = CRGB::Black;
  leds[7] = CRGB::Black;
  leds[8] = CRGB::Black;
  leds[9] = CRGB::Black;
  FastLED.show();
  delay(44);
//delay(44);                                                                                                                                           );
  }*/
}
