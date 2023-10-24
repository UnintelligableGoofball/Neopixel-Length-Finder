#include <Adafruit_NeoPixel.h>

//Pin connected to neopixel data in
#define LED_OUT 6

//Pin connected to neopixel data out
#define LED_IN 9

//Very large baloney value to make the code run (cause the whole point is that we dont know how big the strip is yet)
#define LED_COUNT 500

//Strip object setup:
Adafruit_NeoPixel strip(LED_COUNT, LED_OUT, NEO_GRB + NEO_KHZ800);
void setup()
{
    strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
    strip.show();            // Turn OFF all pixels ASAP
    strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)

    pinMode(LED_IN, INPUT);

    Serial.begin(9600);
}

void loop()
{
    Serial.println(length());
    return;
}

int length()
{
    for(int i=0; i<LED_COUNT; i++)
    {
        nextLed(i);
        if(digitalRead(LED_IN == HIGH))
        {
            return(i-1);
            Serial.print(i);
        }
    }
}

void nextLed(int i)
{
    strip.setPixelColor(i, strip.Color(100, 0, 150));
    strip.show();
}

