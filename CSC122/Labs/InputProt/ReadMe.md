# Topical Information
This lab will help you practice with input validation, arrays, C-strings, and libraries. Function overloading might come in handy, as well.

# Program Information
When the user is expected to enter a value, that value is often under some kind of constraints from the problem we are solving. For instance, a time must be non-negative, a correlation coefficient must lie between -1and +1, a menu choice must be one of a particular set of values (menu-dependent). Such input validation is easily done with a while loop:

    prompt & read
    while (!valid)
    {
        error message
        prompt & read
    }
But this can become tedious if you have to redesign it or alter the code EVERY time you must use it. To make things easier, we can simply place this loop in a function for easy re-use.

Upon examining several specific instances, we see that the main things that change are the variable you are entering, the bounds/values to be used, and the prompts/messages printed to the user. All of these can easily be parameterized using a function. The bounds could be passed as arguments. So could the prompts and messages (C-string arguments?). And the variable entered would simply be assigned upon return from the function (the return value)!

You decide to write some generalized input-validation functions. To make them even more re-usable, you'll place them in a library called input_prot(for input protection). You figure that you need to be able to handle the following situations:

entry bounded at both ends of a range (i.e. grades between 0..100)

entry bounded at the lower end of a range (i.e. time greater than 0)

entry bounded at the upper end of a range (rare, but it does happen)

entry limited to those elements in a particular list of values (i.e. menu choices)

By overloading your functions for use with ALL of the major data types (double, long, and char) you'll almost never have to re-write that validation loop again! (You can skip float and short since they are subsets of double and long. You can skip bool as it can't be directly entered.

You'd probably call the char one with a list of "YyNn"...or some such... and store whether the upper-case of the result was equal to 'Y'or not, right? That is, you'd code something like:

    bool ans;

    ans = toupper(input_protect("\nWould you like to continue?  ",
                                "Please enter Yes or No only!\a\n",
                                "YyNn"))
            == 'Y';
in your main program for a bool entry.)

Of course, to make sure all your validation functions work properly, you'll have to write a driver for this library. (A driver is basically a test application that tests ALLthe functions in the library — at least once. See the library notes for more tips.)

# Options

Add (Level 0.5) to have the prompts and messages to default to certain application-inspecific values where possible.

Add (Level 1) to have as few overloaded functions as possible. One could solve the above lab with 12 functions, obviously. But can you code it in fewer? (Overloaded inline helper functions don't count against the total since they are just a few lines of code each. I'm more focused on the work-horse functions here — avoiding replication of major effort.)

Add (Level 2) to allow the user to enter a valid value or abort the entry.

