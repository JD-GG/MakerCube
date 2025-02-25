#include <cubeLights.h>
#include <ESPUI.h>
//PlatformIO has a quirk where if you don't include a library in the main source file, it's sub-dependencies are not found correctly.

RgbColor colors[] = { red, blue, green, yellow, cyan, magenta, 
                        orange, pink, lime, turquoise, violet, 
                        white, black };
void setup(){
    MclSetup();
    char dir[] = {'N','S','W','O'};

    for(int k = 0;k<4;k++){
    }
}

void loop() {
    for(int i = 0;i<9;i++)
        setLight('N', i, green);
    strip.ClearTo(black);
    delay(2000);
    for(int i = 0;i<9;i++)
        setLight('O', i, red);
    strip.ClearTo(black);
    delay(2000);
    for(int i = 0;i<9;i++)
        setLight('S', i, cyan);
    strip.ClearTo(black);
    delay(2000);
    for(int i = 0;i<9;i++)
        setLight('W', i, violet);
    strip.ClearTo(black);
    delay(2000);
}
