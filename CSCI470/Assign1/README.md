[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/3y0vnd5N)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=13467897)
# Assignment 1 - Tip Calculator #

## Problem: ##
Write a Java console program to calculate tips.  Break the code for this assignment into at least two separate classes. 

## Class TipCalculator ##

This class encapsulates the tip calculation logic.  

### Data Members ###

The class should have the following private data members:

- Bill amount (a double with the default value 0)
- Tip percentage (an integer with the default value 20)
- Party size (an integer with the default value 1)

### Methods ###

The class should have the following methods:

- A default constructor (optional)
- Public getters and setters for the three data members.
- getTotalBill() - computes and returns the total bill (bill amount plus tip).
- getIndividualShare() = computes and returns the value of an equal share of the total bill (i.e., the total bill divided by the party size).

## Class TipApp ##

This class encapsulates the user interface of the program.

### Data Members ###

- A TipCalculator object. 

### Methods ###

- main() - creates an instance of TipApp and uses it to call calculateTips().

- calculateTips() - This method will contain the logic for interacting with the user at the keyboard and displaying the output of the program.  Feel free to extract parts of this logic into other methods that are called by calculateTips().

### Approach ###

1. Create a Scanner object to read input from the keyboard.
2. Prompt for and read the bill amount.  If an invalid numeric value is entered by the user, print an error message and repeat the process until a valid value is entered.  When a valid value is entered, use it to set the bill amount data member for the TipCalculator object.
3. Prompt for and read the tip percentage.  If an invalid numeric value is entered by the user, print an error message and repeat the process until a valid value is entered.  When a valid value is entered, use it to set the tip percentage data member for the TipCalculator object.
4. Prompt for and read the party size.  If an invalid numeric value is entered by the user, print an error message and repeat the process until a valid value is entered.  When a valid value is entered, use it to set the party size data member for the TipCalculator object.
5. Call the various TipCalculator methods to produce the output.
6. Ask the user whether they want to continue and read their response.  If the response is y or Y, go back to Step 2 and repeat.

## Notes ## 

* Invalid input should include values that are not numeric (which will result in a NumberFormatException when Java attempts to convert them to a number) as well as numeric values that should not be possible. 

For example, it would be impossible to have a negative bill amount or a party size of 0.  However, a tip percentage of 0 should certainly be possible.

- Both upper- and lower-case letters should be allowed in the user’s response to the "Another Bill (y/n)?" prompt.


## Sample Run ##

```
Sample Output

A sample run of the program might look something like this:

*** Tip Calculator ***

Enter the bill amount: 105.37
Enter your desired tip percentage (20 equals 20%): 2a
Please enter a valid tip percentage.

Enter your desired tip percentage (20 equals 20%): 20
Enter the size of your party: -3
Please enter a valid party size.

Enter the size of your party: 3

*** Your Bill ***

Bill Amount: $105.37
Tip Percentage: 20%			
Party Size: 3

Total Bill (with Tip): $126.44
Share for Each Individual: $42.15

Another bill? (y/n): y

Enter the bill amount: 78.27
Enter your desired tip percentage (20 equals 20%): 23
Enter the size of your party: 2

*** Your Bill ***

Bill Amount: $78.27
Tip Percentage: 23%
Party Size: 2

Total Bill (with Tip): $96.27
Share for Each Individual: $48.14

Another bill? (y/n): N

Goodbye!1

```

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




