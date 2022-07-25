#ifndef LED_h
#define LED_h

class operator1
{
  public: //define class as public
  operator1(); //compile class
  void SETUP(); 
  void TICK(); //loop this func
  void CHECKSTATE();
  void loadpinmode();
  void lasermode_1(int a, int b, int c);
  void lasermode_2(float delayTime);
  void lasermode_3(float delayTime);
  void lasermode_4();
  void walking(); //not tested
  void StrobeRainbow(); //not tested
  void smoke(int dly); //set smoke machine relay with delay interval
  int value(); //local var
};

extern operator1 LED; //LED definition //what you call from main script

#endif
