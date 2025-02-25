#ifndef CUBELIGHTS_H
#define CUBELIGHTS_H

#include <NeoPixelBus.h>
#include <NeoPixelAnimator.h>

extern RgbColor red,green, blue, yellow, cyan, magenta, orange,pink,lime,turquoise,violet,black,white;
extern NeoPixelBus<NeoGrbFeature, NeoEsp8266Uart1800KbpsMethod> strip;

void MclSetup();
void allWhite();
int calcLedNord(int gridNum);
int calcLedOst(int gridNum);
int calcLedSouth(int gridNum);
int calcLedWest(int gridNum);
void setLight(char direction, int ledNum, RgbColor color);
void alunFunc();
    
#endif
