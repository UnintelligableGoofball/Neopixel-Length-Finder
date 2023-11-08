#include <Arduino.h>
#line 1 "/home/blues/Documents/Code/Neopixel-Length-Finder/Neopixel-Length-Finder.ino"
#include <Adafruit_NeoPixel.h>

//Pin connected to neopixel data in
#define LED_OUT 6

//Pin connected to neopixel data out
const byte LED_IN = (int)3;

//Variable to keep track of how many times the interrupt has been triggered
int state = 0;

//Strip object setup:
Adafruit_NeoPixel strip(500, LED_OUT, NEO_GRBW + NEO_KHZ800);
#line 14 "/home/blues/Documents/Code/Neopixel-Length-Finder/Neopixel-Length-Finder.ino"
void setup();
#line 28 "/home/blues/Documents/Code/Neopixel-Length-Finder/Neopixel-Length-Finder.ino"
void loop();
#line 32 "/home/blues/Documents/Code/Neopixel-Length-Finder/Neopixel-Length-Finder.ino"
void done();
#line 39 "/home/blues/Documents/Code/Neopixel-Length-Finder/Neopixel-Length-Finder.ino"
int length();
#line 59 "/home/blues/Documents/Code/Neopixel-Length-Finder/Neopixel-Length-Finder.ino"
void nextLed(int i);
#line 14 "/home/blues/Documents/Code/Neopixel-Length-Finder/Neopixel-Length-Finder.ino"
void setup()
{
    strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
    strip.show();            // Turn OFF all pixels ASAP
    strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)

    pinMode(LED_IN, INPUT);
    attachInterrupt(digitalPinToInterrupt(LED_IN), done, RISING);

    Serial.begin(9600);

    Serial.println(length());
}

void loop()
{
}

void done() {
    state++;
    //Serial.print("state:");
    //Serial.println(state);
}

//Light each consecutive LED until some data slips out the other end
int length()
{
    for(int i=0; i<=300; i++)
    {
        
        if(state >= 3)
        {
            //Serial.println(i);
            return(i-1);
        }
        //Serial.println(i);
        //light the next LED on the string
        //Strip object setup:
        strip.updateLength(i);
        nextLed(i);
        delay(10);
    }
}

//Light i LED
void nextLed(int i)
{
    strip.setPixelColor(i, strip.Color(25, 0, 0));
    strip.show();
}


