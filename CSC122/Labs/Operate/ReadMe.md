# Topical Information
This lab will help you practice with operator overloading (mixed with classes).

# Program Information
A friend has a point class that needs some help with its interface. You volunteer to help add operator overloading to the class. (No, really, you did. Don't you remember?)

You decide to overload operators for the distance between two points (operator-), input (operator>>), output (operator<<), equality (operator==), and inequality (operator!=). After a bit of arguing, you decide to also overload for midpoint (operator/).

You decide to also fix up your friend's class by adding operator= and 'missing' constructors.

Don't forget to write a small test application to show that the class still works -- new operators and all!

# Options
Add (Level 1) to overload operator[] to return the x or y part of the point. For instance:
```
   Point p(3.2, 9.8);
   double my_x;
   my_x = p['x'];   // my_x should be 3.2
```
would store the Point p's x value (3.2) for storage in my_x.
