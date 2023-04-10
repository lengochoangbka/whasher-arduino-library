#ifndef WHASHER_h
#define WHASHER_h
#include "Arduino.h"

 class whasher
 {
 private:
    int _hot_pin;
    int _cool_pin;
    int _pump;
    int _cyclic;

 public:
    whasher(int hot_pin, int cool_pin, int pump, int cyclic);
    void hot();
    void cool();
    void cyclic();
    void choose();
    void Disable_all();
 };
#endif