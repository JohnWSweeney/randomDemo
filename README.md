# randomDemo

A console app exploring C++ Standard Library's pseudorandom number generators (PRNG).

This project uses four PRNGs: `mt19937`, `mt19937_64`, `rand_s`, and `rand`. PRNGs based on the Mersenne Twister algorithm (`mt19937`, `mt19937_64`) are widely recommended for general-purpose use and include helpful distribution functions. `rand_s` is also good and easy to implement. While `rand` is quite old, produces poor results, and is not recommended for serious projects, I've included it to demonstrate the evolution of PRNGs in C++.

## Motivation
"Anyone who considers arithmetical methods of producing random digits is, of course, in a state of sin." --  John von Neumann

Von Neuman's reservations aside, you can do some pretty interesting things with PRNGs. This project attempts to demonstrate some of those interesting things and how the underlying functions work. Like my [threadDemo](https://github.com/JohnWSweeney/threadDemo), I've approached this project as a teaching tool for a hypothetical, informal crash-course on PRNGs in C++. 

## Functions
The app opens a console window on startup. Enter the *command* keywords separated by a space. Commands are case-sensitive. Function names are entered first, followed by any parameters. For example:
>`functionName parameter1 parameter2 ...` 

### PRNG Basics
To generate ten pseudorandom integers, ranging from 0 to 10, using all four PRNGs, enter:
>`basic`

Similarly, to generate an indefinite number of integers within a specific range, enter:
>`basic n min max`

where *n* is the number of integers and *min* and *max* are lower and upper integer range limits, respectively. The `basic` function with user parameters is a threaded process and can be terminated with:
>`basic stop`

### Wall of Text
Just for fun, generate a wall of text of 1M random characters by entering:
> `wall`

### PRNGs are deterministic?
A repeatable series of pseudorandom integers is also useful in some applications. A PRNG produces the same series of integers when initialized with the same seed integer. The following example generates ten such integers, again ranging from 0 to 10, with zero as the seed integer:
>`basicSeed`

To generate an indefinite number of repeatable integers within a specific range, enter:
>`basicSeed n seed min max`

where *n* is the number of integers, *seed* is the seed integer, and *min* and *max* are lower and upper integer range limits, respectively. The `basicSeed` function with user parameters is a threaded process and can be terminated with:
>`basicSeed stop`

### Simulating Chance with PRNGs 
Flipping a coin is perhaps the simplest demonstration of true randomness. To simulate a coin flip, enter:
>`coinFlip`

"Heads" or "Tails" will be printed to the console.

Rolling dice is a more complex manifestation of randomness. To simulate a dice roll, enter:
>`diceRoll numSides numDice`

where *numSides* is the number of sides on the die and the number of dice is *numDice*. For example:
>`diceRoll 6 2`

simulates the result of rolling two standard six-sided dice.

### Chance Sequences
How many times would you need to flip a coin to get a streak of heads or tails? To find out, enter:

>`coinFlipStreak streak`

where *streak* is the number of time heads or tails occurs in a row. `coinFlipStreak` is a threaded process and can be stopped by entering:
>`coinFlipStreak stop`

Building on the previous example, how many dice rolls would be required to get the same side on all dice? Enter: 
>`diceRollMatch numSides numDice`

where *numSides* is the number of sides on the die and the number of dice is *numDice*. `diceRollMatch` is a threaded process and can be stopped by entering:
>`diceRollMatch stop`

### Default PRNG 
The 32-bit Mersenne Twister (`mt19937`) is the default PRNG for all chance-related functions. The default PRNG can be set to another by entering:
>`default set prngName`

where `prngName` is `rand`, `rand_s`, `mt32` for the 32-bit Mersenne Twister, or `mt64` for the 64-bit Mersenne Twister.

To query the current PRNG, enter:
>`default query`

### App Control
To stop all active threads, enter:
>`stop all`

To stop all active threads and exit the program, enter:
>`exit`

## Download
[randomDemo v1.1.0](https://github.com/JohnWSweeney/randomDemo/releases/download/v1.1.0/randomDemo_v1_1_0.exe) [45 kB]

## ChangeLog
v1.1.0
- Added random class with `mt19937`, `mt19937_64`, `rand_s`, and `rand` PRNGs and related functions.
- Updated basic.h/cpp functions.
- Added chance.h/cpp for chance related PRNG functions.
- Updated README.

v1.0.0
- Initial commit.