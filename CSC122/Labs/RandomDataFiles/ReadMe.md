# Topical Information
This lab should provide you with practice in file handling, libraries, and random variate generation.

# Program Information
Write a program that allows the user to create files of random data. They should be offered a menu of possibilities:

    1) create random Whole number data file
    2) create random Decimal number data file
    3) create random Character data file
    4) Quit program
The first 3 options should ask for appropriate bounds. Your program should make sure they are in order before passing them to your random value generation function. (The overloaded ones we did in class, remember? — place these in a 'random' library.)

Then, ask how many random values to generate and what file to place them in. Assuming the file opened correctly, proceed to generate all requested random values.

The menu should continue to loop until the quit option is chosen. Options should be choosable by either the number or the capitalized word. (For example, to quit, they should be able to enter 4, Q, or q.)

# Options
You may choose to alter your program from above to add any of the following (bulleted) options. You won't be handing in a separate program (unless specifically told to do so!). You will simply change the program you already have to adhere to the new specifications below. This change is considered significant enough to increase your level as stated below.

Again: do NOT create/hand-in multiple programs! Simply altering the program you have already written is enough to increase its level by the amount specified in the option you choose...

(Note: If the option includes its own TPQs, you mustanswer them in addition tothe ones above to earn the full credit!)

Add (Level 2) to add another option (shift the quit option down appropriately):

    4) create random Name data file
This fourth option should ask for a file of given names and a file of family names. If both those files open successfully, ask how many names each person should have (given; given and family; given, middle, and family; etc.). (Hint: middle names are typically the same as most given names, but may occasionally be a family name. My estimate is 80% of middle names were once given names and the remaining 20% were probably family names.)

Once you know how many random names to create and what file to store them in (and that file opened successfully), you'll need to pick names from either the given name file or the family name file (or both) and store them to the output file. To do this quickly, it might help to pre-process the given/family name files to count how many of each you have and figure out where each name starts in the file (an index, perhaps?). Once you know how many names, you can pick a random one easily (a random integer between 0and the number of names-1).
