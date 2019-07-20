const byte pin[] = {9, 10, 11, 12, 12, 11, 10, 9};

void setup()
{
    for (int i = 0; i < 4; i += 1)
    {
        pinMode(pin[i], OUTPUT);
        digitalWrite(pin[i], LOW);
    }
}

void loop()
{
    for (int i = 0; i < 8; i += 1)
    {
        digitalWrite(pin[i], HIGH);
        delay(1000);
        digitalWrite(pin[i], LOW);
    }
}