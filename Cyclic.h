/*
  Cyclic.cpp - v1.2
  Arduino library for millis-based cycle control.
  Created by William Koch, November 07, 2014.
  Released into the public domain.
*/

#ifndef Cyclic_h
#define Cyclic_h

#include "Arduino.h"

class Cyclic {
  public:
    // Manual control, no auto-reset.
    // USAGE: Cyclic Name = Cyclic();
    Cyclic();

    // Auto-resets at max value
    // Manual reset always available.
    // USAGE: Cyclic Name(number);
    Cyclic(unsigned long max);

    // Auto-resets at max value.
    // Manual reset only between min and max.
    // USAGE: Cyclic Name(Number1, Number2);
    Cyclic(unsigned long max, unsigned long min);

    void start();
    void stop();
    boolean status();
    void update();
    void reset();
    void reboot();
    unsigned long time();
    unsigned long now();
    unsigned long last();
    unsigned long cycle();
    unsigned long cycles();
  private:
    unsigned long _min, _max, _start, _now, _last, _cycles;
    boolean _active;
};

#endif
