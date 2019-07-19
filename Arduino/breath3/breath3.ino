float theta = 0;
const float delta = 0.05;
const float multiplier = 255.0 / 2.0;
void setup()
{
}

void loop()
{
    analogWrite(10, multiplier * sin(theta) + multiplier);
    delay(10);
    theta += delta;
}