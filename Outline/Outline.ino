//define addressable LED
#include <Adafruit_NeoPixel.h>
#define PIN 6
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800); 


//define global variables for LED colour & brightness
int red;
int green;
int blue;
int white;
int brightness = 100;


//define interrupt button variables
const byte interruptPin = 2;
volatile byte state = LOW;
int programme_counter = 1;


//encoder 1 input setup
 int val1; 
 int encoder0PinA = 3;
 int encoder0PinB = 4;
 int encoder0Pos = 0;
 int encoder0PinALast = LOW;
 int n = LOW;

//encoder 2 input setup
 int val2; 
 int encoder1PinA = 3;
 int encoder1PinB = 4;
 int encoder1Pos = 0;
 int encoder1PinALast = LOW;
 int m = LOW;


void setup() {
//LED pixel setup
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(brightness);
  
//encoder 1 setup (brightness)
   pinMode (encoder0PinA,INPUT);
   pinMode (encoder0PinB,INPUT);

//encoder 2 setup (selector)
   pinMode (encoder1PinA,INPUT);
   pinMode (encoder1PinB,INPUT);

//interrupt setup
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), programme_interrupt, CHANGE);

}


void loop() {

poll_brightness();
poll_selector();

if (programme_counter = 1) {
  programme1();
}
if (programme_counter = 2) {
  programme2();
}
if (programme_counter = 3) {
  programme3();
}
if (programme_counter = 4) {
  programme4();
}
if (programme_counter = 5) {
  programme5();
}
if (programme_counter = 6) {
  programme6();
}

}


void programme_interrupt() {
  //normal slightly yellow light (classic carnival lights)
  programme_counter += 1;


}

void poll_brightness() {

 /* Read Quadrature Encoder
  * Connect Encoder to Pins encoder0PinA, encoder0PinB, and +5V.
  *
  * Sketch by max wolf / www.meso.net
  * v. 0.1 - very basic functions - mw 20061220
  *
  */  

   n = digitalRead(encoder0PinA);
   if ((encoder0PinALast == LOW) && (n == HIGH)) {
     if (digitalRead(encoder0PinB) == LOW) {
       encoder0Pos--;
     } else {
       encoder0Pos++;
     }
   } 
   encoder0PinALast = n;
  
}

void poll_selector() {

 /* Read Quadrature Encoder
  * Connect Encoder to Pins encoder0PinA, encoder0PinB, and +5V.
  *
  * Sketch by max wolf / www.meso.net
  * v. 0.1 - very basic functions - mw 20061220
  *
  */  

   n = digitalRead(encoder1PinA);
   if ((encoder0PinALast == LOW) && (m == HIGH)) {
     if (digitalRead(encoder1PinB) == LOW) {
       encoder1Pos--;
     } else {
       encoder1Pos++;
     }
   } 
   encoder1PinALast = m;
  
}


void programme1() {
  //normal slightly yellow light (classic carnival lights)
  //use brightness multiplier
  
  strip.setPixelColor(n, red, green, blue, white);
  
}

void programme2() {
  //colour change programme
  //use encoder 2 to cycle through colour
  //use brightness multiplier

  
}

void programme3() {
  //temperature sensor programme
  //use brightness multiplier
  //encoder 2 does nothing
  //15 and below = blue
  //>15 to 18 = green
  //>18 to 21 = yellow
  //>21 to 24 = orange
  //>24 = red


  
}

void programme4() {
  //automatic colour change 
  //use brightness multiplier
  //use encoder 2 to change speed of change


  
}

void programme5() {
  //crazy change - assign random colour value to random led's. 
  //use brightness multiplier
  //use encoder 2 to change speed of change
  

  
}

void programme6() {
  //random change all colours
  //use brightness multiplier
  //use encoder 2 - when turned change to random colour


  
}
