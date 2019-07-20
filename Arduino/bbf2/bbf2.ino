const byte pin[4] = {6, 9, 10, 11};

float theta = PI;
const float delta = 0.01;
const float diff = 0.5;
const float HALF_VMAX = 255.0 / 2.0;
bool movingRight = false;
void setup()
{
}

void loop()
{
    analogWrite(pin[0], HALF_VMAX * cos(2 * (theta)) + HALF_VMAX);
    analogWrite(pin[1], HALF_VMAX * cos(2 * (theta + diff)) + HALF_VMAX);
    analogWrite(pin[2], HALF_VMAX * cos(2 * (theta + diff * 2)) + HALF_VMAX);
    analogWrite(pin[3], HALF_VMAX * cos(2 * (theta + diff * 3)) + HALF_VMAX);
    if (movingRight)
    {
        theta += delta;
        if (theta + diff * 3 > 3 * PI)
        {
            movingRight = false;
        }
    }
    else
    {
        theta -= delta;
        if (theta < PI)
        {
            movingRight = true;
        }
    }
    delay(10);
}