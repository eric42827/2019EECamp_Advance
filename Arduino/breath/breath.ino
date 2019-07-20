byte brightness = 0;
bool descending = false;
const byte delta = 10;
void setup()
{
}

void loop()
{
    analogWrite(10, brightness);
    delay(10);
    if (descending)
    {
        if (brightness < delta)
        {
            brightness = 0;
            descending = false;
        }
        else
        {
            brightness -= delta;
        }
    }
    else
    {
        if (brightness > 255 - delta)
        {
            brightness = 255;
            descending = true;
        }
        else
        {
            brightness += delta;
        }
    }
}