#include "defines.h"

void __interrupt() isr() {
    if (INTCONbits.INTF) {
        INTCONbits.INTF = 0;
        tmCLOCK = TIME_300ms;
        if (tmWAIT_NEXT_RX == 0) {
            rxClocks++;
            LED_RX = 1;
        }
    } else if (PIR1bits.TMR1IF) {
        PIR1bits.TMR1IF = 0;
        if (timers[0]) timers[0]--;
        if (timers[1]) timers[1]--;
        if (timers[2]) timers[2]--;
        if (timers[3]) timers[3]--;
        if (timers[4]) timers[4]--;
        TMR1 = 65535 - 3200; //1ms

        if (button.status == BUTTON_STATUS_PRESSED)
            button.pressTime++;
    }
}