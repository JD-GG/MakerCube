#include <NeoPixelBus.h>
#include <NeoPixelAnimator.h>

#define NUMPIXELS 3
#define colorSaturation 128
const uint16_t PixelCount= NUMPIXELS ;
uint8_t leds[PixelCount];
const uint8_t PixelPin = 2;
bool doAnimation = false;

RgbColor red(colorSaturation, 0, 0);
RgbColor green(0, colorSaturation, 0);
RgbColor blue(0, 0, colorSaturation);
RgbColor white(colorSaturation);
RgbColor black(0,0,0);

#define DELAYVAL 500

NeoPixelBus<NeoGrbFeature, NeoEsp8266Dma800KbpsMethod> strip(PixelCount,PixelPin);

void setup(){
  strip.Begin();
  strip.Show();
}

void clear(){
  for(int i = 0; i<NUMPIXELS; i++){
  strip.SetPixelColor(i, black); 
  }
  strip.Show(); 
}

void loop() {
  clear();

  for(int i=0; i<NUMPIXELS; i++) {

    strip.SetPixelColor(i, red);
    strip.Show();
    delay(DELAYVAL);
  }
}
