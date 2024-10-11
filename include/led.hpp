// define the led class
#include <Arduino.h>
class led
{
public:
    led(); // constructor
    void setPortNum(int x);
    void setFre(int x);
    void blink();
    void disable();

private:
    unsigned long _t_privious;
    unsigned long _t_current;
    int _digital_port;
    float _fre;
    unsigned int _count_called = 0;
    unsigned int _count_period = 0;
};

// define the functions
led::led()
{
    _digital_port = 13;
    _fre = 5.0;
    digitalWrite(_digital_port, LOW);
};

void led::setPortNum(int x)
{
    _digital_port = x;
}

void led::setFre(int x)
{
    _fre = x;
}

void led::blink()
{
    // initialize the time at first time
    if (_count_called == 0)
    {
        _t_privious = millis();
        _count_called++;
    }

    _t_current = millis();

    if ((_t_current - _t_privious) > (1000 / (2*_fre))) // Fix the period
    {
        _t_privious = _t_current;
        _count_period++;

        if (_count_period % 2 == 0)
        {
            digitalWrite(_digital_port, HIGH);
        }
        else
        {
            digitalWrite(_digital_port, LOW);
        }
    }
}

void led::disable()
{
    digitalWrite(_digital_port, LOW);
}