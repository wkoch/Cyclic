#include <Cyclic.h>

// Unlimited time cycle manually reseted every 4 seconds.
// led is off for a second and on for one second on first cycle and
// then led is on for one second and off for three.
// cycle is manually restarted every 4 seconds.
// You can call a reset() trough a button, or from a sensor reading.

Cyclic blink = Cyclic(); // Creates a manual cycle without time limit.
byte led = 13;

void setup() {
  pinMode(led, OUTPUT);
  blink.start(); // Starts the blink cycle.
}

void loop() {
  // No blink.update() anywhere.
  if (blink.cycles() < 20) { // Led will blink 20 times and stop.
    // Tests the cycle position, if between 1 and 2 seconds:
    if (digitalRead(led) == LOW && blink.now() >= 1000 && blink.now() < 2000) {
      // blink.now() runs an update everytime it is called, two millis()
      // interrupts called in the above conditional.
      digitalWrite(led, HIGH);
    } else if (blink.now() >= 4000) { // manual reset every 4 seconds.
      blink.reset(); // manual reset, could be called by a sensor or button.
    } else {
      digitalWrite(led, LOW);
    }
  }
}
