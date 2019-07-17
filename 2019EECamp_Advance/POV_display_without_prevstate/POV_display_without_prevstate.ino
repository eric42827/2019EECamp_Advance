#include <FastLED.h>
#define LED_PIN 8
#define NUM_LEDS 8
#define BRIGHTNESS 30
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];
#define UPDATES_PER_SECOND 100

int text_ok = 0;
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
byte q_letter[] = {124, 130, 138, 134, 126};
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

float delayTime = 1;

//POV clock cariables
unsigned long currentMillis, elapsed_loop_counter, previousMillis;
unsigned long counter_1, current_count;

//Interruption varaibles to count rotation speed
//We create 4 variables to store the previous value of the input signal (if LOW or HIGH)
float one_rot_time = 0; //Here we store the full rotation time
float time_per_deg = 0; //Here we store the time it takes to make one degree rotation

void setup()
{
  PCICR |= (1 << PCIE0);   //enable PCMSK0 scan
  PCMSK0 |= (1 << PCINT4); //Enable pin state interruption on pin D13

  //Output pins register configuration
  //DDRB |= B00000001;      //8 as output

  delay(3000); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  DDRB &= B11101111; //13 input
}

void draw_a_line(int this_line)
{
  leds[0] = this_line & 0b00000001 ? CRGB::Red : CRGB::Black;
  leds[1] = this_line & 0b00000010 ? CRGB::Red : CRGB::Black;
  leds[2] = this_line & 0b00000100 ? CRGB::Red : CRGB::Black;
  leds[3] = this_line & 0b00001000 ? CRGB::Red : CRGB::Black;
  leds[4] = this_line & 0b00010000 ? CRGB::Red : CRGB::Black;
  leds[5] = this_line & 0b00100000 ? CRGB::Red : CRGB::Black;
  leds[6] = this_line & 0b01000000 ? CRGB::Red : CRGB::Black;
  leds[7] = this_line & 0b10000000 ? CRGB::Red : CRGB::Black;
  FastLED.show();
}

void displayChar(char cr, float line_delay)
{
  if (cr == 'a')
    for (int i = 0; i < 5; i++)
      draw_a_line(a[i]);
  else if (cr == 'b')
    for (int i = 0; i < 5; i++)
      draw_a_line(b[i]);
  else if (cr == 'c')
    for (int i = 0; i < 5; i++)
      draw_a_line(c[i]);
  else if (cr == 'd')
    for (int i = 0; i < 5; i++)
      draw_a_line(d[i]);
  else if (cr == 'e')
    for (int i = 0; i < 5; i++)
      draw_a_line(e[i]);
  else if (cr == 'f')
    for (int i = 0; i < 5; i++)
      draw_a_line(f[i]);
  else if (cr == 'g')
    for (int i = 0; i < 5; i++)
      draw_a_line(g[i]);
  else if (cr == 'h')
    for (int i = 0; i < 5; i++)
      draw_a_line(h[i]);
  else if (cr == 'i')
    for (int itr = 0; itr < 3; itr++)
      draw_a_line(i[itr]);
  else if (cr == 'j')
    for (int i = 0; i < 5; i++)
      draw_a_line(j[i]);
  else if (cr == 'k')
    for (int i = 0; i < 5; i++)
      draw_a_line(k[i]);
  else if (cr == 'l')
    for (int i = 0; i < 5; i++)
      draw_a_line(l[i]);
  else if (cr == 'm')
    for (int i = 0; i < 5; i++)
      draw_a_line(m[i]);
  else if (cr == 'n')
    for (int i = 0; i < 5; i++)
      draw_a_line(n[i]);
  else if (cr == 'o')
    for (int i = 0; i < 5; i++)
      draw_a_line(o[i]);
  else if (cr == 'p')
    for (int i = 0; i < 5; i++)
      draw_a_line(p[i]);
  else if (cr == 'q')
    for (int i = 0; i < 5; i++)
      draw_a_line(q_letter[i]);
  else if (cr == 'r')
    for (int i = 0; i < 5; i++)
      draw_a_line(r[i]);
  else if (cr == 's')
    for (int i = 0; i < 5; i++)
      draw_a_line(s[i]);
  else if (cr == 't')
    for (int i = 0; i < 5; i++)
      draw_a_line(t[i]);
  else if (cr == 'u')
    for (int i = 0; i < 5; i++)
      draw_a_line(u[i]);
  else if (cr == 'v')
    for (int i = 0; i < 5; i++)
      draw_a_line(v[i]);
  else if (cr == 'w')
    for (int i = 0; i < 5; i++)
      draw_a_line(w[i]);
  else if (cr == 'x')
    for (int i = 0; i < 5; i++)
      draw_a_line(x[i]);
  else if (cr == 'y')
    for (int i = 0; i < 5; i++)
      draw_a_line(y[i]);
  else if (cr == 'z')
    for (int i = 0; i < 5; i++)
      draw_a_line(z[i]);
  else if (cr == '!')
    for (int i = 0; i < 3; i++)
      draw_a_line(excl[i]);
  else if (cr == '?')
    for (int i = 0; i < 5; i++)
      draw_a_line(ques[i]);
  else if (cr == '.')
    for (int i = 0; i < 4; i++)
      draw_a_line(eos[i]);
  draw_a_line(0);
}

void displayString(char *s, float line_delay)
{
  for (int i = 0; i <= strlen(s); i++)
  {
    displayChar(s[i], line_delay);
  }
}

void loop()
{
  currentMillis = micros();
  elapsed_loop_counter = currentMillis - previousMillis;
  delayTime = time_per_deg; //we want 2 degrees for each line of the letters

  //This if here is to make sure I'll start printing at 216 deg so the text will be centered.
  if ((elapsed_loop_counter >= time_per_deg * (216)) && (elapsed_loop_counter < time_per_deg * (217)) && text_ok)
  {
    displayString("ntuee.", delayTime);
    //delayMicroseconds(delayTime*10);
    text_ok = 0;
  }
}

ISR(PCINT0_vect)
{
  current_count = micros();
  ///////////////////////////////////////Channel 1
  if (PINB & B00010000)
  {                            //We make an AND with the pin state register, We verify if pin 12 is HIGH???
    counter_1 = current_count; //Set counter_1 to current value.
  }
  else
  {                                           //If pin 8 is LOW and the last state was HIGH then we have a state change
    one_rot_time = current_count - counter_1; //We make the time difference. Channel 1 is current_time - timer_1.
    time_per_deg = one_rot_time / 360.0;
    previousMillis = micros();
    text_ok = 1;
  }
}
