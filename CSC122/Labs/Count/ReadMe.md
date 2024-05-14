# Topical Information
This lab will help you practice with classes and libraries.

# Background Information
In olden times -- even before I was born! -- shoppers at a grocery store would keep track of their purchases with a simple hand-held counter. A click to any of four buttons would spin the gears inside so that the digit associated with that button would increment. Typically the four digits were viewed as tens, ones, tenths, and hundredths to line up with monetary needs. I recall seeing one of these at my grand-parents' house once: it was shiny red plastic with four holes through which you could view the digits and there was a '$' stamped in front of the first 'window' and a '.' stamped between the first and last pair of windows. (It was a way to have a small child waste several hours clicking inanely at the little buttons and thus not annoying you for this or that...*grin*)

# Program Information
Design and code a class to represent this 'little red counter' concept. Your counter should be able to hold any valid 4 digit number from 0 to 9999. When the 'hundredths' button is clicked for a counter object that represents 9999, it should wrap to 0 and remember that it has 'overflowed'.

Methods should be provided for construction from nothing (0), a certain starting value (must be in [0..9999] or we failed), or another counter object. Methods for access of the entire counter, access of the 'dollars', and access for the 'cents' should be provided for the programmer's convenience. Mutation should be allowed at an individual digit level (like the original device) as well as to change the counter to an entirely new value (within [0..9999] as with construction). Allow the programmer using the class to detect an overflow condition and to reset an overflow condition (they don't need to be able to set such a state, however).

To make it more general, allow the programmer using the class to change the maximum for the counter. This can be done as a number of digits or as a specific value -- at your discretion. (The last two [base ten] digits are always considered the 'cents'.)

Provide the ability to display in a monetary fashion (1234 displays as $12.34; or 509 displays as $5.09) or a raw fashion (1234 displays as 1234; or 509 displays as 0509). (As above, the last two [base ten] digits are always considered the 'cents'.)

You don't need to provide any means of direct input from the user. The button interface of the original device is a bit complicated for us to mimic within a generic counter class. Allow the application to provide such an interface -- or whatever they wish -- instead of us.

Place your counter ADT in a library.

To make sure the counter works correctly, write a driver (test application). Here you can provide any sort of interface you like, but a simple one would be 'A' -- 10's, 'S' -- 1's, 'D' -- 0.1's, and 'F' -- 0.01's. (ASDF is right there on the keyboard... And if you don't believe in the power of ASDF, may I suggest you check out the cul...er...organization (no, the .org and the .net are not the same; although the .org may be useful...).)

# Options
Add (Level 2) to properly apply inline'ing and const-ness to all of your class methods. (This includes proper use of initializer lists on constructors!)

Add (Level 2) to present a menu for the user to set-up options (when they enter the 'option menu' command -- perhaps 'p'?). Options you must allow them to change are:

the keys used for each counter button

whether to automatically report overflow

(if not, you should only print an overflow message when they enter the overflow-request key -- also a configurable key)

the maximum of the counter

If they hit the option command by accident, don't make them change an option or set it to what it already is. Give them a graceful way to return to normal program control. (Perhaps a 'nevermind' type of option?)

Add (Level 1) to display the default/current values of options in the menu choices. For instance:

    Options Menu
    1) set Button Keys (10's-a,1's-s,0.1's-d,0.01's-f,overflow-o,options-p)
    2) always Display Overflow?  (yes)
    3) counter Maximum (9999)
    4) Nevermind

    Choice:  _
    
After they've chosen an option (other than 4/N/n), take note of their desired changes and then return to normal program control.

(Thoughtful suggestion: The 1/B/b/K/k option might make a natural sub-menu...*shrug*)

Add (Level 1.5) to have menu options present the default/current choice and leave the option unchanged if the user simply hits [Enter] without giving you new information. (Hint: Keep your input buffer clean at all times to make this easier to detect...)
