#ifndef CUBELIGHTS_H
#define CUBELIGHTS_H

#include <NeoPixelBus.h>
#include <NeoPixelAnimator.h>

extern RgbColor red,green, blue, yellow, cyan, magenta, orange,pink,lime,turquoise,violet,black,white;
extern NeoPixelBus<NeoGrbFeature, NeoEsp8266Uart1800KbpsMethod> strip;
extern uint8_t colorSaturation;

void MclSetup();
void setAll(RgbColor color);
void setLight(char direction, int ledNum, RgbColor color);
RgbColor getLight(char direction, int ledNum);
//void setBrightness(uint8_t level); Maybe just not do that
//TODO overingenuired move functions
//ESPUI callbacks
class Player{
    private:
        char name;
        int side, ledNum;
        RgbColor color;
        void decrementSide();
        void incrementSide();
        void drawPLayer();
    public:
        Player(char playerName, int side, int ledNum, RgbColor color);
        void moveRight();
        void moveLeft();
        void moveUp();
        void moveDown();
        int getSide(){
            return side;
        }
        int getLed(){
            return ledNum;
        }
};

#endif
