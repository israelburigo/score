
#ifndef DEFINES_H
#define	DEFINES_H

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low Voltage In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = ALL        // FLASH Program Memory Write Enable (Unprotected program memory may be written to by EECON control)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#define _XTAL_FREQ 12800000L

#define SET_TRISA 0b11111111
#define SET_TRISB 0b00000001
#define SET_TRISC 0b00000000

#define RX_INPUT PORTBbits.RB0
#define LED_RX  PORTCbits.RC7

#define BTN_UP1 PORTAbits.RA0
#define BTN_DOWN1 PORTAbits.RA1
#define BTN_UP2 PORTAbits.RA2
#define BTN_DOWN2 PORTAbits.RA3
#define BTN_CHANGE PORTAbits.RA4
#define BTN_WIN PORTAbits.RA5

#define BUTTON_STATUS_RELEASED 0
#define BUTTON_STATUS_PRESSED 1

#define TIME_100ms 100
#define TIME_10ms 10
#define TIME_300ms 300

#define checkZero(x) !(x || x)

struct BUTTON {
    char status;
};

const char DIGITS[] = {
    0b111110,
    0b111101,
    0b111011,
    0b110111,
    0b101111,
    0b011111
};

const char NUMBERS[] = {
    0b01111110,
    0b00001100,
    0b10110110,
    0b10011110,
    0b11001100,
    0b11011010,
    0b11111010,
    0b00001110,
    0b11111110,
    0b10011110
};

void checkButtons(void);
void updateDisplay(void);
void up1(void);
void up2(void);

struct SCORE {
    signed char team1;
    signed char team2;
    char win1;
    char win2;
    char digit;
};

struct SCORE score;
struct BUTTON button;

volatile unsigned int rxClocks;
volatile unsigned int timers[3];

#define tmDISPLAY timers[0]
#define tmBUTTON timers[1]
#define tmCLOCK timers[2]

#endif

