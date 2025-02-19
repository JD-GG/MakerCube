# MakerCube
 
## What is MakerCube?

### The sides of the Cube:

The sides of the Cube contain, similar to a rubik's cube a 3x3 field, with each a LED in it. 
In total there are 36 LEDs which can be controlled by:

### the top of the Cube:

The top of the Cube contains various input possiblitys, which can be used to control the LEDs on the side. As input you can use
- button
- joystick
- slider
- encoder / potentiometer
- switch
And you can also control a 7 Segment Display, which will be placed on the topside.

On the top will be a dataport, which can be used to upload sketches from the Arduino IDE to the esp.

### the bottom side of the Cube:

On the bottom is a switch, to power the esp and the LEDs and a loading port, to charge the battery.

## Hardware

### esp8266

As a microcontroller we use a esp8226. 
To access it you need the CH340 drivers. 
To controller / programm it in the Arduino IDE you need to add a additional board manager. You do this with adding "http://arduino.esp8266.com/stable/package\_esp8266com\_index.json" into File -> Preferences -> Additional boards manager URLs.
As board you have to choose "LOLIN(WEMOS) D1 R2 & mini".

### neopixels

As LEDs we use BTF-LIGHTING WS2812 WS2812B LED stripes.
To control the LEDs you need to install the "NeoPixelBus by Makuna", which is a fork from the adafruit neopixels repository on github.
Default code to display colors:

```cpp
#include <NeoPixelBus.h>
#include <NeoPixelAnimator.h>

#define colorSaturation 128
const uint16_t PixelCount= 3;
uint8_t leds[PixelCount];
const uint8_t PixelPin = 2;
bool doAnimation = false;

RgbColor red(colorSaturation, 0, 0);
RgbColor green(0, colorSaturation, 0);
RgbColor blue(0, 0, colorSaturation);
RgbColor black(0,0,0);

#define DELAYVAL 500

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
  clear();

  for(int i=0; i<PixelCount; i++) {

    strip.SetPixelColor(i, red);
    strip.Show();
    delay(DELAYVAL);
  }
}
```

### battery

As a battery we use a small lithium ionen battery which will power the esp and the LEDs.

## Whats the plan with the MakerCube?

We want to go into schools and teach the pupils, how to program the Cube, how to use the inputs and how to control the LEDs with these inputs.
Therfore we will design some example projects for diffrent skillgroups, which can be done by them. But in the best case the pupils have their own ideas to bring to the cube.

To make it easier for the pupils to control the cube we will write a library to remove the boilerplate code and deliver more clear functions on controlling the LEDs.
