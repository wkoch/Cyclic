# Cyclic

Small library for millis-based cycle control. Simple to use, 4 examples included.

**Tested on an Arduino Due only.**

## Instructions

Include the library in your sketch:

    #include <Cyclic.h>

### Constructors

#### Manual Control

    Cyclic objectName = Cyclic();

Gives a Cyclic object with full manual control, you'll have to reset it when you want to restart your cycle.

#### Auto

    Cyclic objectName(maximumTime); // In milliseconds.

Creates a Cyclic object which will auto-reset the cycle every time it reaches maximumTime. You can reset it manually anytime.

#### Limited Auto

    Cyclic objectName(maximumTime, minimumTime); // In milliseconds.

Generates a Cyclic object which will auto-reset the cycle every time it reaches maximumTime. You can reset it manually only when the cycle time is between minimumTime and maximumTime.

### Functions

Cyclic has nine functions, some of them are similar, but all of them are simple and easy to understand and use.

#### start()

This serves to start your cycle, in some projects you want your cycle to start as soon as your Arduino is running (put it on the setup), and other times you want to start a cycle only when some function is running. There are no parameters for this function. Just call it when you need it, like this:

    objectName.start();

and your cycle is running forever (*maybe auto-restarting*), until you stop it manually. Put the line above inside your setup and that cycle will run as soon as your Arduino starts running. In case you want to run it only when some special function runs, then you can put it right before calling that special function, or right in the beginning of it, no need to worry about start() being called every time since it is already wrapped in a conditional, if the cycle is already running nothing is done when you call start().

#### stop()

Stops your cycle, resets all runtime variables, it will restart the completed cycles counter **cycles()**. Call it when you want to completely stop your cycle:

    objectName.stop*();

#### status()

This function allows you to confirm if the Cyclic cycle was already started or not, it will return True when the cycle is running and False otherwise. Just use it directly in a conditional:

    if (objectName.status) {
      objectName.stop;
    }

#### update()

This will update the Cyclic clock by calling millis(). Every call to update(), calls millis() and stores its value inside Cyclic. Just call it in the main loop or inside a while which calls Cyclic.time():

    objectName.update();

#### reset()

Resets your cycle, Cyclic is like a chronometer, when started it will count from 0 up to maximumTime and reset automatically, or it will count up indefinitely when manual control. When calling reset(), this chronometer is reset to zero and begins counting up again. You can auto-reset by using a constructor with maximumTime or manually like this:

    objectName.reset();

#### time()

Returns the time stored on the last call to update(). This is a great way to get the current time in big conditionals without doing many calls to the millis() interrupt. Calling millis() many times in your code may or may not make a difference in your project, but you have the choice. time() yields the same result every time, unless update() is called in between:

    objectName.update(); // Gets the current time from millis();
    objectName.time(); // Returns the last update() stored time, ex: 300 ms
    objectName.time(); // Returns exactly the same stored time, ex: 300 ms
    objectName.update(); // Gets the current time from millis();
    objectName.time(); // Returns the time got on the last update(), ex: 350 ms

#### now()

It's exactly the same as time, except that it is for lazy people, now() always calls an update() before returning the current time, so it always returns the latest millis() value. If you use only now() for time reading in your sketch you can completely ignore the update() function.

    objectName.now(); // Returns the current time from millis(), ex 300 ms
    objectName.now(); // Returns the current time from millis(), ex 301 ms
    objectName.now(); // Returns the current time from millis(), ex 302 ms

#### last()

Returns the time duration from the last cycle, if you auto-reset your cycle every 2 seconds, last() will return 2000 ms, if you do a manual reset at 1.2 seconds, last() will return the last cycle duration of 1200 ms.

    objectName.last();

#### cycles()

Returns the number of cycles completed between a Cyclic start() and stop(), remember that each time you call stop() this counter will be reseted, so if you need a total count for several cycles you should store the value of cycles() right before the stop() function is called.

    objectName.cycles(); // Cycles completed, ex: 30
    totalCycles += objectName.cycles();
    objectName.stop(); // Resets the cycle counter
    objectName.cycles(); // Cycles completed, ex: 0
