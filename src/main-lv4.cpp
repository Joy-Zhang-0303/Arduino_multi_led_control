#include <Arduino.h>
#include "led.hpp"

#define led_1 8
#define led_2 9
#define led_3 10
#define led_4 11
#define led_5 12
#define led_6 13
#define sw 5

bool state = false;
int pushed_count = 0;

// Create led object
led led1;
led led2;
led led3;
led led4;
led led5;
led led6;

// Create disable all led function
void off_leds();
bool FLAG_RUN_ONCE = true;

void setup()
{
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);
  pinMode(led_6, OUTPUT);
  pinMode(sw, INPUT_PULLUP);

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

  led6.setPortNum(led_6);
  led6.setFre(32);
}

void loop()
{
  // Buttton Judgement
  if ((digitalRead(sw) == LOW) && state == false)
  {
    state = true;
    pushed_count++;
    FLAG_RUN_ONCE = true;
  }
  if (digitalRead(sw) == HIGH)
  {
    state = false;
  }

  switch (pushed_count % 12)
  {
  case 1:
    led1.blink();
    led2.disable();
    led3.disable();
    led4.disable();
    led5.disable();
    led6.disable();
    break;

  case 2:
    led1.disable();
    led2.blink();
    led3.disable();
    led4.disable();
    led5.disable();
    led6.disable();
    break;

  case 3:
    led1.disable();
    led2.disable();
    led3.blink();
    led4.disable();
    led5.disable();
    led6.disable();
    break;

  case 4:
    led1.disable();
    led2.disable();
    led3.disable();
    led4.blink();
    led5.disable();
    led6.disable();
    break;

  case 5:
    led1.disable();
    led2.disable();
    led3.disable();
    led4.disable();
    led5.blink();
    led6.disable();
    break;

  case 6:
    led1.disable();
    led2.disable();
    led3.disable();
    led4.disable();
    led5.disable();
    led6.blink();
    break;

  case 7:
    led1.blink();
    led2.disable();
    led3.disable();
    led4.disable();
    led5.disable();
    led6.disable();
    break;

  case 8:
    if (FLAG_RUN_ONCE)
    {
      off_leds();
      FLAG_RUN_ONCE = !FLAG_RUN_ONCE;
      // Serial.println("in case8 if");
    }
    led1.blink();
    led2.blink();
    led3.disable();
    led4.disable();
    led5.disable();
    led6.disable();
    break;

  case 9:
    if (FLAG_RUN_ONCE)
    {
      off_leds();
      FLAG_RUN_ONCE = !FLAG_RUN_ONCE;
    }
    led1.blink();
    led2.blink();
    led3.blink();
    led4.disable();
    led5.disable();
    led6.disable();
    break;

  case 10:
    if (FLAG_RUN_ONCE)
    {
      off_leds();
      FLAG_RUN_ONCE = !FLAG_RUN_ONCE;
    }
    led1.blink();
    led2.blink();
    led3.blink();
    led4.blink();
    led5.disable();
    led6.disable();
    break;

  case 11:
    if (FLAG_RUN_ONCE)
    {
      off_leds();
      FLAG_RUN_ONCE = !FLAG_RUN_ONCE;
    }
    led1.blink();
    led2.blink();
    led3.blink();
    led4.blink();
    led5.blink();
    led6.disable();
    break;

  case 0:
    if (FLAG_RUN_ONCE)
    {
      off_leds();
      FLAG_RUN_ONCE = !FLAG_RUN_ONCE;
    }
    if (pushed_count != 0)
    {
      led1.blink();
      led2.blink();
      led3.blink();
      led4.blink();
      led5.blink();
      led6.blink();
    }
    break;
  }

  // Serial.println(pushed_count);
  // delay(100);
}

void off_leds()
{
  led1.disable();
  led2.disable();
  led3.disable();
  led4.disable();
  led5.disable();
  led6.disable();
  delay(1000); // wait for disable the digitalpin off completely
}