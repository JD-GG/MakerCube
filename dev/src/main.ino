#include <cubeLights.h>
#include <ESPUI.h>
//PlatformIO has a quirk where if you don't include a library in the main source file, it's sub-dependencies are not found correctly.

void setup(){
    MclSetup();
    setLight('W', 7, green);
    setLight(3, 5, cyan);
    setLight(3, 4, pink);
}

void loop() {
}

void callbackUp(){
    
}