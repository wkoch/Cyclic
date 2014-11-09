#include <Cyclic.h>

// 2 seconds auto-resetable cycle called blink.
// led is off for a second and on for one second.
// cycle auto-restarts every 2 seconds.

Cyclic blink(2000); // Creates a cycle of 2 seconds.
Cyclic blink2(3000); // Creates a cycle of 3 seconds.
byte led = 23;
byte led2 = 25;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  blink.start(); // Starts the blink cycle.
  blink2.start(); // Starts the blink2 cycle.
}

void loop() {
  blink.update(); // Updates the cycle clock.
  // Tests the cycle position, if between 1000 and 2000...
  if (blink.time() >= 1000 && blink.time() <= 2000) { // using time()
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }

  if (blink2.now() >= 1500 && blink2.now() <= 3000) { // using now()
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);
  }
}
