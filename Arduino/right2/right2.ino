const byte pin[] = {9, 10, 11, 12};
int j = 0;

void setup() {
    for(int i=0; i<4; i+=1) {
        pinMode(pin[i], OUTPUT);
        digitalWrite(pin[i], LOW);
    }
}

void loop() {
    digitalWrite(pin[i], HIGH);
    delay(1000);
    digitalWrite(pin[i], LOW);
    j += 1;
    if (j == 4) {
        j = 0;
    }
}