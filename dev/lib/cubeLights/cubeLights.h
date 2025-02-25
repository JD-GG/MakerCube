#ifndef CUBELIGHTS_H
#define CUBELIGHTS_H

#include <NeoPixelBus.h>
#include <NeoPixelAnimator.h>


class C {
public:
    const int colorSaturation = 255;
    static RgbColor red(colorSaturation, 0, 0);
    static RgbColor green(0, colorSaturation, 0);
    static RgbColor blue(0, 0, colorSaturation);
    static RgbColor yellow(colorSaturation, colorSaturation, 0);    // Gelb (Rot + Grün)
    static RgbColor cyan(0, colorSaturation, colorSaturation);      // Cyan (Grün + Blau)
    static RgbColor magenta(colorSaturation, 0, colorSaturation);   // Magenta (Rot + Blau)
    static RgbColor orange(colorSaturation, colorSaturation / 2, 0); // Orange (Mehr Rot als Grün)
    static RgbColor pink(colorSaturation, colorSaturation / 3, colorSaturation / 2); // Pink (Rot + wenig Blau)
    static RgbColor lime(colorSaturation / 2, colorSaturation, 0);  // Limettengrün (Mehr Grün als Rot)
    static RgbColor turquoise(0, colorSaturation / 2, colorSaturation); // Türkis (Mehr Blau als Grün)
    static RgbColor violet(colorSaturation / 2, 0, colorSaturation); // Violett (Mehr Blau als Rot)
    static RgbColor black(0,0,0);
    static RgbColor white(colorSaturation);
}

void MclSetup();
void allWhite();
int calcLedNord(int gridNum);
int calcLedOst(int gridNum);
int calcLedSouth(int gridNum);
int calcLedWest(int gridNum);
void setLight(char direction, int ledNum, RgbColor color);
void alunFunc();


#endif
