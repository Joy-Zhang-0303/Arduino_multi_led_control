#include <Arduino.h>
#define led_1 8
#define led_2 9
#define led_3 10
#define led_4 11
#define led_5 12

// put function declarations here:
int led_blink(int, int);
bool led_status = HIGH;

void setup()
{
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  led_blink(led_1, 10);
}

// put function definitions here:
int led_blink(int x, int f)
{
  /*
  Input:
   - x: Digital Pin No.
   - f: Frequency.
  */
  static unsigned int count_called = 0;
  static unsigned int count_period = 0;
  static unsigned long privious;
  unsigned long current;

  // initialize the time at first time
  if (count_called == 0)
  {
    privious = millis();
  }

  current = millis();
  Serial.println(privious);

  if ((current - privious) > 1000 / f)
  {
    privious = current;
    count_period++;

    if (count_period % 2 == 0)
    {
      digitalWrite(x, HIGH);
    }
    else
    {
      digitalWrite(x, LOW);
    }
  }
  count_called++;
  return true;
}