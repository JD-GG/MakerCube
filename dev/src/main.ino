#include <cubeLights.h>
#include <ESPUI.h>
//PlatformIO has a quirk where if you don't include a library in the main source file, it's sub-dependencies are not found correctly.

void setup(){
    MclSetup();
}

void loop() {
    alunFunc();
}
