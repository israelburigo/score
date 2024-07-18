#include "defines.h"

void __interrupt() isr() {
    if (PIR1bits.TMR1IF) {
        PIR1bits.TMR1IF = 0;
        if (timers[0]) timers[0]--;
        if (timers[1]) timers[1]--;
        TMR1 = 65535 - 3200;
    }
}