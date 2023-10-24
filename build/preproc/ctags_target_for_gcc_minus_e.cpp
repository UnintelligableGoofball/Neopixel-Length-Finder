# 1 "/home/blues/Documents/Code/Neopixel-Length-Finder/Neopixel-Length-Finder.ino"
# 2 "/home/blues/Documents/Code/Neopixel-Length-Finder/Neopixel-Length-Finder.ino" 2

//Pin connected to neopixel data in


//Pin connected to neopixel data out


//Very large baloney value to make the code run (cause the whole point is that we dont know how big the strip is yet)


//Strip object setup:
Adafruit_NeoPixel strip(500, 6, ((1 << 6) | (1 << 4) | (0 << 2) | (2)) /*|< Transmit as G,R,B*/ + 0x0000 /*|< 800 KHz data transmission*/);
void setup()
{
    strip.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
    strip.show(); // Turn OFF all pixels ASAP
    strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)

    pinMode(9, 0x0);

    Serial.begin(9600);
}

void loop()
{
    Serial.println(length());
    return;
}

int length()
{
    for(int i=0; i<500; i++)
    {
        nextLed(i);
        if(digitalRead(9 == 0x1))
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
