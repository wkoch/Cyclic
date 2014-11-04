#include <Cyclic.h>

// 2 seconds auto-resetable cycle called blink.
// led is off for a second and on for one second.
// cycle auto-restarts every 2 seconds.

Cyclic blink(2000); // Creates a cycle of 2 seconds.
byte led = 13;

void setup() {
  pinMode(led, OUTPUT);
  blink.start(); // Starts the blink cycle.
}

void loop() {
  blink.update(); // Updates de cycle clock.
  // Tests the cycle position, if between 1000 and 2000...
  if (blink.now() >= 1000 && blink.now() <= 2000) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
