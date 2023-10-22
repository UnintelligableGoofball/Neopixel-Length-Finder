#include <Adafruit_NeoPixel.h>

//Pin connected to neopixel data in
#define LED_OUT 6

//Pin connected to neopixel data out
#define LED_IN 9

//Very large baloney value to make the code run (cause the whole point is that we dont know how big the strip is yet)
#define LED_COUNT 500

//Strip object setup:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
void setup()
{
	
}

void loop()
{
	
}
