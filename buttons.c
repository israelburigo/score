#include "defines.h"

char checkButton(char btn, void (*action)(void)) {
    if (!checkZero(btn)) return BUTTON_STATUS_RELEASED;
    if (button.status == BUTTON_STATUS_PRESSED) {
        tmBUTTON = TIME_100ms;
        return BUTTON_STATUS_PRESSED;
    }
    if (tmBUTTON)return BUTTON_STATUS_PRESSED;

    action();
    return BUTTON_STATUS_PRESSED;
}

void up1(void) {
    if (++score.team1 > 99) score.team1 = 99;
}

void up2(void) {
    if (++score.team2 > 99) score.team2 = 99;
}

void down1(void) {
    if (--score.team1 < 0) score.team1 = 0;
}

void down2(void) {
    if (--score.team2 < 0) score.team2 = 0;
}

void change(void) {
    if (score.team1 > 0 || score.team2 > 0) return;
    char aux = score.win1;
    score.win1 = score.win2;
    score.win2 = aux;
}

void win(void) {
    if (score.team1 == score.team2) return;
    if (score.team1 > score.team2) score.win1++;
    if (score.team2 > score.team1) score.win2++;
    score.team1 = score.team2 = 0;
}

void checkButtons(void) {
    button.status = checkButton(BTN_UP1, up1)
            || checkButton(BTN_UP2, up2)
            || checkButton(BTN_DOWN1, down1)
            || checkButton(BTN_DOWN2, down2)
            || checkButton(BTN_CHANGE, change)
            || checkButton(BTN_WIN, win);
}