# Topical Information
This program gives you practice with branching and looping.

# Program Information
Code a menu that allows the user to choose between finding the midpoint of or the distance between two points. The final option should be to quit.

Allow them to enter menu options by either the number or a capitalized letter (make each option's special letter unique!).

As an example, you might have the program interaction look something like (the parts in this color are typed by the user):
```
$ ./pt_menu.out

                 Welcome to the Point Menu Program!!!

    1) calculate Distance between two points
    2) calculate Midpoint of two points
    3) Quit

    Choice:  n

I'm sorry, that choice is invalid!

Please try to read/type more carefully next time...

    1) calculate Distance between two points
    2) calculate Midpoint of two points
    3) Quit

    Choice:  mid


Where is your first point?  (3.4, 12.2)
Where is your second point?  (13.4, 12.2)

The midpoint of the line segment from (3.4, 12.2) to
(13.4, 12.2) is (8.4, 12.2).


    1) calculate Distance between two points
    2) calculate Midpoint of two points
    3) Quit

    Choice:  D


Where is your first point?  (3.4, 12.2)
Where is your second point?  (13.4, 12.2)

(3.4, 12.2) is 10 units away from (13.4, 12.2).


    1) calculate Distance between two points
    2) calculate Midpoint of two points
    3) Quit

    Choice:  3

Thank you for using the PMP!!

Endeavor to have a transcendental day!

$
```
Be careful that they don't derail your program with words for menu choices!

# Options

Add (Level 1) to have your input format be more flexible. Allow the user to leave off one or both parentheses or to leave out the comma between the two coordinates. If they do, don't worry about it, but print a little reminder message to tell them what notation they messed up on.

So, to enter the point '(3,-4)', the user should be able to enter any of: '(3,-4)', '3,-4)', '(3,-4', '(3 -4)', '3,-4', '3 -4)', '(3 -4', or even '3 -4'. Only the first would be quiet, however, the others would generate 1, 2, or even 3 warning/reminder messages about missing notation.

Add (Level 1) to have your input validate the user's entry format more forcefully. For this particular input, that is made tricky by the optionality of the '(', ',', and ')'parts of the traditional notation. However, if the user has entered what should be a number, make sure it is numeric. Also make sure the user only uses '(', ',', and ')'in those places — when they are entered. All the while, make sure that they can still place spaces between all parts of the point — Freedom of Input Act of 1987, remember? *grin* (Recall that, although the ws manipulator will eat any upcoming whitespace in the buffer, it treats '\n'no differently than any of the other spacing characters...and thus can cross over the user's original Enter-y.)

Add (Level 3) for using functions to break this program into manageable pieces. (I'd suggest having one for each menu option and one for the entire menu loop itself at the very least. If you see any other candidates for general re-use such as those suggested in the similar project, that may add more Levels...)

Add (Level 1) credit for re-using your point library from the options of "Point(in), out = Point". (If you didn't do this project, you can still get this Level — plus 0.5 more — by creating the library it describes.)

Add (Level 2) credit for modifying the menu so that entry of the points is an option:
```
   1) Enter point
   2) calculate Distance between two points
   3) calculate Midpoint of two points
   4) Quit
```
The user, when they choose the entry option, should get a choice of which point to enter:
```
   1) enter First point
   2) enter Second point
   3) Nevermind...
```
Choosing any option will return straight to the main menu — this submenu doesn't loop. (Choosing the third option simply doesn't enter a point before going back to the main menu.)

The distance and midpoint options from the main menu should only work after both the first and second point have been entered. If the user enters only one point, they should remind the user that two points are needed. If the user enters the same point twice (not an equal point, but First or Second point twice), while still having not entered two points, a similar message is printed (the same message, probably).

But once the user has chosen both a first and second point, you can give them any answers they choose. Also, once they've chosen two points, there should be no errors if they choose to re-enter either point.

The new interaction might look something like this:
```
$ ./pt_menu_e.out

                 Welcome to the Point Menu Program!!!

    1) Enter point
    2) calculate Distance between two points
    3) calculate Midpoint of two points
    4) Quit

    Choice:  n

I'm sorry, that choice is invalid!

Please try to read/type more carefully next time...

    1) Enter point
    2) calculate Distance between two points
    3) calculate Midpoint of two points
    4) Quit

    Choice:  m

Please enter two points before choosing this option!

    1) Enter point
    2) calculate Distance between two points
    3) calculate Midpoint of two points
    4) Quit

    Choice:  D

Please enter two points before choosing this option!

    1) Enter point
    2) calculate Distance between two points
    3) calculate Midpoint of two points
    4) Quit

    Choice:  e

    1) enter First point
    2) enter Second point
    3) Nevermind...

    Choice:  e

I'm sorry, that choice is invalid!

Please try to read/type more carefully next time...

    1) Enter point
    2) calculate Distance between two points
    3) calculate Midpoint of two points
    4) Quit

    Choice:  E

    1) enter First point
    2) enter Second point
    3) Nevermind...

    Choice:  F

Where is your first point?  (3.4, 12.2)

    1) Enter point
    2) calculate Distance between two points
    3) calculate Midpoint of two points
    4) Quit

    Choice:  3

Please enter two points before choosing this option!

    1) Enter point
    2) calculate Distance between two points
    3) calculate Midpoint of two points
    4) Quit

    Choice:  1

    1) enter First point
    2) enter Second point
    3) Nevermind...

    Choice:  1

Where is your first point?  (13.4, 12.2)

    1) Enter point
    2) calculate Distance between two points
    3) calculate Midpoint of two points
    4) Quit

    Choice:  M

Please enter two points before choosing this option!

    1) Enter point
    2) calculate Distance between two points
    3) calculate Midpoint of two points
    4) Quit

    Choice:  E

    1) enter First point
    2) enter Second point
    3) Nevermind...

    Choice:  s

Where is your second point?  (3.4, 12.2)

    1) Enter point
    2) calculate Distance between two points
    3) calculate Midpoint of two points
    4) Quit

    Choice:  M

The midpoint of the line segment from (13.4, 12.2) to
(3.4, 12.2) is (8.4, 12.2).

    1) Enter point
    2) calculate Distance between two points
    3) calculate Midpoint of two points
    4) Quit

    Choice:  d

(13.4, 12.2) is 10 units away from (3.4, 12.2).

    1) Enter point
    2) calculate Distance between two points
    3) calculate Midpoint of two points
    4) Quit

    Choice:  q

Thank you for using the PMP!!

Endeavor to have a transcendental day!

$
```

Add (Level 1) to use a switch for processing the menu. (Add another (Level 0.5) to use a switch for the submenu, if you did that option...)
