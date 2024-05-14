# Topical Information
The purpose of this project is to test your ability to use files, class design, operator overloading, and Strings or strings effectively in program design.

# Program Information
Create a program which will read a phrase from the user and create a framed version of it for printing. For example, the phrase "hello world"would always result in:
```
   *********
   * hello *
   * world *
   *********
```
Whereas the phrase "the sky is falling"might be:
```
   ***********
   * the     *
   * sky     *
   * is      *
   * falling *
   ***********
```
Or:
```
   ***********
   *   the   *
   *   sky   *
   *   is    *
   * falling *
   ***********
```
Or even:
```
   ***********
   *     the *
   *     sky *
   *      is *
   * falling *
   ***********
```

Depending on whether or not the user asked for left, centered, or right justification — respectively — of the phrase's words within the frame. Note how the frame exactly fits the phrase based on the longest word within. Neat, eh? (Makes "Hello World" seem like a bad test case, doesn't it?)

The phrase "O | -+- | /-\"when centered would become:
```
    *******
    *  O  *
    *  |  *
    * -+- *
    *  |  *
    * /-\ *
    *******
```
(Okay, so it's a sad excuse for a stick figure, but hey! I've never claimed to be a great good decent artist, now have I? *phbbt*)

Also allow the user to specify what character you are to make the frame from. Typical choices would be @, #, *, +, x, X, o, or O. But let them tell you anything that will print just fine. (Hint: cctype has a function called isprint that tells if a character is printable.)

Give them the option of reading phrases from the keyboard or a file they specify (assume each line of the input stream contains a single phrase).

The user should also be able to choose if the framed phrase is printed on the screen or into a file they specify.

In case it isn't clear, you should create a 'frame the phrase' class. It should have overloaded operators for at leastinput and output. (Although concatenation might prove interesting, too...)

# Options
You may choose to alter your program from above to add any of the following (bulleted) options. You won't be handing in a separate program (unless specifically told to do so!). You will simply change the program you already have to adhere to the new specifications below. This change is considered significant enough to increase your level as stated below.

Again: do NOT create/hand-in multiple programs! Simply altering the program you have already written is enough to increase its level by the amount specified in the option you choose...

Add (Level 1.5) to add a choice of frame types: single line, double line, or shaded. For instance:
```
    +---------+     +============+      +--------+    +=======+
    |         |     ||          ||      |        |*   ||     ||#
    |         |     ||          ||      |        |*   ||     ||#
    +---------+     +============+      +--------+*   +=======+#
                                         **********    #########
```
You don't have to allow them to choose the framing character when they are using anything of these options.

Add (Level 1) to make a nice menu to set up these options and include in the menu save and load options. This option configuration should also be automatically read at program startup time — if it exists.

Add another (Level 1) to make this options configuration file a nice labeled format suitable for human editting.

Add another (Level 1) to allow the user to specify what file to use for reading in option configuration information at the command-line.

Add another (Level 1) to allow the user to specify what file to use for reading in option configuration information with an environment variable you specify the name of.

Add (Level 2.5) to combine this project with the templated Array lab. Hmm...where would you use the array?

This option is not combinable with the templated linked list option!

Add (Level 3.5) to combine this with a templated linked list class. Hmm...where would you use such a data structure?

For full credit, your linked list must implement all insertion and removal functions that would be generally useful — not just those you'll use here.

This option is not combinable with the templated dynamic array option!
