#include "mbed.h"
#include "header_serial.hpp"


int main() {
    while(1) {
        serial_read();
    }
}

void serial_read(){
    led[0] = 0;
    led[1] = 0;
    if(pc.readable()){
        op = pc.getc();
        dimmer();
    }
}
    

void dimmer(){
    if(op == '+'){
        iLED = iLED + 0.1;
        timeout.attach(&blink,0.1);
    }
    if(op == '-'){
        iLED = iLED - 0.1;
        timeout.attach(&blink,0.1);
    }
}

void blink(){
    if(op == '+'){
        led[0] = 1;
        timeout.attach(&serial_read,0.1);
    }
    if(op == '-'){
        led[1] = 1;
        timeout.attach(&serial_read,0.1);
    }
}
        