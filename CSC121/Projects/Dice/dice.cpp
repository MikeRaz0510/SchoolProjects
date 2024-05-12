#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cctype>
#include<limits>

using namespace std;

int main(void)
{
short num_of_dice, dice_type, pips, num, max, min, rolls, adj, menu,
opt1, opt2; //declaring variables
double avg;
char dice;
char cont = 'Y'; //continue the program, start as 'Y' so the program begins
char plus; //used if user adds an adjustment to their roll
string ind_rolls_opt = "[ON]"; //individual rolls option
string plat_size_opt = "[OFF]"; //platonic sizes option
adj = 0; //declare that if no adjustment, then it is 0


srand(static_cast<unsigned>(time(nullptr))); //Generate random numbers

cout << "\n\t\tWelcome to Mike's Dice Roller Program!\n\n"; //welcom message

while (cont == 'Y') //checking to see if the user wants to rerun the program
{
    //menu options
    cout << "MENU: Please select a number!\n\n1. Enter Dice Roll\n2. Show"
        << " Individual Rolls " << ind_rolls_opt << "\n3. Force Platonic "
        << "Sizes Only " << plat_size_opt << "\n4. Quit\n";
    cin >> menu; //reading menu input

    while (menu < 1 || menu > 4) //validating menu input
    {
        //error message and reasking for menu input
        cout << "Invalid entry! Please select a valid Option\n\nMENU: "
            << "Please select a number!\n\n1.Enter Dice Roll\n2.Show "
            << "Individual Rolls" << ind_rolls_opt << "\n3. Force "
            << "Platonic Sizes Only" << plat_size_opt << "\n4. Quit\n";

        if (cin.fail()) //if cin fails, clear and ignore
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin >> menu; //reading input
    }
    if (menu == 4) //if user selects quit, end program
    {
        cont = 'n'; //cont = n so the while loop ends
    }
    if (menu == 2) //user selects to change display individual rolls settings
    { 
        //show user if setting is on or off and ask if they what to change it
        cout << "Displaying each individual roll. Currently "
            << ind_rolls_opt << "\n1.ON\n2.OFF\n";
        cin >> opt1; //reading input

        while (opt1 != 1 && opt1 != 2) //validating setting input
        {
            //error message and asking for new input
            cout << "Invalid entry!\nDisplaying each individual roll."
                << " Currently " << ind_rolls_opt << "\n1. ON\n2. OFF\n";

            if (cin.fail()) //if cin fails, clear and ignore
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin >> opt1; //reading input
        }
        if (opt1 == 1) //turning setting on
        {
            ind_rolls_opt = "[ON]";
        }
        if (opt1 == 2) //turning setting off
        {
            ind_rolls_opt = "[OFF]";
        }
    }
    if (menu == 3) //user selects platonic sizes settings
    {
        //showing user current settings and asking if they want it on or off
        cout << "Using platonic sizes only. Currently " << plat_size_opt
            << "\n1.ON\n2.OFF\n";
        cin >> opt2; //reading input

        //validating input
        while (opt2 != 1 && opt2 != 2)
        {
            //error message and asking for new input
            cout << "Invalid entry!\nUsing platonic sizes only. Currently "
                << plat_size_opt << "\n1. ON\n2. OFF\n";
            //if cin fails, clear and ignore
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin >> opt2; //reading input
        }
        if (opt2 == 1) //turning setting on
        {
            plat_size_opt = "[ON]";
        }
        if (opt2 == 2) //turning setting off
        {
            plat_size_opt = "[OFF]";
        }
    }
    if (menu == 1) //user wants to enter a roll
    {
       
        //asking for input
        cout << "Please enter your dice roll. Example: 3d20+1\n";
        cin  >> num_of_dice >> dice >> dice_type;//reading input
             
       //if user doesnt enter a number of dice make number of dice 1
       //commented out because I cannot get it to work
       /*if (!isdigit(num_of_dice))
       {   
            
            num_of_dice = 1;
            dice = 'd';
            cin >> dice_type;//reading the dice type
            //peeking to see if there is more input after dice_type
            if (cin.peek() != '\n')
            {
                cin >> plus >> adj;//reading input
            }
       } */
        //peeking to see if there is more input after dice_type
        if (cin.peek() != '\n')
        {
            cin >> plus >> adj;//reading input
        } 

        if (plat_size_opt == "[ON]")//if plat_size_opt is on validate dice_type
        {
               while (dice_type != 2 && dice_type != 4 && dice_type != 6
                                 && dice_type != 8 && dice_type != 10
                                 && dice_type != 12 && dice_type != 20
                                 && dice_type != 100)
               {
                 //telling user to enter a platonic size and letting them know
                 //they can change the setting from the main menu
                 cout << "Not a platonic size! Please use platonic sizes! "
                      << "(You can turn off platonic sizes in the menu.)\n\n"
                      << "Please enter your dice roll. Example: 3d20+1\n";

                 if (cin.fail()) //if cin fails, clear and ignore
                 {
                     cin.clear();
                     cin.ignore(numeric_limits<streamsize>::max(), '\n');
                 }

                 cin >> num_of_dice >> dice >> dice_type;//reading input

                 //if user doesnt enter a number of dice make number of dice 1
                 //commented out because I cannot get it to work
                 /*if (!isdigit(num_of_dice))
                 {
                     num_of_dice = 1;
                     dice = 'd';
                     cin >> dice_type;//reading input

                     if (cin.peek() != '\n')//peeking for aditional input
                     {
                         cin >> plus >> adj;//reading aditional input
                     }
                 }*/
                 if (cin.peek() != '\n')//peeking for aditional input
                 {
                     cin >> plus >> adj;//reading aditional input
                 }
               }
        }
      
            //important calculations
            min = num_of_dice + adj; 
            max = num_of_dice * dice_type + adj;
            avg = static_cast<double>(min + max) / 2;//cast to double 

            //resetting importatn variables from previous runthroughs
            pips = 0;
            num = 0;
            rolls = 1;

            //rolling dice individualy
            while (rolls <= num_of_dice)
            {
                pips = rand() % (dice_type - 1 + 1) + 1;
                if (ind_rolls_opt == "[ON]")//display rolls if setting is on
                {
                    cout << pips << " ";

                    if (rolls % 20 == 0) // start a new line every 20 rolls
                    {
                        cout << endl;
                    }
                }

                num = num + pips; //calculating total roll
                
                rolls++; //counting each roll
            }

            num = num + adj; //calculating example roll

            //printing out results and asking if they want to roll again
            cout << "\nexample roll: " << num
                << "\nmin roll: " << min << "\nmax roll: "
                << max << "\naverage roll: " << avg << "\nWould you like to"
                << " roll again? Please type Yes or No.\n";
            cin >> cont;//reading input anything other than Y ends the program
            //ignore extra input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            //changing input to uppercase
            cont = toupper(cont);
        }
    }
    return 0;
}
