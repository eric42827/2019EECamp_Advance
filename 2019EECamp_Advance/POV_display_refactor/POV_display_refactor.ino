#include <FastLED.h>
#define LED_PIN 8
#define NUM_LEDS 8
#define BRIGHTNESS 30
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
CRGB LEDs[NUM_LEDS];
// #define UPDATES_PER_SECOND 100

int text_ok = 0;
namespace pattern {
  byte a[] = {126, 144, 144, 144, 126};
  byte b[] = {254, 146, 146, 146, 108};
  byte c[] = {254, 130, 130, 130, 130};
  byte d[] = {254, 130, 130, 130, 124};
  byte e[] = {254, 146, 146, 146, 146};
  byte f[] = {254, 144, 144, 144, 128};
  byte g[] = {124, 130, 138, 138, 76};
  byte h[] = {254, 16, 16, 16, 254};
  byte i[] = {130, 250, 130};
  byte j[] = {12, 2, 2, 2, 252};
  byte k[] = {254, 16, 40, 68, 130};
  byte l[] = {254, 2, 2, 2, 2};
  byte m[] = {254, 64, 32, 64, 254};
  byte n[] = {254, 32, 16, 8, 254};
  byte o[] = {124, 130, 130, 130, 124};
  byte p[] = {254, 136, 136, 136, 112};
  byte q[] = {124, 130, 138, 134, 126};
  byte r[] = {254, 144, 152, 148, 98};
  byte s[] = {100, 146, 146, 146, 76};
  byte t[] = {128, 128, 254, 128, 128};
  byte u[] = {252, 2, 2, 2, 252};
  byte v[] = {248, 4, 2, 4, 248};
  byte w[] = {254, 4, 8, 4, 254};
  byte x[] = {198, 40, 16, 40, 198};
  byte y[] = {224, 16, 14, 16, 224};
  byte z[] = {134, 138, 146, 162, 194};
  byte eos[] = {0, 3, 2, 0};
  byte excl[] = {0, 250, 0};
  byte ques[] = {64, 128, 138, 144, 96};
}

unsigned long rotation_end_time, full_rotation_time = 0;

void setup()
{
  PCICR |= (1 << PCIE0);   // Enable PCMSK0 scan
  PCMSK0 |= (1 << PCINT4); // Enable pin state interruption on pin D13

  delay(3000); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(LEDs, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  pinMode(12, INPUT);
}

void draw_a_line(int this_line)
{
  LEDs[0] = this_line & 0b00000001 ? CRGB::Red : CRGB::Black;
  LEDs[1] = this_line & 0b00000010 ? CRGB::Red : CRGB::Black;
  LEDs[2] = this_line & 0b00000100 ? CRGB::Red : CRGB::Black;
  LEDs[3] = this_line & 0b00001000 ? CRGB::Red : CRGB::Black;
  LEDs[4] = this_line & 0b00010000 ? CRGB::Red : CRGB::Black;
  LEDs[5] = this_line & 0b00100000 ? CRGB::Red : CRGB::Black;
  LEDs[6] = this_line & 0b01000000 ? CRGB::Red : CRGB::Black;
  LEDs[7] = this_line & 0b10000000 ? CRGB::Red : CRGB::Black;
  FastLED.show();
}

void displayChar(char cr)
{
  if (cr == 'a')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::a[i]);
  else if (cr == 'b')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::b[i]);
  else if (cr == 'c')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::c[i]);
  else if (cr == 'd')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::d[i]);
  else if (cr == 'e')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::e[i]);
  else if (cr == 'f')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::f[i]);
  else if (cr == 'g')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::g[i]);
  else if (cr == 'h')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::h[i]);
  else if (cr == 'i')
    for (int i = 0; i < 3; i++)
      draw_a_line(pattern::i[i]);
  else if (cr == 'j')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::j[i]);
  else if (cr == 'k')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::k[i]);
  else if (cr == 'l')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::l[i]);
  else if (cr == 'm')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::m[i]);
  else if (cr == 'n')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::n[i]);
  else if (cr == 'o')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::o[i]);
  else if (cr == 'p')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::p[i]);
  else if (cr == 'q')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::q[i]);
  else if (cr == 'r')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::r[i]);
  else if (cr == 's')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::s[i]);
  else if (cr == 't')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::t[i]);
  else if (cr == 'u')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::u[i]);
  else if (cr == 'v')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::v[i]);
  else if (cr == 'w')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::w[i]);
  else if (cr == 'x')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::x[i]);
  else if (cr == 'y')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::y[i]);
  else if (cr == 'z')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::z[i]);
  else if (cr == '!')
    for (int i = 0; i < 3; i++)
      draw_a_line(pattern::excl[i]);
  else if (cr == '?')
    for (int i = 0; i < 5; i++)
      draw_a_line(pattern::ques[i]);
  else if (cr == '.')
    for (int i = 0; i < 4; i++)
      draw_a_line(pattern::eos[i]);
  draw_a_line(0);
}

void displayString(char *s)
{
  for (int i = 0; i <= strlen(s); i++)
    displayChar(s[i]);
}

void loop()
{ 
  static float delay_time = 1, time_per_deg = 0;
  static unsigned long current_time, time_delta;
  current_time = micros();
  time_delta = current_time - rotation_end_time;
  time_per_deg = full_rotation_time / 360.0;
  delay_time = time_per_deg; //we want 2 degrees for each line of the letters

  //This if here is to make sure I'll start printing at 216 deg so the text will be centered.
  if ((time_delta >= time_per_deg * (216)) && (time_delta < time_per_deg * (217)) && text_ok)
  {
    displayString("ntuee.");
    text_ok = 0;
  }
}

ISR(PCINT0_vect)
{
  static unsigned long current_time, rotation_start_time;
  static byte last_state = 1;
  current_time = micros();
  if (PINB & B00010000) // Check if PIN12 is HIGH
  {
    if (last_state == 0) // From LOW to HIGH, leaves magnet
    {
      last_state = 1;
      rotation_start_time = current_time;
    }
  }
  else if (last_state == 1) // From HIGH to LOW, enters magnet
  {
    last_state = 0;
    full_rotation_time = current_time - rotation_start_time;
    rotation_end_time = micros(); // TODO replace with current_time?
    text_ok = 1;
  }
}
