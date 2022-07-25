//#include <MemoryFree.h>
#include <EEPROM.h>
#include "LED.h"

#define PIN_LED 13    // вывод светодиода
#define led_pin2 53
String inString;
int current = 0;
// Настройка
void setup() {
  // Инициализация портов и выходов
  Serial.begin(115200);
  Serial3.begin(115200);
  pinMode(PIN_LED, OUTPUT);
  pinMode(51,OUTPUT);
  digitalWrite(PIN_LED, LOW);
   digitalWrite(51, LOW);
    Serial.print("ATMEGA2566 Setup");
LED.SETUP();
}

// Выполнение
void loop() {
 // LED.lasermode_1(100,22,44); //delay , startpin, stoppin //loop through
 //LED.lasermode_2(500); //delay on off based on groups
 // LED.lasermode_3(50); //delay on off based on Random
// LED.lasermode_4(); //off command
//LED.walking(); 
//LED.StrobeRainbow();

  if(current == 0) //off
  {
     LED.lasermode_4();
  //    return;
  }
  else if(current == 1) //on with loop through
  {
  LED.lasermode_1(100,22,44);
 //  return;
  }
   if(current ==2) //smoke on
  {
    LED.smoke(100); //High 100 Low = 100x 10 = 1000 (1 sec)
     //continue;
  }
 else if(current == 3)
  {
    LED.lasermode_3(50);
  //digitalWrite(13, LOW); //simple overide of Smoke on
  // return;
  }
}


// Проверка события на порту Serial3
void serialEvent3() {
  while (Serial3.available()) 
  {
    // Чтение данных из порта Serial3
    char inChar = Serial3.read();
    // Вывод прочитанных данных в порт Serial
    Serial.write(inChar);
    // Поиск команды в полученных данных (команда должна быть в квадратных скобках)
    inString += inChar;
    if (inChar == ']') 
    {
      if (inString.indexOf("[ON]")>0) {
        //digitalWrite(PIN_LED, HIGH);
        current = 1;
       // LED.lasermode_1(100,22,44); //delay , startpin, stoppin //loop through
      }
      else if (inString.indexOf("[OFF]")>0) {
       // digitalWrite(PIN_LED, LOW);
         //off command
         current = 0;
      }
         if (inString.indexOf("[SMOKEON]")>0) {
        //digitalWrite(led_pin2, HIGH);
         current = 2;
        // continue;
        }
        else if (inString.indexOf("[SMOKEOFF]")>0) {
       // digitalWrite(led_pin2, LOW);
       //LED.nosmoke;
       current = 3;
       Serial.println("Turn off smoke!");  
        } 
      else
      {
      //  Serial.println("Wrong command");
        inString = "";
      }
       inString = "";
    }
  }
}
