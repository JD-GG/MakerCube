#include <NeoPixelBus.h>
#include <NeoPixelAnimator.h>
#include <ESPUI.h>
//PlatformIO has a quirk where if you don't include a library in the main source file, it's sub-dependencies are not found correctly.

#define colorSaturation 128
const uint16_t PixelCount= 36;
uint8_t leds[PixelCount];
const uint8_t PixelPin = 2;
bool doAnimation = false;

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

#define DELAYVAL 2000

NeoPixelBus<NeoGrbFeature, NeoEsp8266Uart1800KbpsMethod> strip(PixelCount,PixelPin);

void setup(){
  strip.Begin();
  strip.Show();
}

void clear(){
  for(int i = 0; i<PixelCount; i++){
  strip.SetPixelColor(i, black); 
  }
  strip.Show(); 
}

void loop() {
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
    delay(DELAYVAL);
  }
}
