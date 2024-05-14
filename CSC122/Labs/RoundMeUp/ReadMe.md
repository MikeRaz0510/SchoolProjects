# Topical Information
This lab will help you practice simple data processing from a file where you don't know the amount of information in the file ahead of time. (It also provides some refresher in basic statistics.) (classes may or may not be of use here...you decide!)

# Program Information
Write a program that calculates basic statistics for a set of numbers stored in a file. Make sure to allow the user to tell you the name of their file and to check for file open errors.

The data in the file will be a space-separated list of numbers. You won't know the length of the list ahead of time. You'll need to calculate the average and standard deviation of the list as well as determining the maximum and minimum for the data. To refresh your memory, the standard deviation is the square root of the variance. And the variance? Well, it is found as discussed in this brief paper. (Make sure to read it carefully all the way through!)

You can choose the actual values to use for the data. Make sure to do enough differentsets of data to test your program well! (I'd recommend an empty file, the example below, and a file with lots of numbers.)

Remember that your program cannot know how many data points are in the file ahead of time! (In such a situation, you should never try to read the entire file into memory. Process the file element-by-element without holding onto more than a single piece of data at a time.)

Don't forget to read the file's name from the user and protect your program against any errors that may occur during the opening of the file.

As always, try to use functions to break up the program into more manageable pieces.

As an example, you might have the data file contain:
```
1 2 3 4
5 6 7 8

9 10
```
and the program interaction might look something like (the parts in this color are typed by the user):
```
$ ./statnumbs.out

                 Welcome to the Number Statistics Program!!!

Please enter the name of your data file:  bob.dat

I'm sorry, I could not open 'bob.dat'.  Please enter another name:
values

File 'values' opened successfully!

Reading data from 'values'...

Calculating...

Done processing data!

For your data, the statistics are as follows:

     Count:  10
   Minimum:  1
   Average:  5.5
   Maximum:  10
    StdDev:  3.02765

Thank you for using the NSP!!

Endeavor to have a undulating day!
```
$
