#include "defines.h"

void setup() {
    TRISA = SET_TRISA;
    TRISB = SET_TRISB;
    TRISC = SET_TRISC;
    PORTB = 0;
    PORTC = 0;

    T1CON = 0;
    T1CONbits.TMR1CS = 0;
    T1CONbits.TMR1ON = 1;

    ADCON0 = 0;
    ADCON1bits.PCFG = 0b0110;

    OPTION_REGbits.nRBPU = 0;
    OPTION_REGbits.INTEDG = 0;

    INTCONbits.INTE = 1;
    PIE1bits.TMR1IE = 1;
    PEIE = 1;
    GIE = 1;
    
    rxClocks = 0;
}

void main(void) {

    setup();

    __delay_ms(500);
    
    score.team1 = 0;
    score.team2 = 0;
    
    loadMemory();
    isSaveMemory = 0;

    while (1) {
        checkButtons();
        updateDisplay();
        if (tmCLOCK == 0 && rxClocks > 0) {
            LED_RX = 0;
            if (rxClocks > 200) up2();
            else up1();
            rxClocks = 0;
            tmWAIT_NEXT_RX = TIME_3s;
        }
        
        if(isSaveMemory && tmMEMORY == 0){
            isSaveMemory = 0;
            saveMemory();
        }
    }
}
