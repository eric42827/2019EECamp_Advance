#include <FastLED.h>
#define LED_PIN 8
#define NUM_LEDS 8
#define BRIGHTNESS 30
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

int char_a[] = {
    0b01111110,
    0b10010000,
    0b10010000,
    0b10010000,
    0b01111110};
int char_b[] = {
    0b11111110,
    0b10010010,
    0b10010010,
    0b10010010,
    0b01101100};
int char_c[] = {
    0b11111110,
    0b10000010,
    0b10000010,
    0b10000010,
    0b10000010};
int char_d[] = {
    0b11111110,
    0b10000010,
    0b10000010,
    0b10000010,
    0b01111100};
int char_e[] = {
    0b11111110,
    0b10010010,
    0b10010010,
    0b10010010,
    0b10010010};
int char_f[] = {
    0b11111110,
    0b10010000,
    0b10010000,
    0b10010000,
    0b10000000};
int char_g[] = {
    0b01111100,
    0b10000010,
    0b10001010,
    0b10001010,
    0b01001100};
int char_h[] = {
    0b11111110,
    0b00010000,
    0b00010000,
    0b00010000,
    0b11111110};
int char_i[] = {
    0b10000010,
    0b11111010,
    0b10000010};
int char_j[] = {
    0b00001100,
    0b00000010,
    0b00000010,
    0b00000010,
    0b11111100};
int char_k[] = {
    0b11111110,
    0b00010000,
    0b00101000,
    0b01000100,
    0b10000010};
int char_l[] = {
    0b11111110,
    0b00000010,
    0b00000010,
    0b00000010,
    0b00000010};
int char_m[] = {
    0b11111110,
    0b01000000,
    0b00100000,
    0b01000000,
    0b11111110};
int char_n[] = {
    0b11111110,
    0b00100000,
    0b00010000,
    0b00001000,
    0b11111110};
int char_o[] = {
    0b01111100,
    0b10000010,
    0b10000010,
    0b10000010,
    0b01111100};
int char_p[] = {
    0b11111110,
    0b10001000,
    0b10001000,
    0b10001000,
    0b01110000};
int char_q[] = {
    0b01111100,
    0b10000010,
    0b10001010,
    0b10000110,
    0b01111110};
int char_r[] = {
    0b11111110,
    0b10010000,
    0b10011000,
    0b10010100,
    0b01100010};
int char_s[] = {
    0b01100100,
    0b10010010,
    0b10010010,
    0b10010010,
    0b01001100};
int char_t[] = {
    0b10000000,
    0b10000000,
    0b11111110,
    0b10000000,
    0b10000000};
int char_u[] = {
    0b11111100,
    0b00000010,
    0b00000010,
    0b00000010,
    0b11111100};
int char_v[] = {
    0b11111000,
    0b00000100,
    0b00000010,
    0b00000100,
    0b11111000};
int char_w[] = {
    0b11111110,
    0b00000100,
    0b00001000,
    0b00000100,
    0b11111110};
int char_x[] = {
    0b11000110,
    0b00101000,
    0b00010000,
    0b00101000,
    0b11000110};
int char_y[] = {
    0b11100000,
    0b00010000,
    0b00001110,
    0b00010000,
    0b11100000};
int char_z[] = {
    0b10000110,
    0b10001010,
    0b10010010,
    0b10100010,
    0b11000010};

int eos[] = {
    0b00000000,
    0b00000011,
    0b00000010,
    0b00000000};
int excl[] = {
    0b00000000,
    0b11111010,
    0b00000000};
int ques[] = {
    0b01000000,
    0b10000000,
    0b10001010,
    0b10010000,
    0b01100000};

float delayTime = 1;
bool text_ok = false;
int *letters[] = {char_a, char_b, char_c, char_d, char_e, char_f, char_g, char_h, char_i, char_j, char_k, char_l, char_m, char_m, char_o, char_p, char_q, char_r, char_s, char_t, char_u, char_v, char_w, char_x, char_y, char_z};

// POV clock variables
unsigned long currentMillis, elapsed_loop_counter, previousMillis;
unsigned long counter_1, current_count;

// Interruption varaibles to count rotation speed
// We create 4 variables to store the previous value of the input signal (if LOW or HIGH)
byte last_IN_state;     // Here we store the previous state on digital pin 13
float one_rot_time = 0; // Here we store the full rotation time
float time_per_deg = 0; // Here we store the time it takes to make one degree rotation

void setup()
{
  PCICR |= (1 << PCIE0);   //enable PCMSK0 scan
  PCMSK0 |= (1 << PCINT4); //Enable pin state interruption on pin D12

  delay(3000); // Power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  DDRB &= B11101111; // set PIN 12 as Input (PB4)
}

void draw_a_line(int this_line)
{
  for (int i = 0; i < 8; ++i)
  {
    leds[i] = this_line & (1 << i) ? CRGB::Red : CRGB::Black;
  }
  FastLED.show();
}

void displayChar(char cr, float line_delay)
{

  if (cr == 'i') {
    for (int itr = 0; itr < 3; itr++)
    {
      draw_a_line(char_i[itr]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  else if (cr >= 'a' && cr <= 'z') {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(letters[cr - 'a'][i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  else if (cr == '!') {
    for (int i = 0; i < 3; i++)
    {
      draw_a_line(excl[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  else if (cr == '?') {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(ques[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  else if (cr == '.') {
    for (int i = 0; i < 4; i++)
    {
      draw_a_line(eos[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  delayMicroseconds(line_delay * 2);
}

void displayString(char *s, float line_delay)
{
  for (int i = 0; i <= strlen(s); i++)
    displayChar(s[i], line_delay);
}

void loop()
{

  currentMillis = micros();
  elapsed_loop_counter = currentMillis - previousMillis;
  delayTime = time_per_deg; //we want 2 degrees for each line of the letters

  //This if here is to make sure I'll start printing at 216 deg so the text will be centered.
  if ((elapsed_loop_counter >= time_per_deg * 216) && (elapsed_loop_counter < time_per_deg * 217) && text_ok)
  {
    displayString("ntuee.", delayTime);
    //delayMicroseconds(delayTime*10);
    text_ok = false;
  }
}

ISR(PCINT0_vect)
{
  //First we take the current count value in micro seconds using the micros() function

  ///////////////////////////////////////Channel 1
  if (PINB & B00010000) // Read from PB4 (PIN 12), true if 12 is HIGH (rising edge)
  {
    if (last_IN_state == 0) // 12 goes from LOW to HIGH
    {
      last_IN_state = 1;         // Store the current state into the last state for the next loop
      counter_1 = micros(); // Set counter_1 to current value.
    }
  }
  else if (last_IN_state == 1) // 12 is LOW, and goes from HIGH to LOW (falling edge)
  {
    last_IN_state = 0;                        // Store the current state into the last state for the next loop
    one_rot_time = micros() - counter_1; // We make the time difference. Channel 1 is current_time - timer_1.
    time_per_deg = one_rot_time / 360.0;
    previousMillis = micros();
    text_ok = true;
  }
}
