const byte pin[] = {9, 10, 11, 12};
volatile bool movingRight = true;
int j = 0;

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
    digitalWrite(pin[j], HIGH); // 點亮第j個LED
    delay(1000);                // 延遲1秒
    digitalWrite(pin[j], LOW);  // 關閉第j個LED
    if (movingRight)
    {
        j += 1; // 右移
        if (j == 4)
        { // 檢查是否已右移至最右方
            j = 3;
            movingRight = false; // 改成向左移
        }
    }
    else
    {
        j -= 1; // 左移
        if (j == -1)
        { // 檢查是否已右移至最左方
            j = 0;
            movingRight = true; // 改成向右移
        }
    }
}
