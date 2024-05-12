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
### Toward a More Natural Manner of Input
Students are complaining that their teacher makes them use standard ordered pair notation for points in class, but your program makes them enter points without the notation. They are getting frustrated and some even confused.

Add (Level 1) to forcethe user to enter the end points of the segment in normal, ordered-pair style (with parenthesis surrounding the coordinates and a comma between them).

The program interaction might now look something like (the parts in this color are typed by the user):
```
$ ./midpoint.out

                 Welcome to the 2D Midpoint Program!!!

What is the first end-point?  (3.4, 12.2)
What is the second end-point?  (13.4, 12.2)

Thank you!!  Calculating...  Done.

The midpoint of the line segment between (3.4, 12.2) and (13.4, 12.2)
is (8.4, 12.2).

Thank you for using the TMP!!

Endeavor to have a voracious day!

$
```
