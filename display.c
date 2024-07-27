#include "defines.h"

char calcDigit(signed char value, char dozen) {
    char d = (char) value / 10;
    char u = (char) value - d * 10;
    return score.digit == dozen ? d : u;
}

char getNumber() {
    if (score.digit < 2) return calcDigit(score.team1, 0);
    if (score.digit < 4) return calcDigit(score.team2, 2);
    if (score.digit == 4) return score.win1;
    if (score.digit == 5) return score.win2;
    return 0;
}

void updateDisplay(void) {
    if (tmDISPLAY) return;
    tmDISPLAY = TIME_2ms;

    if (++score.digit > 5) score.digit = 0;
    char number = NUMBERS[getNumber()];
    char digit = DIGITS[score.digit];

    PORTC = (PORTC & 0b10000000) | digit;
    PORTB = number;
}