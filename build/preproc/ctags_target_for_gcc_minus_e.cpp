# 1 "/home/blues/Documents/Code/Neopixel-Length-Finder/Neopixel-Length-Finder.ino"
# 2 "/home/blues/Documents/Code/Neopixel-Length-Finder/Neopixel-Length-Finder.ino" 2

//Pin connected to neopixel data in


//Pin connected to neopixel data out
const byte LED_IN = (int)3;

//Variable to keep track of how many times the interrupt has been triggered
int state = 0;

//Strip object setup:
Adafruit_NeoPixel strip(500, 6, ((3 << 6) | (1 << 4) | (0 << 2) | (2)) /*|< Transmit as G,R,B,W*/ + 0x0000 /*|< 800 KHz data transmission*/);
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
