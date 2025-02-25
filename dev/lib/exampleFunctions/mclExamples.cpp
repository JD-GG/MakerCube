#include <mclExamples.h>

void fullSideOneColor(int delayVar){
    for(int i = 0;i<9;i++)
        setLight('N', i, green);
    strip.ClearTo(black);
    delay(delayVar);
    for(int i = 0;i<9;i++)
        setLight('O', i, red);
    strip.ClearTo(black);
    delay(delayVar);
    for(int i = 0;i<9;i++)
        setLight('S', i, cyan);
    strip.ClearTo(black);
    delay(delayVar);
    for(int i = 0;i<9;i++)
        setLight('W', i, violet);
    strip.ClearTo(black);
    delay(delayVar);
}

void alunFunc(){
    RgbColor colors[] = { red, blue, green, yellow, cyan, magenta, orange, pink, lime, turquoise, violet, white, black };

    int numColors = sizeof(colors) / sizeof(colors[0]); // Anzahl der Farben

    for (int i = 0; i < (numColors-1); i++) { 
        for (int j = 0; j < 36; j++) { // LEDs nacheinander leuchten lassen
            //clear(); // Vorherige LEDs ausschalten
            if(j%2==0)
                strip.SetPixelColor(j, colors[i]); 
            else
                strip.SetPixelColor(j, colors[i+1]); 
        }
        strip.Show();
        delay(2000);
        
    }
}
