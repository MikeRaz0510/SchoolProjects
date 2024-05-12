# Topical Information
This program works with more data to give you some more practice at handling more variables. It will hopefully also give you an even better feel for how much testing is necessary to verify a program's correctness. Finally, it gives a refresher to some concepts from algebra.

# Program Information
Write a program that helps the user calculate the midpoint of a line segment in the 2D Cartesian plane. Try to make your results as readable as possible.

As an example, you might have the program interaction look something like (the parts in this color are typed by the user):

```
$ ./midpoint.out

Welcome to the 2D Midpoint Program!!!

What is the first end-point?  3.4 12.2
What is the second end-point?  13.4 12.2

Thank you!!  Calculating...  Done.

The midpoint of the line segment between (3.4, 12.2) and (13.4, 12.2)
is (8.4, 12.2).

Thank you for using the TMP!!

Endeavor to have a voracious day!

$
```
# Options

You may choose to alter your program from above to add any of the following (bulleted) options. You won't be handing in a separate program (unless specifically told to do so!). You will simply change the program you already have to adhere to the new specifications below. This change is considered significant enough to increase your level as stated below.

Again: do NOT create/hand-in multiple programs! Simply altering the program you have already written is enough to increase its level by the amount specified in the option you choose...

(Note: If the option includes its own TPQs, you mustanswer them in addition tothe ones above to earn the full credit!)

### User-Entered-Units?
Some users might like to type in their units along with the resistance values. (Although Ω is the only unit I've heard used, some people are just creatures of habit. "Ya' gotta do what ya' gotta do.")

Add (Level 1) to allow the user to type the "ohms" after their resistance values. Since this is the only unit (known) for this measure, we don't need to care about what was actually entered — we just need to remove it so we can get to the next input value(s). Also, to allow for this, we'll have to change the program to prompt for each resistance separately. That way we'll know the data value is coming first at each prompt and thenthe garbage...er...units.

With these changes, the program interaction might look like so (the parts in this color are typed by the user):
```
$ ./resist.out

                 Welcome to the Resistor Calculation Program!!!

Please enter your first resistance:  12 ohms
Please enter your second resistance:  42ohms

Thank you!!  You've entered 12 ohms and 42 ohms!  Calculating...

Done.

If your resistors are placed in series, they'll total to 54 ohms.

If they are placed in parallel, they'll total 9.333333 ohms.

Thank you for using the RCP!!

Endeavor to have a blossoming day!

$
```
Note that this example user has entered the same values as above and gotten the same answer. They simply typed in the units after their values instead of the values alone.

Note also that on the second entry they mistyped and skipped the space between the value and the unit name!

Here's another example that should work with this option-enhanced program (the parts in this color are typed by the user):
```
$ ./resist.out

                 Welcome to the Resistor Calculation Program!!!

Please enter your first resistance:  12
Please enter your second resistance:  42 oops, I forgot my units above...they are both in "ohms"

Thank you!!  You've entered 12 ohms and 42 ohms!  Calculating...

Done.

If your resistors are placed in series, they'll total to 54 ohms.

If they are placed in parallel, they'll total 9.333333 ohms.

Thank you for using the RCP!!

Endeavor to have a blossoming day!

$
```
This one should also work (the parts in this color are typed by the user):
```
$ ./resist.out

                 Welcome to the Resistor Calculation Program!!!

Please enter your first resistance:  12
Please enter your second resistance:  42

Thank you!!  You've entered 12 ohms and 42 ohms!  Calculating...

Done.

If your resistors are placed in series, they'll total to 54 ohms.

If they are placed in parallel, they'll total 9.333333 ohms.

Thank you for using the RCP!!

Endeavor to have a blossoming day!

$
```
And even this one — sadly (the parts in this color are typed by the user):
```
$ ./resist.out

                 Welcome to the Resistor Calculation Program!!!

Please enter your first resistance:  12crap
Please enter your second resistance:  42 more crap!

Thank you!!  You've entered 12 ohms and 42 ohms!  Calculating...

Done.

If your resistors are placed in series, they'll total to 54 ohms.

If they are placed in parallel, they'll total 9.333333 ohms.

Thank you for using the RCP!!

Endeavor to have a blossoming day!

$
```
### Algebraic Exploration
The formulae given above for equivalent resistance calculations are standard — see most any introductory electronic circuits course textbook. However, they are not necessarily optimal for implementation on a computer.

Okay, so the series equation is fine. But the one for parallel equivalent resistance is clunky and requires three (3) divisions! Division is one of the slowest things we can do on the computer!

Add (Level 0.5) to algebraically manipulate the parallel equation to represent an equivalent result, but require only one (1) division and one (1) multiplication instead of the current three (3) divisions.

(Hint: Consider solving the following algebraic equation:

     1      1      1
   ---- = ---- + ----
    RP      R1     R2
for RP. ...how do we solve equations involving rational expressions? Hmm...)

### Multiple Resistors

Add (Level 2) to use the accumulator loop pattern to allow the user to have as many resistors as they need in their sequence.

Note that if you did the above algebraic exploration, this won't work for more than two resistances! You can still get that level by doing the first two resistances before your loop and reporting their equivalences. Then, loop to gather more and calculate the total as originally specified along the way.

Also note that if you did the units option above, it needs to apply to the resistances entered in the loop as well!
