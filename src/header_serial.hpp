#include <mbed.h>

DigitalOut led[]={(PD_15),(PD_13)};
PwmOut iLED(PA_9);
Serial pc(USBTX, USBRX);
char op;
Timeout timeout;

void serial_read();
void dimmer();
void blink();