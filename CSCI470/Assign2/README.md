[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/bt71BgAf)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=13582198)
# Assignment 2 - Frequent Flyer #

## Problem ##
Write a console-based Java application for a travel agent to present options for travel destinations to a client who wants to redeem their accumulated frequent flyer miles.  
We assume all trips depart from O'Hare International Airport and  the miles represented are required for a roundtrip ticket.  

Depending on the distance, each destination requires a different number of frequent flyer miles to obtain a roundtrip ticket.  If the client travels during the off-season, they may take advantage of the “Frequent Flyer” option requiring fewer miles for a roundtrip ticket to a destination.

### Input File ###
A list of destination cities and related ticket redemption information will be read from a file (one named destinations.txt is provided for you but you may create your own).  The file is formatted with one city, or destination, per line, with the first five fields separated by a semicolon ( ; ) and the last two separated by a hyphen ( - ) as shown in the example below.  

The six items for a single destination represent:
- The destination city name.
- The normal mileage needed for an economy class ticket
- The “Frequent Flyer” mileage needed for an economy class ticket
- The additional mileage needed for upgrading to first class
- The beginning month of departure when  “Frequent Flyer” mileage can be used instead of the normal mileage 
- The ending month when “Frequent Flyer” mileage can be used instead of the normal mileage

### Example Input File: ###
```
Berlin;17250;12750;5250;3-5
Hong Kong;30000;20250;17500;2-4
Hyderabad;30000;20000;15000;2-4
Sidney;50000;30000;20000;5-6
Paris;20000;15000;10000;2-4
New York;10000;5000;8000;10-11
Tokyo;29000;16500;5350;2-5
Vienna;17500;12500;5000;2-4
Washington, D.C.;9000;7500;2000;10-12
```

### Redemption Algorithm ###
Your algorithm should:
1. Get tickets that travel the furthest.
2. Use “Frequent Flyer” mileage whenever possible 
3. Display as many different tickets as possible given the information after you determine the destinations where can fly, 
4. Determine if you can use the remaining mileage for upgrade for any of the eligible destinations  (Upgrade the longest trip first, then the next-to-longest - if there is one, etc.).

## The Classes ##

### Class: Destination ###
This class  encapsulates:
- Destination City Name 
- Normal miles required for a ticket
- “Frequent Flyer” miles
- Additional miles for upgrading
- "Frequent Flyer" program start month  
- "Frequent Flyer" program end month 
-  Getters and setters are needed 

### Class: MileRedeemer ###
This class encapsulates the logic for redeeming mileage.  

#### Data ####
- Array of Destinations
- Remaining miles after redemption.

#### Methods ####
- public void readDestinationInfo(Scanner fileScanner) -
    - Use a Scanner object as the input parameter for flexibility and reusability.  This could be reused to read files from different sources.  
    - Use the Scanner object to read and parse the destination data into an array of Destination objects.
    - The method should output a sorted array of Destination objects in descending order by normal mileage (see more information about sorting below).

- public String[] getDestinationNames()
    - Loop through the Destination objects and create an array of strings from the city names.  
    - Return an ascending, sorted array for printing all possible destinations.

- public String[] redeemCustomerMiles(int miles, int month)
    - miles is the total available miles
    - month is the desired month of departure.  
    - To avoid writing one huge method, you should have the redeemCustomerMiles() method call other methods to make the overall algorithm clearer. 
    - Return an array of String  describing redeemed tickets to be printed out by the main program. 
    - Save the remaining miles after the tickets redemption.

* public int getLeftoverMiles( )
    - Returns remaining miles.

### Class: MileRedemptionApp ###
This is the main application and will drive the entire process.

#### High Level Algorithm ####
1. Declare a Scanner object for the keyboard and prompt the travel agent for the filename containing destinations.  
2. Read the destination records from the file and create your array of destination objects in readDestinationInfo
3. Print the list of all possible destinations.  
4. Prompt the travel agent for the client's Frequent Flyer Miles balance and for the client's month of departure.  
5. Call redeemCustomerMiles( ) to determine the destinations available for the client and present them to the travel agent. 
    -If redeemCustomerMiles( ) returns an empty array, print an appropriate message such as:
    - *** Your client has not accumulated enough Frequent Flyer Miles ***
6. Display remaining Frequent Flyer Miles  after determining the available destinations.
7. After presenting the  destinations and remaining miles, prompt the travel agent to start over.  
   - Do not ask for a new file name D
   - Do not print the header statement 
   - Do not print the list of all possible destinations again.  
   - If the  agent answers y/Y/yes/Yes or 'yes' or 'Yes' prompt the user to enter the client's Frequent Flyer Miles and departure month and determine a new list of possible destinations.

### Class: MileageComparator ###

#### Methods ####
public readDestinationInfo() 
    - The cities in the input  file will probably be out of order based on normal miles.  
    - Sort them in descending normal miles order before any redemptions can be done.  
    - The class java.util.Arrays has a static sort( ) method that takes an array and a Comparator.  
    - See Below for how to define the comparator.

    ```
    public class MileageComparator implements Comparator<Destination> 
    {
        public int compare(Destination dest1, Destination dest2) 
        {
            return (dest2.getNormalMiles() - dest1.getNormalMiles());
        }
    }
    ```

    Alternatives to this class include creating an inner class. Different way to implement the Java Comparator.  For example, create an inner class.

#### Note ####
The array of city names returned by getDestinationNames() can also be sorted using a version of Arrays.sort( ).  There's no need to write a Comparator here, as the “natural ordering” of  strings will be sufficient.


### Programming Notes ###

#### Input Validation ####
You do not to do any input validation.

#### File I/O and String Parsing ####
Use the Scanner class to read  lines from the file and parse them in an array list.


(Sample exact output follows)


Exact Program Output Using the Mileage to Destinations.txt File Provided

Please enter the name of the file:  Mileage to Destinations.txt

----------------------------------------------------------------
WELCOME TO THE JAVA AIRLINES FREQUENT FLYER MILES REDEMPTION APP
----------------------------------------------------------------

List of destination cities your client can travel to:

Berlin
Hong Kong
Hyderabad
New York
Paris
Sidney
Tokyo
Vienna
Washington, D.C.f

----------------------------------------------------------------

Please enter your client's accumulated Frequent Flyer Miles:  49600

Please enter your client's month of departure (1-12):  4

Your client's Frequent Flyer Miles can be used to redeem the following tickets:

* A trip to Hong Kong in Economy Class 
* A trip to Hyderabad in Economy Class 
* A trip to Washington, D.C. in Economy Class

Your client's remaining Frequent Flyer Miles: 350

----------------------------------------------------------------

Do you want to continue (y/n)? y

----------------------------------------------------------------

Please enter your client's accumulated Frequent Flyer Miles:  3421

Please enter your client's month of departure (1-12):  3

*** Your client has not accumulated enough Frequent Flyer Miles ***

Your client's remaining Frequent Flyer Miles: 3421

----------------------------------------------------------------

Do you want to continue (y/n)? y

----------------------------------------------------------------

Please enter your client's accumulated Frequent Flyer Miles:  154351

Please enter your client's month of departure (1-12):  7

Your client's Frequent Flyer Miles can be used to redeem the following tickets:

* A trip to Sydney in Economy Class 
* A trip to Hong Kong in Economy Class
* A trip to Hyderabad in Economy Class
* A trip to Tokyo in First Class 
* A trip to New York in Economy Class

Your client's remaining Frequent Flyer Miles: 1

----------------------------------------------------------------

Do you want to continue (y/n)? n

-------------------------------------------------------------------------
THANK YOU FOR USING THE JAVA AIRLINES FREQUENT FLYER MILES REDEMPTION APP
-------------------------------------------------------------------------


# Grading Details #
## Header ##
  - Comment header must be present and must precisely match the followinng text.  
    - No changes, deletions or extra spaces.  Name, And student Id must be present.
     ```
     // *************************************************************************** 
     // 
     //   Your Name 
     //   Your NIU ID
     //   Your Course and Section Number 
     // 
     //   I certify that this is my own work and where appropriate an extension 
     //   of the starter code provided for the assignment. 
     // ***************************************************************************
     ```
     - If this header is not present there will be a 20 Point deduction.
   ## Correctness of assignment: 50 Points ##  
   - Does it do what its supposed to?   Does it meet the requirements of the assignment?
  ## Coding Conventions 20 Points ##
    - Variables are named meaningfully 
    - Code is consistently formatted using an evident style
    - Comments are used where appropriate
    - Classes are in seperate files.
    - .h and .cpp files are used appropriately.
   ## Input and output 30 points ##
   - Program displays input as shown and output as shown.  Accurately formatted text is required.
  
  # If your program does not compile and run, your grade will automatically be a zero
 
## Total: 100 points ##

Submit your project using Visual Studio Code with Java extensions or the git command line


