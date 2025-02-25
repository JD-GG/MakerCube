#ifndef CUBELIGHTS_H
#define CUBELIGHTS_H

#include <NeoPixelBus.h>
#include <NeoPixelAnimator.h>

#define colorSaturation 255
const uint16_t PixelCount= 36;
NeoPixelBus<NeoGrbFeature, NeoEsp8266Uart1800KbpsMethod> strip(PixelCount,2);
void MclSetup();
void allWhite();
int calcLedNord(int gridNum);
int calcLedOst(int gridNum);
int calcLedSouth(int gridNum);
int calcLedWest(int gridNum);
void setLight(char direction, int ledNum, RgbColor color);
void alunFunc();
RgbColor red(colorSaturation, 0, 0);
RgbColor green(0, colorSaturation, 0);
RgbColor blue(0, 0, colorSaturation);
RgbColor yellow(colorSaturation, colorSaturation, 0);    // Gelb (Rot + Grün)
RgbColor cyan(0, colorSaturation, colorSaturation);      // Cyan (Grün + Blau)
RgbColor magenta(colorSaturation, 0, colorSaturation);   // Magenta (Rot + Blau)
RgbColor orange(colorSaturation, colorSaturation / 2, 0); // Orange (Mehr Rot als Grün)
RgbColor pink(colorSaturation, colorSaturation / 3, colorSaturation / 2); // Pink (Rot + wenig Blau)
RgbColor lime(colorSaturation / 2, colorSaturation, 0);  // Limettengrün (Mehr Grün als Rot)
RgbColor turquoise(0, colorSaturation / 2, colorSaturation); // Türkis (Mehr Blau als Grün)
RgbColor violet(colorSaturation / 2, 0, colorSaturation); // Violett (Mehr Blau als Rot)
RgbColor white(colorSaturation);
RgbColor black(0,0,0);

#endif