# Topical Information
This program will continue to provide you with practice with using standard library functions, making elegant use of character input's amazing properties, branching, and looping. There are also options for using functions to clean up the program/ease development and using more advanced input features.

# Background Information
You remember your old friend the Cartesian plane, right? Well, then you'll also remember how to determine the distance between any two points in that plane or how to find a third point which is equidistant from each of two points in that plane.

# Program Information
Write a program that helps the user calculate both the distance between two points in the 2D Cartesian plane and the midpoint of the line segment those two points define. Try to make your results as readable as possible.

Oh, btw, the exact level of the user may be a bit variable. The client said they want to use this program anywhere in their K-12 school system. So, you'll need to account for the possibility that the user may use appropriate notation during entry or might not. They may leave off one or both parentheses or leave out the comma between the two coordinates. If they do, don't worry about it, but print a little reminder message to tell them what notation they messed up on.

So, to enter the point (3,-4), the user should be able to enter any of: (3,-4), 3,-4), (3,-4, (3 -4), 3,-4, 3 -4), (3 -4, or even 3 -4. Only the first would be quiet, however, the others would generate 1, 2, or even 3 warning/reminder messages about missing notation.

As an example, you might have the program interaction look something like (the parts in this color are typed by the user):
```
$ ./pointcalcinp.out

                 Welcome to the 2D Point Program!!!

Where is your first point?  3.4 12.2)

    You were missing the open parenthesis before the x coordinate!
    You were missing the comma to separate coordinates!

    Please use proper notation...

Where is your second point?  (13.4, 12.2

    You were missing the close parenthesis after the y coordinate!

    Please use proper notation...

Thank you!!  Calculating...  Done.

(3.4, 12.2) is 10 units away from (13.4, 12.2).

The midpoint of the line segment from (3.4, 12.2) to
(13.4, 12.2) is (8.4, 12.2).

Thank you for using the 2PP!!

Endeavor to have a day...

$
```
This assignment is (Level 4).

# Options

Add (Level 1) to have your program repeat as often as the user desires.

Add (Level 2) to have your input validate the user's entry format more forcefully. For this program's particular input structure, such a thing is made tricky by the optionalityof the (, ,, and )parts of the traditional notation.

However, if the user has entered what should be a number, make sure it is numeric. Also make sure the user only uses (, ,, and )in the places they should be used -- if they are entered. All the while, make sure that they can still place spaces between all parts of the 2D point (Freedom of Input Act of 1987, remember? *grin*).

(Hint: Recall that, although the ws manipulator will eat any upcoming whitespace in the buffer, it treats '\n'no differently than any of the other spacing characters...and thus can cross over the user's original Enter-y.)

Add (Level 2) to add a menu structure to the program so that the user can set options. Perhaps something like this:
```
    2D Point Calculations Menu

    1) Perform Point calculations
    2) Set Notation complaint Level [WARNING]
    3) Quit
```
The first option (chosen by the user entering '1', 'P', or 'p') acts as the program currently does. The second option (chosen by the user entering '2', 'S', 's', 'N', 'n', 'L', or 'l') controls an option that decides what to do when the user's notation isn't the best it could be.

A level of WARNING(the default) behaves as the program is described above. A level of ERRORshould make the program behave as described in the validation option above. (Yes, if your program actually does behave that way, you get the levels for that option and this one!)

In [square] brackets after the menu choice text is listed the current option state. If the user selects this menu option, the state will change to 'ERROR'and the entry of a point will behave as described under validation above. If the option is selected again, the state will toggle back to 'WARNING'and entry of a point will return to the behavior described in the main assignment.

(Note that this program option subsumes the 'repeat as desired' option so you get credit for that option's level, too!)

Add (Level 4) to write the program using at leastthese six (6) functions:

printing the opening message

printing the closing message

printing a 2D point in normal notation

printing all of the results

calculating the distance of two points

calculating the midpoint of two points


Add (Level 2) credit for placing all point-oriented functions in a library.

Add (Level 2) credit for using either overloading or default arguments (pick one) to make your distance function capable of doing 1D, 2D, or even 3D distances.

(This will NOT change the purpose of the program to deal with other dimensionalities! This only provides functions that coulddeal with those other possibilities ...should the need arise at some point!!!)

Add (Level 2.5) credit for using encapsulation and re-use (and maybe overloading) to provide specialized functions for 1D, 2D, and 3D midpoint calculations. (These functions should re-use your current function!!!)

(This will NOT change the purpose of the program to deal with other dimensionalities! This only provides functions that coulddeal with those other possibilities ...should the need arise at some point!!!)

Add (Level 1.5) credit for using a single function to input a 2D point. It should have no inputs and two outputs (the two coordinates). (This function should go in your point library if you did that option above. Don't worry, the levels will add up...)

If you combine this option with the input validation option above, add another (Level 1) to have this function manipulate cin's idea of failure when any of the good entry practices outlined above are violated so that the calling part of the program can use cin as a guide as to whether entry was or was not successful.

Add (Level 1.5) to use a singlefunction to print both the opening and closing messages (and any other 'messages' your program may produce).
