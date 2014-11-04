/*
  Cyclic.cpp - v1.0
  Library for millis-based cycle control
  Created by William Koch, November 04, 2014.
  Released into the public domain.
*/

#ifndef Cyclic_h
#define Cyclic_h

#include "Arduino.h"

class Cyclic {
  public:
    // Manual control, no auto-reset.
    Cyclic();

    // Auto-resets at max value
    // Manual reset always available.
    Cyclic(unsigned long max);

    // Auto-resets at max value.
    // Manual reset only between min and max.
    Cyclic(unsigned long max, unsigned long min);

    void start();
    void stop();
    void reset();
    void update();
    unsigned long now();
    unsigned long last();
    unsigned long cycles();
  private:
    unsigned long _min, _max, _start, _now, _last, _cycles;
    boolean _active;
};

#endif
