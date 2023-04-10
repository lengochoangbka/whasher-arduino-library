#include "Arduino.h"
#include "whasher.h"

whasher::whasher (int hot_pin, int cool_pin, int pump, int cyclic)
{
     pinMode(hot_pin, OUTPUT);
     pinMode(cool_pin, OUTPUT);
     pinMode(pump, OUTPUT);
     pinMode(cyclic, OUTPUT);
    _hot_pin = hot_pin;
    _cool_pin = cool_pin;
    _pump = pump;
    _cyclic = cyclic;
}
void whasher::hot()
{
    Serial.println("Only use water from hot sources:");
    digitalWrite(_pump , LOW);
    digitalWrite(_hot_pin , LOW);
    digitalWrite(_cool_pin , HIGH);
    digitalWrite(_cyclic , HIGH);
}
void whasher::cool()
{
    Serial.println("Only use water from cool sources:");
    digitalWrite(_pump , LOW);
    digitalWrite(_hot_pin , HIGH);
    digitalWrite(_cool_pin , LOW);
    digitalWrite(_cyclic , HIGH);
}
void whasher::cyclic()
{
    digitalWrite(_pump , LOW);
    digitalWrite(_hot_pin , HIGH);
    digitalWrite(_cool_pin , HIGH);
    digitalWrite(_cyclic , LOW);
}
void whasher::choose()
{
    digitalWrite(_pump , LOW);
    digitalWrite(_cyclic, HIGH);
    digitalWrite(_cool_pin, LOW);
    digitalWrite( _hot_pin, LOW);
    delay(1500);
    digitalWrite(_hot_pin , LOW);
    digitalWrite(_cool_pin, HIGH);
    delay(1000);
}
void whasher::Disable_all()
{
    digitalWrite(_pump , HIGH);
    digitalWrite(_hot_pin , HIGH);
    digitalWrite(_cool_pin , HIGH);
    digitalWrite(_cyclic , HIGH);
    Serial.println("Stopped all devices: ");
}