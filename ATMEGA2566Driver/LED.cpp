//https://www.youtube.com/watch?v=2pxYEwaMtaI
#include "Arduino.h"
#include "LED.h"

//WS2812B includes and defines https://github.com/Freenove/Freenove_WS2812B_RGBLED_Controller
#include "Freenove_WS2812B_RGBLED_Controller.h"
#define I2C_ADDRESS  0x20
#define LEDS_COUNT   10

const uint8_t LED_global = 53; //global variables for class

int all_laser[] = {22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43}; //orange

//define lasers and group them
int laserpin_low[] = {22, 25, 28, 31, 34, 37, 40, 43}; //orange

int laserpin_mid[] = {23, 26, 29, 32, 35, 38, 41, 44}; //green

int laserpin_high[] = {24, 27, 30, 33, 36, 39, 42, 45}; //blue

int laserpin_1[] = {22, 23, 24};
int laserpin_2[] = {25, 26, 27};
int laserpin_3[] = {28, 29, 30};
int laserpin_4[] = {31, 32, 33};
int laserpin_5[] = {34, 35, 36};
int laserpin_6[] = {37, 38, 39};
int laserpin_7[] = {40, 41, 42};
int laserpin_8[] = {43, 44, 45};

const int smokePin = 13;

operator1::operator1()
{
}

void operator1::SETUP()
{
  //implementation
  Serial.println(" Loading LED Functions");
  loadpinmode();
}
void operator1::TICK()
{
  //implementation
}

int operator1::value()
{
  //implementation
  int var = 51;
  return(var);
}

  void operator1::loadpinmode()
  {
     pinMode(51, OUTPUT);
  
    pinMode(laserpin_low[0], OUTPUT);
    pinMode(laserpin_low[1], OUTPUT);
    pinMode(laserpin_low[2], OUTPUT);
    pinMode(laserpin_low[3], OUTPUT);
    pinMode(laserpin_low[4], OUTPUT);
    pinMode(laserpin_low[5], OUTPUT);
    pinMode(laserpin_low[6], OUTPUT);
    pinMode(laserpin_low[7], OUTPUT);
  
    pinMode(laserpin_mid[0], OUTPUT);
    pinMode(laserpin_mid[1], OUTPUT);
    pinMode(laserpin_mid[2], OUTPUT);
    pinMode(laserpin_mid[3], OUTPUT);
    pinMode(laserpin_mid[4], OUTPUT);
    pinMode(laserpin_mid[5], OUTPUT);
    pinMode(laserpin_mid[6], OUTPUT);
    pinMode(laserpin_mid[7], OUTPUT);
  
    pinMode(laserpin_high[0], OUTPUT);
    pinMode(laserpin_high[1], OUTPUT);
    pinMode(laserpin_high[2], OUTPUT);
    pinMode(laserpin_high[3], OUTPUT);
    pinMode(laserpin_high[4], OUTPUT);
    pinMode(laserpin_high[5], OUTPUT);
    pinMode(laserpin_high[6], OUTPUT);
    pinMode(laserpin_high[7], OUTPUT);
  
    Serial.println(" Pinmode assigned");
  }
  
void operator1::lasermode_1(int delayint,int pinstart, int pinstop) {
  //loop through all lasers
  for (int i = pinstart; i < pinstop; i++) {
    digitalWrite(i, HIGH);
    delay(delayint); //1 sec
    digitalWrite(i, LOW);
  }
}
void operator1::lasermode_2(float delayTime) {
  //loop through all sets of lasers
  digitalWrite(22, HIGH);
  digitalWrite(23, HIGH);
  digitalWrite(24, HIGH);
  delay(delayTime);
  digitalWrite(22, LOW);
  digitalWrite(23, LOW);
  digitalWrite(24, LOW);
  delay(delayTime);
  digitalWrite(25, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH);
  delay(delayTime);
  digitalWrite(25, LOW);
  digitalWrite(26, LOW);
  digitalWrite(27, LOW);
  delay(delayTime);
  digitalWrite(28, HIGH);
  digitalWrite(29, HIGH);
  digitalWrite(30, HIGH);
  delay(delayTime);
  digitalWrite(28, LOW);
  digitalWrite(29, LOW);
  digitalWrite(30, LOW);
  delay(delayTime);
  digitalWrite(31, HIGH);
  digitalWrite(32, HIGH);
  digitalWrite(33, HIGH);
  delay(delayTime);
  digitalWrite(31, LOW);
  digitalWrite(32, LOW);
  digitalWrite(33, LOW);
  delay(delayTime);
  digitalWrite(34, HIGH);
  digitalWrite(35, HIGH);
  digitalWrite(36, HIGH);
  delay(delayTime);
  digitalWrite(34, LOW);
  digitalWrite(35, LOW);
  digitalWrite(36, LOW);
  delay(delayTime);
  digitalWrite(37, HIGH);
  digitalWrite(38, HIGH);
  digitalWrite(39, HIGH);
  delay(delayTime);
  digitalWrite(37, LOW);
  digitalWrite(38, LOW);
  digitalWrite(39, LOW);
  delay(delayTime);
  digitalWrite(40, HIGH);
  digitalWrite(41, HIGH);
  digitalWrite(42, HIGH);
  delay(delayTime);
  digitalWrite(40, LOW);
  digitalWrite(41, LOW);
  digitalWrite(42, LOW);
  delay(delayTime);
  digitalWrite(43, HIGH);
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  delay(delayTime);
  digitalWrite(43, LOW);
  digitalWrite(44, LOW);
  digitalWrite(45, LOW);
  delay(delayTime);
}

void operator1::lasermode_3(float delayTime) {
  //laser random
  digitalWrite(random(22, 43), HIGH);
  delay(delayTime);
  for (int i = 22; i < 43; i++) {
    digitalWrite(i, LOW);
  }
}

void operator1::lasermode_4() {
  //all lasers off
  for (int i = 22; i < 43; i++) {
    digitalWrite(i, LOW);
  }
}



float ledWalk;
float ledWalkSpeed = 1;
Freenove_WS2812B_Controller strip(I2C_ADDRESS, LEDS_COUNT, TYPE_GRB);
void operator1::walking() {
//  while (!strip.begin());
  ledWalk += ledWalkSpeed;
  if (ledWalk > LEDS_COUNT) {
    ledWalkSpeed = -ledWalkSpeed;
  }
  if (ledWalk < 1) {
    ledWalkSpeed = -ledWalkSpeed;
  }

  strip.setLedColorData(ledWalk, 255, 0, 0);
  strip.show();
  delay(100);
  strip.setLedColorData(ledWalk, 0, 255, 0);
  strip.show();
  delay(100);
}

float strobeColor;
float strobeColorSpeed = 1;
void operator1::StrobeRainbow() {
  strobeColor += strobeColorSpeed;
  if (strobeColor > 255) {
    strobeColorSpeed = -strobeColorSpeed;
  }
  if (strobeColor < 0) {
    strobeColorSpeed = -strobeColorSpeed;
  }

  for (int i = 0; i < LEDS_COUNT; i++) {
    strip.setLedColorData(i, strip.Wheel(strobeColor));
  }
  strip.show();
  delay(100);
  for (int i = 0; i < LEDS_COUNT; i++) {
    strip.setLedColor(i, 0, 0, 0);
  }
  strip.show();
  delay(100);
}

void operator1::smoke(int delaynum) {
  digitalWrite(smokePin, HIGH);
  delay(delaynum);
  digitalWrite(smokePin, LOW);
  delay(delaynum*10);
}
operator1 led = operator1(); //for compiling
