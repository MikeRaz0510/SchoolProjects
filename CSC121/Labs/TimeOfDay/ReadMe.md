# Topical Information
This program will help you develop a useful application from output, calculations (including modulo), and library functions. It is also a good place to use constants.

# Program Information
Write a program that tells the user what time of day it is in 24-hour (military) time (AM-PM is an option below). This program will be unusual in that there will be no user input (excepting options). Simply output the time of day to the user and exit the program. Be sure to report the results neatly.

#### Hints:

The time function from the time library actually returns the number of seconds since midnight of January 1, 1970 (Greenwich Mean Time or GMT). (And, YES, you must use only the time function from the ctime library as we've learned to use it before! This is where the modulo comes in, you see!)
A day has 60*60*24 seconds in it.
People keep wanting to call the functions localtime and asctime from the standard C library ctime here. Just don't! The goal of this program is for you to code this process yourself! (And asctime leaves a mess behind you would probably forget to clean up even if you knew how!)

As an example, you might have the program interaction look something like:
```
$ ./time.out

                 Welcome to the Time-of-Day Program!!!

It is currently 12:59:59.

Thank you for using the ToDP!!

Endeavor to have a timely day!

$ ./time.out

                 Welcome to the Time-of-Day Program!!!

It is currently 13:0:9.

Thank you for using the ToDP!!

Endeavor to have a timely day!

$
```
(Note: Notice that the second time isn't terribly pretty. That's fine. If you want to fix it, see the option below.)

# Options
You may choose to alter your program from above to add any of the following (bulleted) options. You won't be handing in a separate program (unless specifically told to do so!). You will simply change the program you already have to adhere to the new specifications below. This change is considered significant enough to increase your level as stated below.

Again: do NOT create/hand-in multiple programs! Simply altering the program you have already written is enough to increase its level by the amount specified in the option you choose...


### Prettying-Up the Display
Most users just giggle. But a few are actually freaked out or even dazed. It's nothing terrible. It's not even a big thing. But the lack of 0's on your minutes and seconds (hours if you'd like) is the culprit. People just can't seem to adjust completely to a time like 10:1:7 for some reason. *shrug*

Add (Level 1) to display the time in a pretty format with leading 0's using a simple branch (as described in Chapter 3). This would make the second run above display the time as: 13:00:09.


### De-Internationalization
Well, most of the time you hear that programs and applications are moving toward more internationalization — making sure that the software will work anywhere and everywhere it is run around the world. Well, even though 24-hour format is generally considered generic and should be well understood pretty much anywhere, folks in the US can't be bothered to think quite that much on a regular basis. They like their 12-hour format and they'll hear none of this weird 24-hour mess!

Add (Level 2) to display the time in American format (AM-PM, that is) as well as 24-hour format. (Hint: This will also require a simple branch as from Chapter 3.) This would make the second run above display the time as: 13:0:9 (or 1:0:9 PM for the poor Americans). (Or something like that...*grin*)

### Re-Internationalization
But, in the sake of making things work around the world instead of just in Greenwich, England, let's localize the time reported to Chicago time (US Central).

Add (Level 1) to adjust the time from Greenwich Mean Time to US Central Time. (Hint: Check out this page for examples of GMT vs CDT/CST.)

### Time Is As Time Does
Most users want a single utility that can handle all of their needs. And since our little clock does the time of day, they'd also like to know what that day is.

Add (Level 4) to also print out the current date (day, month, and year). (Hint: This will entail using those seconds you arbitrarily removed before and breaking them down. But our calendar's months are not quite amenable to modulomanipulation... Maybe some sort of decisionstructure like those in Chapter 3 would be of help..?)

(Note: You'll find that the times are off by several hours. That's because they are the time in Greenwich, England — see the link above. Adjusting for this is an option below.)
