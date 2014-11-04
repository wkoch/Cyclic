/*
  Cyclic.cpp - v1.0
  Library for millis-based cycle control
  Created by William Koch, November 04, 2014.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Cyclic.h"

// Manual control, no auto-reset.
Cyclic::Cyclic() {
  _max = _min = _start = _last = _now = _cycles = 0;
  _active = false;
}

// Auto-resets at max value
// Manual reset always available.
Cyclic::Cyclic(unsigned long max) {
  _max = max;
  _min = _start = _last = _now = _cycles = 0;
  _active = false;
}

// Auto-resets at max value.
// Manual reset only between min and max.
Cyclic::Cyclic(unsigned long max, unsigned long min) {
  _max = max;
  _min = min;
  _start = _last = _now = _cycles = 0;
  _active = false;
}

void Cyclic::start() {
  if (!_active) {
    _active = true;
    _start = millis();
    Cyclic::update();
  }
}

void Cyclic::stop() {
  if (_active) {
    _active = false;
    _start = 0;
  }
}

void Cyclic::reset() {
  if (_active && _now >= _min) {
    _last = _now;
    _now = 0;
    _cycles++;
    _start = millis();
  }
}

void Cyclic::update() {
  if (_active) {
    _now = millis() - _start;
    if (_max > 0 && _now >= _max) {
      Cyclic::reset();
    }
  }
}

unsigned long Cyclic::now() {
  if (_active) {
    return _now;
  }
}

unsigned long Cyclic::last() {
  if (_active) {
    return _last;
  }
}

unsigned long Cyclic::cycles() {
  return _cycles;
}
