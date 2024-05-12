[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/SCPgVqGK)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=14060828)
# Assignment 3 – Classes, Objects, and Methods #

This programming assignment is  intended to strengthen your knowledge about classes, objects, and methods.


## Create A Class ##

### Class Name: USMoney ###
Represents money in dollars and cents, expressed as integers
#### Data ####
  - int dollars 
  - int cents
  - Provide getters and setters where appropriate

#### Methods ####
- Constructor with two parameters for initializing a USMoney object.  
    - Validate cents value is between 0 and 99. If not, transfer some of the cents to the dollars variable to make it between 0 and 99.

- plus() takes a USMoney object as its parameter.  
    - Returns a new USMoney object representing the sum of the object and the parameter.  
    - The plus() method does not modify the values of the two existing objects.  
    - Ensure that cents on the new object is between 0 and 99.
    - Example:     
        - x is a USMoney object with 5 dollars and 80 cents
        - y is a USMoney object with 1 dollar and 90 cents
        - x.plus(y) = new USMoney object with 7 dollars and 70 cents.

### Class Name: USMoneyTester ###
Test class for USMoney
- Prompt the user twice, once for the first USMoney object, and then for the second.
- Tests all functions


### Class: MyDate ###
Represents a date with day, month and year properties (all integer)

#### Data ####
- int day
- int month
- int year

#### Members ####
- constructor with three parameters 
- daysSinceJan1() - # of days since Jan 1 of the year specified in the date inclusive.  


### Class: MyDateTester ###
Test class for MyDate class.
- Prompt the user to enter an integer  day, a second prompt to enter an integer month and a third to enter an integer 
- Instantiate your Date object with these values.  
- Call the method DaysSinceJan1() to display the answer.

Example:
-  User enters values of day = 1, month = 3, and year = 2019
-  myDate.daysSinceJan1() should return 60 as there are  60 days between  January 1, 2019, and March 1, 2019.  
-  In leap years, it should return 61.  
    - In a leap year like 2024 there will be one more day between January 1 and any date following February 28.  What
    - Rules for leap years - 
        - If the year is evenly divisible by four, then it is a leap year except when its divisible by 100. Unless its divisible by 400. 
        - The  year 2000 WAS a leap year but 1900 was NOT a leap year.  
        - Neither were 1700 or 1800 and neither will be 2100 but 1600 was.

### You may NOT use an Array or ArrayList (or any other type of array) and you may not use any of the Java API date classes and/or methods. ###

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
