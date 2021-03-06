/*
  Cyclic - v1.2 - November 19, 2014.
  Arduino library for millis-based cycle control.
  Created by William Koch.
  Released into the public domain.
*/

#include "Cyclic.h"

// Manual control, no auto-reset.
Cyclic::Cyclic() {
  _max = _min = _start = _last = _now = _cycles = 0;
  _active = false;
}

// Auto-resets at max value.
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

// Starts the cycle.
void Cyclic::start() {
  if (!_active) {
    _active = true;
    _start = millis();
    Cyclic::update();
  }
}

// Stops the cycle.
void Cyclic::stop() {
  if (_active) {
    _active = false;
    _start = 0;
  }
}

// Resets the cycle.
void Cyclic::reset() {
  if (_active && _now >= _min) {
    _last = _now;
    _now = 0;
    _cycles++;
    _start = millis();
  }
}

// Reboots the cycle.
void Cyclic::reboot() {
  Cyclic::stop();
  _start = _last = _now = _cycles = 0;
}

// Updates the time and auto-resets.
void Cyclic::update() {
  if (_active) {
    _now = millis() - _start;
    if (_max > 0 && _now >= _max) {
      Cyclic::reset();
    }
  }
}

// Returns the time of the cycle from last manual update.
unsigned long Cyclic::time() {
  if (_active) {
    return _now;
  }
}

// Returns the current time of the cycle.
unsigned long Cyclic::now() {
  if (_active) {
    Cyclic::update();
    return _now;
  }
}

// Returns the duration of the last cycle.
// Good for implementing median dynamic cycles.
unsigned long Cyclic::last() {
  if (_active) {
    return _last;
  }
}

// Returns the max value.
unsigned long Cyclic::cycle() {
  return _max;
}

// Returns the count of cycles completed.
unsigned long Cyclic::cycles() {
  return _cycles;
}

// Returns True when Cyclic is running and False otherwise.
boolean Cyclic::status() {
  return _active;
}
