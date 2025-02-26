#ifndef CUBELIGHTS_H
#define CUBELIGHTS_H

#include <NeoPixelBus.h>
#include <NeoPixelAnimator.h>

extern RgbColor red,green, blue, yellow, cyan, magenta, orange,pink,lime,turquoise,violet,black,white;
extern NeoPixelBus<NeoGrbFeature, NeoEsp8266Uart1800KbpsMethod> strip;
extern uint8_t colorSaturation;

void MclSetup();
void allWhite();
void setLight(char direction, int ledNum, RgbColor color);
void setBrightness(uint8_t level);
//TODO overingenuired move functions
//ESPUI callbacks

#endif
