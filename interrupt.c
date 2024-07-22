#include "defines.h"

void __interrupt() isr() {
    if (INTCONbits.INTF) {
        INTCONbits.INTF = 0;
        tmCLOCK = TIME_300ms;
        rxClocks++;
        LED_RX = 1;
    } else if (PIR1bits.TMR1IF) {
        PIR1bits.TMR1IF = 0;
        if (timers[0]) timers[0]--;
        if (timers[1]) timers[1]--;
        if (timers[2]) timers[2]--;
        TMR1 = 65535 - 3200; //1ms
    }
}