# Topical Information
This project will help you show your mastery of arrays, classes, and libraries.

# Program Information
Write a program to allow the user to calculate the distance between cities on a map.

Sounds pretty complicated, eh? Don't worry, we'll make a few simplifications here:

The distances are calculated in map units on the 2D map.

Each city is given a set of coordinates relative to some point on the map. We'll call this origin (0,0).

There can only be a finite number of cities in the system at a given time (you decide this maximum).

But in order to make the system useful, we'll have to add a few other features:

Each city has a name in addition to its coordinates (you can assume a maximum length for these names; but they must be able to hold spaces: Los Angeles, New York, etc.).

The user selects what action to take from a menu:

    1) Enter city Information
    2) calculate Distance between two cities
    3) Print All cities
    4) Quit
Make sure you allow them to choose their options by both the number and the capitalized letter(s) of the choice.

They cannot calculate a distance until at least two cities have been entered.

When they have exactly two cities, assume they are the ends and print their distance.

When they have more than two cities, show them the list of cities and have them pick the two cities to calculate the distance between. Don't let them choose the same city for both ends of the 'trip'.

If your list is full and they choose to enter another city, have them choose to either NOT enter the new city or to overwrite one of the earlier cities (they choose which one). Print the list of cities for them to choose from. (Remember, you still can't exceed your maximum list size!)

For those last two when you list the cities for them to choose, I'm assuming you'll do a numbered list and have them enter the position number of the city they are interested in. If you want to make it nicer, see the option below.

Hint: You should have at least 2 classes — possibly 3 (see the options below). One will be Point— from the examples. (And, yes, you must use it as is!) Another should be a Cityclass almost exactly like:

    const size_t MAX_CITY_NAME = ???;
    class City
    {
        Point location;
        char name[MAX_CITY_NAME];
    public:
        double distance(const City & other) const
        {
            return location.distance(other.location);
        }
        Point get_location(void) const
        {
            return location;
        }
    // other methods and constructors here
    };
but with additions as noted. (But otherwise identical!)

Don't forget to separate all the details of city handling from the details of list management.

Hint: Each class should be in its own library. Other libraries may also be used for collections of useful functions.

# Options
You may choose to alter your program from above to add any of the following (bulleted) options. You won't be handing in a separate program (unless specifically told to do so!). You will simply change the program you already have to adhere to the new specifications below. This change is considered significant enough to increase your level as stated below.

Again: do NOT create/hand-in multiple programs! Simply altering the program you have already written is enough to increase its level by the amount specified in the option you choose...

Add (Level 2) to detect whether the user entered a number or a name at prompts involving a list of the cities (including overwrite and distance). If they've entered a number, proceed as normal. If they've entered a name, use a search to decide which city it was. (If the name 'matches' multiple cities, you should print a new — hopefully smaller — list of the matches for them to choose from.)

Add (Level 2.5) to let them both load and save city information from/to files. You can decide the format of the city information file. Note: you'll have to add a save option to the menu (or a question under 'print') and you'll have to ask if entry should come from the keyboard or a file. (Hint: You shouldn't need a new function to handle loading from a file — your current entry function should work fine with a little tweaking of the argument(s).)

Add (Level 4) to use a labeled block data format for your city files. This will require the use of a set of string translation functions for at least string and double data. (To receive full option credit all translations must be supported — even those not used in this application.)

Hints: What kind of default values might you have if the user leaves out an item from the data block? What items make up a block of data? (Will you just have to teach the city to do block data or will you also have to teach your point?)

Add (Level 3) more if your 'labeled' format is XML (or at least XML-like). XML uses a system of tags similar to HTML. The example file from the related lab might look like this as XML:
```
<student>
    <name>Jason James</name>
    <id>123456</id>
    <gpa>9.2</gpa>
    <grade>B</grade>
</student>
<student>
    <name>Tammy James</name>
    <gpa>11.2</gpa>
    <grade>A</grade>
    <id>123457</id>
</student>
<student>
    <name>Henry Ramirez</name>
    <gpa>12.3</gpa>
    <id>111888</id>
    <major>ChE</major>
    <class>soph</class>
</student>
<student>
    <id>788531</id>
    <name>Suzie Shah</name>
    <grade>Q</grade>
</student>

```
Note how some problems mentioned in that lab are removed by the rigid structure but others are created. Here's a brief introduction to the syntax of XML.

Add (Level 3) to add a submenu to sort the city list. The submenu should allow the user to choose whether to sort by name, x coordinate, or y coordinate. (Note: You can't simply sort by location since there is no way to compare 2D points without reference to a common line.) Just like the main menu, your submenu choices should be choosable by either their number or their capitalized letter. Have a fourth option to return to the main menu. (Implying that you'll stay in the submenu until they choose that option.)

Tip: Have your class provide a compare method which returns similarly to strcmp (negative, 0, or positive). Its arguments should be a string to compare with and some indication as to which of the data fields to compare the string to (maybe a char or short with provided constants the caller could pass; maybe even an enumeration!). Something like:

    enum CompTo { Name, X_coord, Y_coord };
    class City
    {
    public:
        short compare(const char comp_this[]);  // compare name
        short compare(double comp_this, CompTo to_member);   // compare coord
        short compare(const Point & comp_this, CompTo to_member);   // compare coord
        short compare(const City & comp_this, CompTo to_member);  // compare anything
    };
Tip: If you remember that the list is sorted on item X, you can use a binary search when they search for an entry by Xnext time.

Add (Level 2) to mark entries as deleted instead of shifting all remaining entries down in the list. This will affect print, save, sort (if you did that option), and even add. (How, after all, will add know the list is full if there are entries missing in the middle that can be used?) Will this affect your ability to binary search instead of linear search for sorted fields?

You can even add another (Level 2) to implement an undelete feature that shows them the previously deleted entries and allows them to put them back into place in the list.

Add (Level 2) to add a third class to manage the city list. This will keep the main uncluttered by list management details. (This can be difficult, though. Keep straight in your head what is a city behavior and what is a list behavior!)

To help you get started:

    const size_t MAX_CITY_LIST = ???;
    class CityList
    {
        City list[MAX_CITY_LIST];
        size_t current;
    public:
        bool full(void) const { return current == MAX_CITY_LIST; }
        bool empty(void) const { return current == 0; }
        City get(size_t index) const;
        size_t get_num_cities(void) const { return current; }
        void set(size_t index, const City & new_city);
        bool add(const City & new_city);
        // other methods and constructors
    };
