#include "defines.h"

char onClick(char btn, void (*action)(void)) {
    if (!checkZero(btn)) return BUTTON_STATUS_RELEASED;
    button.btn = btn;
    if (button.status == BUTTON_STATUS_PRESSED) {
        tmBUTTON = TIME_100ms;
        return BUTTON_STATUS_PRESSED;
    }
    if (tmBUTTON) return BUTTON_STATUS_PRESSED;
    action();
    tmBUTTON = TIME_100ms;
    return BUTTON_STATUS_PRESSED;
}

char onPressed(char btn, void (*action)(void), unsigned int pressTime, void (*pressAction)(void)) {
    if (!checkZero(btn)) return BUTTON_STATUS_RELEASED;
    button.btn = btn;
    if (button.status == BUTTON_STATUS_PRESSED) {
        if (pressTime != TIME_ZERO && button.pressTime > pressTime) {
            pressAction();
            button.pressTime = 0;
        }
        tmBUTTON = TIME_100ms;
        return BUTTON_STATUS_PRESSED;
    }
    if (tmBUTTON) return BUTTON_STATUS_PRESSED;
    action();
    tmBUTTON = TIME_100ms;
    return BUTTON_STATUS_PRESSED;
}

void up1(void) {
    if (++score.team1 > 99) score.team1 = 99;
    isSaveMemory = 1;
    tmMEMORY = TIME_5s;
}

void up2(void) {
    if (++score.team2 > 99) score.team2 = 99;
    isSaveMemory = 1;
    tmMEMORY = TIME_5s;
}

void down1(void) {
    if (--score.team1 < 0) score.team1 = 0;
    isSaveMemory = 1;
    tmMEMORY = TIME_5s;
}

void down2(void) {
    if (--score.team2 < 0) score.team2 = 0;
    isSaveMemory = 1;
    tmMEMORY = TIME_5s;
}

void change(void) {
    if (score.team1 > 0 || score.team2 > 0) return;
    char aux = score.win1;
    score.win1 = score.win2;
    score.win2 = aux;
    isSaveMemory = 1;
    tmMEMORY = TIME_5s;
}

void clear(void) {
    score.win1 = score.win2 = 0;
    score.team1 = score.team2 = 0;
    saveMemory();
}

void win(void) {
    if (score.team1 == score.team2) return;
    if (score.team1 > score.team2) score.win1++;
    if (score.team2 > score.team1) score.win2++;
    score.team1 = score.team2 = 0;
    saveMemory();
}

void checkButtons(void) {
    button.status = onClick(BTN_UP1, up1)
            || onClick(BTN_UP2, up2)
            || onClick(BTN_DOWN1, down1)
            || onClick(BTN_DOWN2, down2)
            || onPressed(BTN_CHANGE, change, TIME_3s, clear)
            || onClick(BTN_WIN, win);

    if (button.status == BUTTON_STATUS_RELEASED)
        button.pressTime = 0;
}