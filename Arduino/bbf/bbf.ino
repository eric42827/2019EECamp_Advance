#define Speed 4
#define Long 180

const byte Led[4] = {9, 10, 11, 12};
int brightness[4];
byte i;

void darken(int index)
{
    analogWrite(Led[index], brightness[index]);
    brightness[index] -= 1;
    if (brightness[index] < 1)
        brightness[index] = 0;
}

void setup()
{
    for (i = 0; i < 4; i++)
        pinMode(Led[i], OUTPUT);
}

void loop()
{
    for (i = 0; i < 4; i++)
        brightness[i] = 255;
    i = 0;
    while (brightness[3] > 0)
    {
        darken(i);
        if (i > 0)
            darken(i - 1);
        if (i > 1)
            darken(i - 2);
        if (i > 2)
            darken(i - 3);
        if (i > 3)
            darken(i - 4);
        if (brightness[i] == Long && i < 4)
            i++;
        delay(6 - Speed);
    }
    delay(150);
}