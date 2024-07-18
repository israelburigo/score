#include "defines.h"

void setup() {
    TRISA = 0xFF;
    TRISB = 0x00;
    TRISC = 0x00;
    PORTB = 0;
    PORTC = 0;

    T1CON = 0;
    T1CONbits.TMR1CS = 0;
    T1CONbits.TMR1ON = 1;

    ADCON0 = 0;
    ADCON1bits.PCFG = 0b0110;

    PIE1bits.TMR1IE = 1;
    PEIE = 1;
    GIE = 1;
}

void main(void) {

    setup();
    
    __delay_ms(500);

    while (1) {
        checkButtons();
        updateDisplay();
    }
}
