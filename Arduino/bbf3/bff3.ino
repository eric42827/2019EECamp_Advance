const uint8_t led[4] = {6, 9, 10, 11};
const uint8_t brightness[][4] = {
    {0, 0, 0, 0},
    {30, 0, 0, 0},
    {105, 30, 0, 0},
    {180, 105, 30, 0},
    {255, 180, 105, 30},
    {180, 255, 180, 105},
    {105, 180, 255, 180},
    {30, 105, 180, 255},
    {0, 30, 105, 180},
    {0, 0, 30, 105},
    {0, 0, 0, 30},
};

int i = 0;   //Current LED state index
int dir = 1; //1右，-1向左

void setup()
{
}

void loop()
{

    for (int k = 0; k < 11; k += 1) //向右
    {
        for (int j = 0; j < 4; j += 1) //LED index
        {
            analogWrite(led[j], brightness[k][j]);
            delay(50);
        }
    }
    for (int j = 0; j < 4; j += 1) //LED index
    {
        analogWrite(led[j], 0);
    }
    delay(200);

    for (int k = 0; k < 11; k += 1) //向左
    {
        for (int j = 0; j < 4; j += 1) //LED index
        {
            analogWrite(led[j], brightness[k][3 - j]);
            delay(50);
        }
    }
    for (int j = 0; j < 4; j++) //LED index
    {
        analogWrite(led[j], 0);
    }
    delay(200);
}