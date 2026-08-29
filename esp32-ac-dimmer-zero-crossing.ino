#define PIN_ZC 14
#define PIN_TRIAC 27

volatile int dimming = 50; // 0 (full) to 128 (off)

void IRAM_ATTR zeroCrossISR() {
 int delayTime = (75 * dimming); // Microseconds
 delayMicroseconds(delayTime);
 digitalWrite(PIN_TRIAC, HIGH);
 delayMicroseconds(10);
 digitalWrite(PIN_TRIAC, LOW);
}

void setup() {
 pinMode(PIN_ZC, INPUT_PULLUP);
 pinMode(PIN_TRIAC, OUTPUT);
 attachInterrupt(digitalPinToInterrupt(PIN_ZC), zeroCrossISR, RISING);
}

void loop() { delay(1000); }