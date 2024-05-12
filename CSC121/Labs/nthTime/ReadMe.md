# Topical Information
This program gives you continued practice with branching, looping, and even a little bit of string play...well, storing and printing them, anyway...*shrug* (But perhaps more importantly, you'll also get to work with integer math again!) (And not justwithin the context of random number generation...)

# Program Information
Write an algorithm which can store into a string variable the two letters which are the proper suffix of a particular integeras typically used for printing.

To test your algorithm, embed it in a program which reads an integer from the user and then displays it and its suffix form.

For example, if the user entered the value 1, you would place 's'and 't'into the string and display their number and your string (because 'first' is also represented as '1st' -- and since we can't exactly do 1st -- i.e. superscripting -- without more font control than a terminal window typically allows).

To refresh your memory, the pattern for suffices (suffixes?) is:
```
   1st   2nd   3rd   4th   5th   ...  10th
  11th  12th  13th  14th  15th   ...  20th
  21st  22nd  23rd  24th  25th   ...  30th
  31st  32nd  33rd  34th  35th   ...  40th
  ...
 101st 102nd 103rd 104th 105th   ... 110th
 111th 112th 113th 114th 115th   ... 120th
 121st 122nd 123rd 124th 125th   ... 130th
  ...
 201st 202nd 203rd 204th 205th   ... 210th
 211th 212th 213th 214th 215th   ... 220th
 221st 222nd 223rd 224th 225th   ... 230th
  ...
```
To test your program, ensconce it within a yes/no style loop to allow ease of testing.

As an example, you might have the program interaction look something like (the parts in this coloration are typed by the user):
```
$ suffix_test.out

                 Welcome to the Suffix Testing Program!!!

Enter a value: 1

That would be the 1st.

Test another value?  You bet!

Enter a value: 11

I'd have to say the 11th.

Test another value?  yes

Enter a value: 534252

That sounds like it could be the 534252nd.

Test another value?  nyeah

Thank you for using the STP!!

Endeavor to have a purple-textured day!

$
```
# Options

Add (Level 2) to use functions to break your program into more manageable pieces. I'd recommend the display of the result go into a function to de-clutter the main.
In fact, you can probably break out another function from the results-display: the random pre-message generation. If you do, I'll throw in another (Level 1.5) to make justthe random number formula into an inline function.

You can add a special (Level 1.5) to place your suffix-determining code in a generic/re-usable function.

Add (Level 1.5) to place your suffix function in a library.

Add (Level 1.5) to place your random number generation function in a library.
