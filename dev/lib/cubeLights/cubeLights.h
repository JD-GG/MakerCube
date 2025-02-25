#ifndef CUBELIGHTS_H
#define CUBELIGHTS_H

#include <NeoPixelBus.h>
#include <NeoPixelAnimator.h>

#define colorSaturation 255

void MclSetup();
void allWhite();
int calcLedNord(int gridNum);
int calcLedOst(int gridNum);
int calcLedSouth(int gridNum);
int calcLedWest(int gridNum);
void setLight(char direction, int ledNum, RgbColor color);
void alunFunc();


#endif