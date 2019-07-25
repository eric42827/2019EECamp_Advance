#include <FastLED.h>
#define LED_PIN 8
#define NUM_LEDS 8
#define BRIGHTNESS 30
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];
#define UPDATES_PER_SECOND 100

int text_ok = 0;
byte e[] = {254, 146, 146, 146, 146};

float delayTime = 1;

unsigned long currentMillis, elapsed_loop_counter, previousMillis;
unsigned long counter_1, current_count;

byte last_IN_state;
float one_rot_time = 0; // 轉一圈的時間
float time_per_deg = 0; // 每一度多少秒

void setup()
{
  PCICR |= (1 << PCIE0);
  PCMSK0 |= (1 << PCINT4); //打開 D13 的 pin state interrupt

  delay(3000);
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  DDRB &= B11101111; // 把 12 設成 input
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

void displayChar(char cr, float line_delay)
{
  
  if (cr == 'e')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(e[i]);
    }
    draw_a_line(0);
  }
  
}

void displayString(const char *s, float line_delay)
{
  for (int i = 0; i < strlen(s); i++)
  {
    displayChar(s[i], line_delay);
  }
}

void loop()
{
  currentMillis = micros();
  elapsed_loop_counter = currentMillis - previousMillis;
  delayTime = time_per_deg *2; // 每一行兩度

  // 從第 216 度開始顯示
  if ((elapsed_loop_counter >= time_per_deg * (216)) && (elapsed_loop_counter < time_per_deg * (217)) && text_ok)
  {
    displayString("e", delayTime);
    text_ok = 0;
  }
}

ISR(PCINT0_vect)
{
  current_count = micros();
  if (PINB & B00010000) // 如果 12 是 HIGH
  {
    if (last_IN_state == 0) // 如果 12 從 LOW 變 HIGH
    {
      last_IN_state = 1;
      counter_1 = current_count;
    }
  }
  else if (last_IN_state == 1) // 如果 12 從 HIGH 變 LOW
  {
    last_IN_state = 0;
    one_rot_time = current_count - counter_1;
    time_per_deg = one_rot_time / 360.0;
    previousMillis = micros();
    text_ok = 1;
  }
}
