#include "defines.h"

void updateMemory(char addr, char value) {
    char mem = EEPROM_READ(addr);
    if (mem == value) return;
    EEPROM_WRITE(addr, value);
}

void saveMemory(void) {
    updateMemory(0x00, (char) score.team1);
    updateMemory(0x01, (char) score.team2);
    updateMemory(0x02, score.win1);
    updateMemory(0x03, score.win2);
}

void loadMemory(void) {
    score.team1 = (signed char) EEPROM_READ(0x00);
    score.team2 = (signed char) EEPROM_READ(0x01);
    score.win1 = EEPROM_READ(0x02);
    score.win2 = EEPROM_READ(0x03);

    if ((char) score.team1 == 0xff)score.team1 = 0;
    if ((char) score.team2 == 0xff)score.team1 = 0;
    if (score.win1 == 0xff)score.win1 = 0;
    if (score.win2 == 0xff)score.win2 = 0;
}