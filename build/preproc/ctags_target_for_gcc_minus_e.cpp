# 1 "/home/blues/Documents/Code/Neopixel-Length-Finder/Neopixel-Length-Finder.ino"
# 2 "/home/blues/Documents/Code/Neopixel-Length-Finder/Neopixel-Length-Finder.ino" 2

//Pin connected to neopixel data in


//Pin connected to neopixel data out
const byte LED_IN = (int)3;
volatile byte state = 0x0;

//Very large baloney value to make the code run (cause the whole point is that we dont know how big the strip is yet)


//Strip object setup:
Adafruit_NeoPixel strip(9, 6, ((1 << 6) | (1 << 4) | (0 << 2) | (2)) /*|< Transmit as G,R,B*/ + 0x0000 /*|< 800 KHz data transmission*/);
void setup()
{
    strip.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
    strip.show(); // Turn OFF all pixels ASAP
    strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)

    pinMode(LED_IN, 0x0);
    attachInterrupt(((LED_IN) == 2 ? 0 : ((LED_IN) == 3 ? 1 : -1)), done, 3);

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
    for(int i=0; i<=9; i++)
    {
        //light the next LED on the string
        nextLed(i);
        if(state == 0x1)
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
