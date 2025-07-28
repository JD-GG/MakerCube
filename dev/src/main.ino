#include "secrets.h"
#include <cubeLights.h>
#include <mclExamples.h>
#include <ESPUI.h>
//PlatformIO has a quirk where if you don't include a library in the main source file, it's sub-dependencies are not found correctly.

Player a = Player('a', 0, 0, pink);
Player b = Player('a', 0, 4, cyan);
Player c = Player('a', 0, 8, red);//This is copy initialization
Player d('a', 0, 0, cyan);//And this is called direct initialization. Both work in cpp
RgbColor pureWhite = RgbColor(255,255,255);
RgbColor myColor(1,1,1);

void generalCallback(Control* sender, int type) {
    Serial.printf("Type: %d\nID: %d\n", type, sender->id);
}
void buttonCallback(Control* sender, int type)
{
    switch (type)
    {
    case B_DOWN:
        //Serial.println("Button DOWN");
        a.moveLeft();
        b.moveLeft();
        c.moveLeft();
        d.moveLeft();
        break;

    case B_UP:
        //Serial.println("Button UP");
        break;
    }
}

void setup(){
    // To add elements to a non tabbed GUI use the following syntax. Every attribute can be changed
    // ESPUI.button("Title", &callBackFunction, ControlColor::Color, "Inscription");
    ESPUI.button("Push Button", &buttonCallback, ControlColor::Peterriver, "Nothing");
    MclSetup(true); // Has to be true if ESPUI is being used
}

void loop() {
    MclLoop();
}