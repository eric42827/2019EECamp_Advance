float theta = 0;
bool descending = false;
const float delta = 0.05;
void setup()
{
}

void loop()
{
    analogWrite(10, 255 * sin(theta));
    delay(10);
    if (descending)
    {
        if (theta < 0)
        {
            theta = 0;
            descending = false;
        }
        else
        {
            theta -= delta;
        }
    }
    else
    {
        if (theta > HALF_PI)
        {
            theta = HALF_PI;
            descending = true;
        }
        else
        {
            theta += delta;
        }
    }
}