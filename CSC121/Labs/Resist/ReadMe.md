# Topical Information
This lab will help you practice with data types, mathematical calculations, input, output, and forming a main program.

# Background Information
A resistoris a piece of electronics that resiststhe flow of electricity. Different resistors can resist electrical flow with different strengths. This strength of resistance is measured in units of ohms(Ω).

Resistors Placed In Series
In the simplest electrical circuit, two resistors can be placed in one of two possible configurations. They can be placed in line with one another (called 'in series' by electrical engineers):

      ---------------/\/\----------/\/\----------

                      R1            R2
(The /\/\ things are the resistors. The ---- is the electrical conductor of the circuit — like a copper wire. The Ri are variables representing the ohms measures of each resistor.)

Two resistors in series will affect this portion of the circuit's resistance to electrical flow according to this formula:

    Rc = R1 + R2
This is read: "the equivalent resistance of the circuit (of two resistors placed in series) is equal to the sum of the resistance strengths of the two resistors."

Resistors Placed In Parallel
On the other hand, two resistors can also be placed side by side (called 'in parallel' by electrical engineers):

    ----------------------
         |         |
         |         |
         /         /
     R1  \     R2  \
         /         /
         \         \
         |         |
         |         |
    ----------------------
In this configuration their effect on the resistance of the surrounding circuit's is:

                1
     Rc = -------------
            1      1
           ---- + ----
            R1     R2
This is read: "the equivalent resistance of the circuit (of two resistors placed in parallel) is the reciprocal of the sum of the reciprocals of the individual resistances." (*whew!*)

(Recall that this form of rational expression — having rational expressions as sub-parts — is known as a complex rational expression.)

In Practice...Let's Get A Grip
Theory and formulas are all well and good, but how can we write a program about something we've never experienced?! (Sadly, this happens all the time, but programmers have gotten pretty good at approximating knowledge from resources, references, and experts.) Okay, fine, fine! Let's practice what we've been preached...at...about...yeah...

If I place a board 1' wide and 3" tall into a channel 1' wide and 6" deep, how is the flow of water affected? Well, practically speaking, we've cut off half the room the water had to flow there. So we've resisted the water's flow. Unfortunately, electrons (or the positive holes they leave behind more to the point) don't react like water does. When we put the board in the water channel, the water has less room to go, but still wants to go! So, more of it rushes through — we increase the flow of water by trying to resist its flow!

Electricity, on the other hand, might be better reckoned as fish swimming in a stream. The resistors are like rocks, branches, logs, and even bears (sort-of) in the stream. All of these things impede the path of the fish — making them detour or even stopping them altogether. This slow down of the fish's journey is a much more appropriate visualization of what resistors do to electricity than the board/dam in the water.

Now that we have a decent model to picture things with, lets re-think the formulae given above:

    RS = R1 + R2

               1
    RP = -------------
           1      1
          ---- + ----
           R1     R2
The first one is for resistors placed one right after another and says that the resistance strength of the pair is the total of their effects individually. True. If I place a rock in a fish's way and then a branch right after that, the fish will be delayed twice.

The second one is for resistors placed side-by-side. But how can we visualize this with the fish?! What's with the reciprocal-ed reciprocals and such?! Hmm... Well, if I zoom back from the diagram above, I see how this parallel set of resistors is hooked into the circuit:

                      R1

              +-----\/\/\/-------+
              |                  |
       -------+                  +-------
              |                  |
              +-----\/\/\/-------+

                      R2
(Okay, so I redrew it completely. So sue me...er...well, don't do that, but they're both instructive!)

So now we see that we've given the fish one of two alternative paths through the stream — an island or sand bar is splitting the water's path. How can a single fish be affected by the rock/branch placed on either side of the split?! Well, a single fish can't. What the formula measures is 'effective equivalent resistance'. We are seeing what type of resistance this formation has compared to a single resistor placed in the circuit:

       -------------\/\/\/---------------

                      RP
It is possible that statistics and probability has entered our realm unbidden...or perhaps electricians with ohm-meters simply took readings for days on end and evolved the formula. At any rate, it seems we'll just have to trust that the results are correct.

Unless, of course, someone has a good visualization to share with the rest of us? *shameless begging*

In Practice...Trying It Out
So, let's say we have a 5 lbs rock...er...a 5 Ω resistor attached following a 10 Ω resistor in a circuit. What is their equivalent resistance?

We see that they are attached 'following' one another and so this is a series circuit. We substitute the given values for the variables R1 and R2 to get:

    RS = R1 + R2
       = 10 + 5
       = 15 Ω
Next let's try to attach the 5 Ω resistor along-side-of the 10 Ω resistor in the circuit. What is their effective resistance now?

Placing one resistor 'along-side-of' is going to make a parallel circuit. Substituting the resistance values for the variables R1 and R2 we get:

                1
     RP = -------------
            1      1
           ---- + ----
            10     5

                1
        = -------------
            1   +  2
           -----------
               10

             1
        = ------
             3
           ----
            10

           10         _
        = ---- ~ 3.3333 Ω
            3
Hmm... the fish had a choice between being delayed by '5' and twice that on the other side. About a third of them... no, a third of the '10' side... no, hmm...

It kind-of makes sense, but it still isn't clear why. That series circuit makes so much more sense! Why don't we just use that one all the time? Well, there are many reasons. Sometimes you need a resistance that isn't a whole number and resistors seem to only be manufactured in strengths of whole Ω's. Or, perhaps you need a certain resistance to fix a broken circuit but you don't have that resistor handy! You can use a parallel circuit to make this happen — even when you can't do it with a series circuit.

Take, for example, the situation that you need a 40 Ω resistance in a circuit but your only available resistors are in units of 60 Ω, 100 Ω, 120 Ω, and 150 Ω. If we could only use a series circuit, we'd be out of luck! We'd order the resistor, which would be out of stock and placed on back-order, and on, and on, and on... But with a parallel circuit, we take the 60 Ω resistor and place it parallel to the 120 Ω resistor to get:

                 1
     RP = --------------
             1      1
           ----- + ----
            120     60

               1
        = -----------
            1  +  2
           ---------
              120

             1
        = -------
             3
           -----
            120

           120
        = ----- = 40 Ω
            3
Of course, the two resistances don't have to be paired as nand 2n(as the 5 and 10 and then the 60 with the 120 were). What would happen, for instance, if we'd hooked the 60 together with the 150 or the 100? We'd have gotten:

Resistors	Equivalent Parallel Resistance
60 & 150	300/7 ~ 42.857
60 & 120	120/3 = 40
60 & 100	300/8 = 75/2 = 37.5
# Program Information
Okay, so what do we do with all of this stuff? Let's write a program to read in the user's two resistors' resistance values, calculate both the parallel and series resistances, and print each out. (Keep in mind that the resistors you can buy at the store only come in whole numbers of ohms!)

As an example, the program interaction might look something like (the parts in this color are typed by the user):
```
$ ./resist.out

                 Welcome to the Resistor Calculation Program!!!

Please enter your two resistances:  12 42

Thank you!!  You've entered 12 ohms and 42 ohms!  Calculating...

Done.

If your resistors are placed in series, they'll total to 54 ohms.

If they are placed in parallel, they'll total 9.333333 ohms.

Thank you for using the RCP!!

Endeavor to have a blossoming day!

$
```
Try Before You Buy...
If you were to have coded up the program as required above and demonstrated in the above example, you would be able to play with it like you can this version. (Click the "Run the Program" button to execute the 'resist.out' program as if you'd already finished it! Then click "Run Again" to...well, run it again. *shrug*)

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
```
     1      1      1
   ---- = ---- + ----
    RP      R1     R2

```
for RP. ...how do we solve equations involving rational expressions? Hmm...)

### Multiple Resistors

Add (Level 2) to use the accumulator loop pattern to allow the user to have as many resistors as they need in their sequence.

Note that if you did the above algebraic exploration, this won't work for more than two resistances! You can still get that level by doing the first two resistances before your loop and reporting their equivalences. Then, loop to gather more and calculate the total as originally specified along the way.

Also note that if you did the units option above, it needs to apply to the resistances entered in the loop as well!
