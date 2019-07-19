#define Speed 4  //Min = 1 ,Max = 5
#define Long 180 //Min = 0 ,Max = 254

const byte Led[4] = {9, 10, 11, 12}; //建立儲存LED接腳位置陣列
int brightness[4];                   //建立儲存LED亮度陣列
byte i;

void darken(int index)
{
    analogWrite(Led[index], brightness[index]); //對LED腳位輸出PWM信號
    brightness[index] -= 1;                     //並將值衰減一次後回傳
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
        brightness[i] = 255;  //存入各LED點燈亮度值
    i = 0;                    //預設開始點燈位置
    while (brightness[3] > 0) //判斷最後一個燈是否熄滅
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
            i++;          //判斷是否點亮下一顆燈
        delay(6 - Speed); //設定延遲時間
    }
    delay(150);
}