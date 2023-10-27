#include <Adafruit_NeoPixel.h>

//Pin connected to neopixel data in
#define LED_OUT 6

//Pin connected to neopixel data out
const byte LED_IN = (int)3;
volatile byte state = LOW;

//Very large baloney value to make the code run (cause the whole point is that we dont know how big the strip is yet)
#define LED_COUNT 9

//Strip object setup:
Adafruit_NeoPixel strip(LED_COUNT, LED_OUT, NEO_GRB + NEO_KHZ800);
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
    state = !state;
}

//Light each consecutive LED until some data slips out the other end
int length()
{
    for(int i=0; i<=LED_COUNT; i++)
    {
        //light the next LED on the string
        nextLed(i);
        if(state == HIGH)
        {
            Serial.println(i);
            return(i+1);
        }
        Serial.println(i);
        delay(100);
    }
}

//Light i LED
void nextLed(int i)
{
    strip.setPixelColor(i, strip.Color(100, 0, 150));
    strip.show();
}

