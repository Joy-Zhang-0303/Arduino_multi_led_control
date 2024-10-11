#include <Arduino.h>
#include "led.hpp"

#define led_1 8
#define led_2 9
#define led_3 10
#define led_4 11
#define led_5 12



// Create led object
led led1;
led led2;
led led3;
led led4;
led led5;

void setup()
{
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);

  led1.setPortNum(led_1);
  led1.setFre(1);
  
  led2.setPortNum(led_2);
  led2.setFre(2);
  
  led3.setPortNum(led_3);
  led3.setFre(4);
  
  led4.setPortNum(led_4);
  led4.setFre(8);
  
  led5.setPortNum(led_5);
  led5.setFre(16);
  
}

void loop()
{
  // put your main code here, to run repeatedly:
  led1.blink();
  led2.blink();
  led3.blink();
  led4.blink();
  led5.blink();
}