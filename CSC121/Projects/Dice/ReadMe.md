# Topical Information
This program will give you more practice with generating random values, branching, looping, and playing with character input's clever applications. (There may also be a chance to use functions to clean up the program and ease development or even to use more advanced input features. See the Options section below.)

# Program Information
Write a program that helps the user determine the statistics on a common die roll. First read in the user's desired die roll. This is made programmatically interesting by the gamers' idea of 'optional' pieces of information. You will have to be able to accept entries of d6, 1d6, d6-0, 1d6-0, d6+0, and 1d6+0 — all of which mean the same thing; they are simply entered in a different way! Dealing with optional parts of input, of course, will entail determining (aka deciding) whether the upcoming input is or is not ...something. (As you recall, upcoming input can be seen by peeking into cin's buffer.)

Then the simple part: calculate the three basic statistics for the user's roll and report them in a 'nice way'.

Finally, it would be nice to give the user a sample roll of what might possibly come up during an actualroll. In order for you to make the sample roll statistically accurate, though, you can't simply apply the general formula we developed in lecture to the roll's minimum and maximum. Were you to naïvely use that formula, you would give the user a value that would certainly be in the proper range — but uniformlydistributed! (That is, each value would be equally likely to occur. Hence, if we rolled the d6mentioned above, we'd find that each of the faces has a 0.16666666666666666666...— or 1in 6— chance of being 'up'.)

Of course, that simply isn't the case ...in general... Look at something as simple as 2d4(two four-sided dice):

All possible resulting combinations when rolling two dice each with four sides.
```
+-------+-------+-------+    +-------+-------+-------+
| Die 1 | Die 2 | Total |    | Die 1 | Die 2 | Total |
+-------+-------+-------+    +-------+-------+-------+
|   1   |   1   |   2   |    |   3   |   1   |   4   |
|   1   |   2   |   3   |    |   3   |   2   |   5   |
|   1   |   3   |   4   |    |   3   |   3   |   6   |
|   1   |   4   |   5   |    |   3   |   4   |   7   |
|   2   |   1   |   3   |    |   4   |   1   |   5   |
|   2   |   2   |   4   |    |   4   |   2   |   6   |
|   2   |   3   |   5   |    |   4   |   3   |   7   |
|   2   |   4   |   6   |    |   4   |   4   |   8   |
+-------+-------+-------+    +-------+-------+-------+

```
Summary of the numer of ways each possible total can be arrived at when rolling two dice of four sides each.
```
+----------------+---+---+---+---+---+---+---+
| Dice Total     | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
+----------------+---+---+---+---+---+---+---+
| Ways to Get It | 1 | 2 | 3 | 4 | 3 | 2 | 1 |
+----------------+---+---+---+---+---+---+---+
```
The first table shows all possible rolls and totals for the dice. The second table shows the possible totals and the number of ways each can be achieved. Notice that a total of 5is 4times as likely to occur as either a 2or an 8total.

Although we could use some rather twisted statistics to model this behavior, it would be far easier to roll the dice individually and add up their respective values. Since each die taken alone is uniformly distributed, we can use our standard formula for that bit of randomness.

Then, repeatingthe roll of an individual die a number of times equal to the number of dice to be used and adding them up will get us a result 'just like' the one the user would get by rolling real dice. (It's so 'just like' theirs, of course, because that's exactly what they would do if they hadn't spent 80¢ [apiece!] on the extra dice because they were too lazy to add the single die result over the course of several rolls.) (Recall from above that the roll of a single die has a minimum of 1and a maximum of the number of sides on the die: S.)

As an example, you might have the program interaction look something like (the parts in this color are typed by the user):
```
$ ./dicestatproj.out

                 Welcome to the Dice Statistics Program!!!

What is your dice roll?  3d12

Thank you!!  Calculating...  Done.

When rolling 3d12 (3 size-12 dice), your statistics will be:

   Minimum:  3
   Average:  19.5
   Maximum:  36

A typical dice roll might result in 23.

Thank you for using the DSP!!

Endeavor to have an extemporaneous day!

$
```
Note how the average is a decimal value even though there is no possible way to roll a 19.5on a standard die. (That's statistics for ya'!)

Don't forget to make sure the typical roll is different each time you run the program with the same die roll.

# Options

Add (Level 1) to have your program repeat as often as the user desires.

Add (Level 2) to have your input validate the user's entry format. For this particular input, that is made tricky by the optionality of the Nand +Aparts of the die roll. At any rate, if the user has entered what shouldbe a number, make sure it is numeric. Also make sure the user only uses a d(or perhaps D) to precede the size of their dice. Finally, make sure the user's adjustment is only preceded by a +or a -. All the while, make sure that they can still place spaces between all parts of the die roll — Freedom of Input Act of 1987, remember? *grin* (Recall that, although the ws manipulator will eat any upcoming whitespace in the buffer, it treats \nno differently than any of the other spacing characters...and thus can cross over the user's original Entery.)

Add (Level 2) to add a menu structure to the program so that they can set options. Perhaps something like this:
```
    Dice Statistics Menu

    1) Enter Die Roll
    2) Force Platonic Sizes Only [NO]
    3) Quit
```
The first option (chosen by the user entering 1, E, e, D, d, R, or r) acts as the program currently does. The second option (chosen by the user entering 2, F, f, P, p, S, s, O, or o) controls an option that only allows the user to enter die rolls that are the Platonic sizes (4, 6, 8, 12, 20) or the standard gamer sizes (2, 10, 100). In brackets after the menu choice text is listed the current option state. It defaults to such sizes not being enforced. If the user choses this option, the state will change to YES and the die roll input will have to check that the die size entered is one of the 8 allowed values. If it isn't, the user will get no statistics or roll and be told to check their dice — no shaving corners to get weird sizes.
(Note that this program option subsumes the 'repeat as desired' option so you get credit for that option's level, too!)
(This option does not subsume the validation option, however. You can take that option and this option independent of one another. Their levels stack together normally.)


Add (Level 4) to write the program using at leasteight (8) functions:

printing the opening message

printing the closing message

printing a die roll in normal notation

printing all of the results

calculating the maximum

calculating the minimum

calculating the average

generating a random integer value between a specified minimum and maximum



Add (Level 2) to create a library for all dice specific functions.

Add (Level 2) to create a library for all random value creation functions. (Note that this will be a different and separate library from the dice library described above! Although there is no rule that says the dice library cannot usethe facilities of the random value library...)

Add (Level 1.5) to use a default value for the lower bound on your random range function.

Add (Level 1.5) to make appropriate use of inline functions.

Add (Level 1.5) to use a singlefunction for the input of a die roll (it will have no 'function' inputs and three 'function' outputs). (This function should go in your dice library if you did that option above. Don't 
worry, the levels will add up...)
If you combine this option with the input validation option above, add another (Level 1) to have this function manipulate cin's idea of failure when any of the good entry practices outlined above (possibly including the Platonic sizes enforcement...) are violated so that the calling part of the program can use cin as a guide as to whether entry was or was not successful.

Add (Level 1.5) to use a singlefunction to print both the opening and closing messages (and any other 'messages' your program may produce).
