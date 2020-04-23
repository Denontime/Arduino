#include <Adafruit_NeoPixel.h>
#define PIN      6  // what pin is this plugged into?
#define N_LEDS 30    // how many pixels are in the strip?

// this is our neopixel strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);


// this is the sensor poin
int sensePin = A2;

// this is the status
int sensorStatus;

void setPixel(int LEDNumber,int Red,int Green,int Blue)
{
  int i;
  for(i=0;i<LEDNumber-1;i++)
  {
      strip.setPixelColor(i, strip.Color(Red,Green,Blue));
  }
  
}

// run setup once
void setup() 
{
  pinMode(sensePin,INPUT); //  this is for squeezing
 // put your setup code here, to run once:
  // we are going to use this strip
  strip.begin();

  // turn off the strip
  strip.show();
  
  setPixel(30,int 255,int 255,int 255);
  
  strip.show();

  delay(100);

  setPixel(30,int 0,int 0,int 0);
  
  strip.show();

  delay(10);

  
}

// run loop forever
void loop() 
{
  sensorStatus = analogRead(sensePin); // get run this sense

  if(sensorStatus > 20 ) // if the sensor pressed
  {
  setPixel(30,int 255,int 255,int 255);
  // now that we have defined all the pixels, turn it on
  strip.show();
    delay(5000); // wait five sencond
  setPixel(30,int 0,int 0,int 0);
  // now that we have defined all the pixels, turn it on
  strip.show();
  delay(0);  // don not wait
  }
}
