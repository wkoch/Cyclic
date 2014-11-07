#include <Cyclic.h>

// 2 seconds auto-resetable cycle called blink.
// led is off for a second and on for one second.
// cycle auto-restarts every 2 seconds.

Cyclic blink(2000); // Creates a cycle of 2 seconds.
byte led = 23;
byte led2 = 25;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  blink.start(); // Starts the blink cycle.
}

void loop() {
  blink.update(); // Updates the cycle clock.
  // Tests the cycle position, if between 1000 and 2000...
  if (blink.time() >= 1000 && blink.time() <= 2000) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }

  if (blink.time() >= 0 && blink.time() <= 1000) {
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);
  }
}
