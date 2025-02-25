#include <cubeLights.h>

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
const uint16_t PixelCount= 36;
NeoPixelBus<NeoGrbFeature, NeoEsp8266Uart1800KbpsMethod> strip(PixelCount,2);

void MclSetup() {
    //pinMode(_pin, OUTPUT);??
    strip.Begin();
}

void allWhite() {
    strip.ClearTo(white);
}

int calcLedNord(int gridNum){
    //Maybe start counting with 1 idk
    int result = 0;
    switch(gridNum){
        case 0: break;
        case 1: result = 11; break;
        case 2: result = 10; break;
        case 3: result = 23; break;
        case 4: result = 22; break;
        case 5: result = 21; break;
        case 6: result = 34; break;
        case 7: result = 33; break;
        case 8: result = 32; break;
    }
    return result;
}

int calcLedOst(int gridNum){
    if(gridNum == 8)
        return 35;
    else
        return calcLedSouth(gridNum) - 3;
}

int calcLedSouth(int gridNum){
    return calcLedWest(gridNum) - 3;
}

int calcLedWest(int gridNum){
    int result = 0;
    switch(gridNum){
        case 0: result = 9; break;
        case 1: result = 8; break;
        case 2: result = 7; break;
        case 3: result = 20; break;
        case 4: result = 19; break;
        case 5: result = 18; break;
        case 6: result = 31; break;
        case 7: result = 30; break;
        case 8: result = 29; break;
    }
    return result;
}

void setLight(char direction, int ledNum, RgbColor color) {//Din A4 Dokumentation mit LED nummerierung
    int ledInArr = 0;
    switch(direction){
        case 'N': 
            ledInArr =  calcLedNord(ledNum);
            break;
        case 'O':
            ledInArr = calcLedOst(ledNum);
            break;
        case 'S':
            ledInArr = calcLedSouth(ledNum);
            break;
        case 'W':
            ledInArr = calcLedWest(ledNum);
            break;
    }
    strip.SetPixelColor(ledInArr, color); 
    strip.Show();
}

void alunFunc(){
    RgbColor colors[] = { red, blue, green, yellow, cyan, magenta, 
                        orange, pink, lime, turquoise, violet, 
                        white, black };

  int numColors = sizeof(colors) / sizeof(colors[0]); // Anzahl der Farben

  for (int i = 0; i < (numColors-1); i++) { 
    for (int j = 0; j < PixelCount; j++) { // LEDs nacheinander leuchten lassen
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