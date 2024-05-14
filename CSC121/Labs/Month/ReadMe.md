# Topical Information
This lab will help you practice with libraries and classes.

# Program Information
Design and code a class that represents a single month of the year. It should have a single integer-typed data member to represent the month. Make sure to provide for proper construction, access, and mutation for this member as well as input and output methods.

In addition, methods for comparing two months chronologically for ordering would be useful. (You know, to decide if the calling month is earlier, later than, or at the same time as the argument month.)

Also a method to advance to the next month would be handy. (Note that January follows December and begins the cycle anew.) You should also be able to move to a previous month. In fact, thinking about it, it might be good to be able to advance to a month an arbitrary number of whole months in the future or past: January+ 5= June; March- 5= October.

Place your Monthclass in a library.

Write a test application (driver) for your class.

Oh, BTW, the programmers who commissioned this class wanted to make sure it could handle not only integer-valued representation of a month but also either whole-word names or three-letter abbreviations for the months. By this they mean that they should be able to construct a Monthobject from either an integer value or a string — which could be either the whole month name or a 3-letter version thereof. (The Monthobject would still just store a single integer to represent which month it represented, however.)

Similarly, they'd like to be able to retrieve (i.e. access) the Month's information as either an integer value or a string (of either form), mutate the Monthby any of these means, display by any of the three forms, and even allow their user to enter any of the three forms at the console.

But, to keep things as simple as possible, they'd not like a whole lot of different names to remember. Please use the following names for all functions that perform such tasks: set_month, get_month, input, output, advance, before, after, and same. (There may be only one of some methods, but others will need at least two overloadsto offer full functionality.)


# Options

Add (Level 2) to properly apply inline'ing and const-ness to all of your class methods. (This includes proper use of member initializer lists on constructors!)

Add (Level 2) to use a vector to store the month names. Then, instead of using a huge switch, a linear search of the vector could be used to find the proper month — 4 lines instead of 15! (This can actually simplify your class GREATLY.)

Note: This will alter your constructors, mutators, and accessors. It may also affect the inputand outputmethods (when working with names/abbrev.; although it needn't). Note also that this will not add any new accessors or mutators to your class, treat this vector member as if it were constant (even though we can't actually make it a constant member...*sigh*).

Make sure that you fill in the vector with month names only once — not during every conversion request! (Hint: To simplify construction, you may want to do this step in a private helper method...)

However, I'll add another (Level 2) to not add a new data member to your class to do this...*double take* WHAT?!?!

To notadd a data member, the vector can be placed into the conversion function(s) as a static local variable. This still affects the storage for your class, but not of each individual object. (A static local variable for a function doesn't get destroyed between calls and is 'initialized' only on the first call to the function. Otherwise, it acts normally and is only 'in scope' within the function.)

To fulfill the single initialization requirement, however, we'll need to rememberthat we were/n't initialized. (Since the only way we have to put data into a vector is to push_[it_]back or subscript...*sigh*) This could be a separate helper memory variable (another static local as well) or can the vector somehow tell us it was never initialized? Now, on the first call to the function, initialize the vector to the names of the months. But use your memory to not repeat the initialization on later calls.

(To achieve this same end, you could also make the vector member itself static, but that is trickier and makes the process more obvious to programmers using your class.)
