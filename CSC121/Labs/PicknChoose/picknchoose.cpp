#include<iostream>
#include<cmath>
#include<limits>
#include<cctype>
#include<string>

using namespace std;

//function prototypes
void point(double& x, double& y, string f_or_s);
void distance(double x1, double x2, double y1, double y2);
void midpoint(double x1, double x2, double y1, double y2);
void menu(double& x1, double& x2, double& y1, double& y2,
          bool& point1_entered, bool& point2_entered);
void sub_menu(double& x1, double& x2, double& y1, double& y2,
              bool& point1_entered, bool& point2_entered);
void punct(char& punct_check, char act_punct, short& error, bool end);

int main(void)
{
    //declaring vairables
    double x1, x2, y1, y2;

    //entered points start false because nothing is entered.
    bool point1_entered = false,
        point2_entered = false;

    //run the menu function
    menu(x1, x2, y1, y2, point1_entered, point2_entered);
    return 0;
}

//this function calculates the distance between
//the 2 points the user has entered. It takes in 
//the x and y values. it calculates the distance 
//and prints out a message with the results
//it returns nothing
void distance(double x1, double x2, double y1, double y2)
{
    //declaring local variables
    double x, y, dist;

    //caluclations
    x = x2 - x1;
    y = y2 - y1;
    dist = sqrt(pow(x, 2) + pow(y, 2));

    //displaying the distance
    cout << "The distance between the points"
        << " (" << x1 << ',' << y1 << ") and ("
        << x2 << ',' << y2 << ") is " << dist
        << endl;

    return;//return
}

//this function calculates the midpoint between
//the 2 points the user has entered. It takes in 
//the x and y values. it calculates the midpoint
//and prints out a message with the results.
//it returns nothing
void midpoint(double x1, double x2, double y1, double y2)
{
    //declaring local variables
    double xM, yM;

    //calculations
    xM = (x2 + x1) / 2;
    yM = (y2 + y1) / 2;

    //displaying the results 
    cout << "The midpoint on the line segment"
        << " between the points (" << x1 << ',' << y1 << ") and ("
        << x2 << ',' << y2 << ") is (" << xM << ',' << yM << ").";
    return;//return
}

//this function controlls the main menu of the
//program. it also displays the status of the
//entered points. it takes in the 4 x and y
//coordiantes of the 2 points by reference
// and the two bool variables controlling the
//status message. it returns nothing
void menu(double& x1, double& x2, double& y1, double& y2,
    bool& point1_entered, bool& point2_entered)
{
    //declaring local variables
    char menu;
    bool repeat = true;//repeat is true until the user quits
    string status = "[Need to enter points]";//starting status

    //do/while loop that runs until the user quits
    do
    {
        //change the status messge if both points entered
        if (point1_entered && point2_entered)
        {
            status = "[2 points entered]";
        }
        //change the status messsge if one point entered
        else if (point1_entered || point2_entered)
        {
            status = "[1 points entered]";
        }

        //the main menu
        cout << "\n\tMain Menu:\n1: Enter points\t" << status
            << "\n2: calculate Distance between two points\n3:"
            << " calculate Midpoint of two points\n4: Quit\n";

        cin >> menu;//reading menu input

        //ignoring extra input 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        //making the users choice uppercase
        menu = toupper(menu);

        //showing the user what they entered
        cout << "\nYou chose " << menu << '\n';

        //switch to chose and action based on menu choice
        switch (menu)
        {
        case '1': case 'E':
        {
            //go to submenu
            sub_menu(x1, x2, y1, y2, point1_entered, point2_entered);

        } break;
        case '2': case 'D':
        {
            //if both points entered
            if (point1_entered && point2_entered)
            {
                //calculate distance
                distance(x1, x2, y1, y2);
            }
            else
            {
                //error message
                cerr << "Both points not entered! Enter both points "
                    << "before calculations\n";
            }

        } break;
        case '3': case 'M':
        {
            //if both points entered
            if (point1_entered && point2_entered)
            {
                //calculate midpoint
                midpoint(x1, x2, y1, y2);
            }
            else
            {
                //error message
                cerr << "Both points not entered! Enter both points "
                    << "before calculations\n";
            }

        } break;
        case '4': case 'Q': case 'X':
        {
            //user chose to quit stop repeating the menu
            repeat = false;

        } break;

        //catch all invalid inputs
        default:
        {
            //error message
            cerr << "Invalid entry! Please select "
                << "a menu number or capitalized"
                << " letter!\n";

        }break;
        }
    } while (repeat);
    return;
}

//this function controlls the submenu where
//the the user enters points. it takes in the 4
//x and y coordiantes of the two points by 
//reference. it also takes in the bool vairables 
//controlling the status of the point entry.
//it retuens nothing
void sub_menu(double& x1, double& x2, double& y1, double& y2,
    bool& point1_entered, bool& point2_entered)
{
    //declaring local variables
    char sub_menu;
    string point1, point2;

    //setting point1
    if (!point1_entered)
    {
        point1 = "(???,???)";
    }
    else
    {
        point1 = '(' + to_string(x1) + ',' + to_string(y1) + ')';
    }

    //setting point 2
    if (!point2_entered)
    {
        point2 = "(???,???)";
    }
    else
    {
        point2 = '(' + to_string(x2) + ',' + to_string(y2) + ')';
    }

    //the sub menu
    cout << "\nEnter Points Menu\n1: enter First point.\t" << point1 
        << "\n2: enter Second point.\t" << point2 << "\n3: Main Menu.\n";

    cin >> sub_menu; //reading input
    cin.ignore(numeric_limits<streamsize>::max(), '\n');//ignoring extra input

    //making the users choise uppercase
    sub_menu = toupper(sub_menu);

    //switch to decide on an action the user chose
    switch (sub_menu)
    {
    case '1': case 'F':
    {
        //reading the first point
        point(x1, y1, "first ");
        point1_entered = true;//point 1 entered

    }break;
    case '2': case 'S':
    {
        //reading the second point
        point(x2, y2, "second ");
        point2_entered = true;//point 2 entered

    }break;
    case '3': case 'M': case 'X': case 'Q':
    {
        //user wants to return to the main menu
        cout << "Taking you back to the main"
            << " menu.\n";

    }break;

    //catching all invalid inputs
    default:
    {
        //error message
        cerr << "Invalid entry! Please select a menu number or capitalized"
            << " letter!\n";

    }break;
    }
    return;//return
}

//this function allows the user to enter in a
//point. it takes in the x and y variable of the 
//point by referece so it can store them into 
//seperate points. it also takes in a string
//so the user knows which point they are 
//entering. it retuens nothing.
void point(double& x, double& y, string f_or_s)
{
    //declaring local variables
    short error = 0;
    char open, comma, close;
    bool repeat;
    //do/while loop to repeat until user enters a vaild input.
    do
    {
        //reset loop to not repeat
        repeat = false;

        //prompting user for input
        cout << "Please enter your " << f_or_s
            << "point in standard notation! (x,y)\n";
        //do/while loop for reading input, allowing the program to exit
        //when an invalid input is detected.
        do
        {
            //eating whitespace before input
            cin >> ws;

            //checking to see if ( was entered 
            punct(open, '(', error, false);

            //reading in x and eating whitespace after
            cin >> x >> ws;

            //validating x
            if (cin.fail())//if cin fails, clear and ignore
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                //error message
                cerr << "Invalid entry for x coordinate!"
                    << " Try again!\n";

                repeat = true; //repeat the loop
                break;//break out of it inner loop 
            }

            //checking to see if , was entered
            punct(comma, ',', error, false);

            //reading in y
            cin >> y;

            //validating y
            if (cin.fail())//if cin fails clear and ignore
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                //error message
                cerr << "Invalid entry for y coordinate!"
                    << " Try again!\n";

                repeat = true;//repeat the loop
                break;//break out of the inner loop
            }
            while (isspace(cin.peek()) && cin.peek() != '\n')
            {
                cin.ignore();
            }

            //checking to see if ) was entered
            punct(close, ')', error, true);

            //if user had any errors print error message
            if (error > 0)
            {
                //error message
                cout << "Remember standard notation is (x,y)!\n";
            }

            //showing users the point they entered
            cout << open << x << comma << y << close << endl;

        } while (repeat);
    } while (repeat);

    return;//return
}

//This function validates the punctuation for each (,) of the standard
//notation. It takes in a char the user entered, the actual char that
//should be in that place, and a bool variable. the bool variable tells 
//the loop if it might have a number after the char. If it does, check
//that the punct isnt - . or + because those could be part of a number 
//and cin would rip that away from the number. It also takes in a short
//variable counting errors so the error count gets updated in the 
//function. it returns nothing.
void punct(char& punct_check, char act_punct, short& error, bool end)

{
    //if not the last expected input
    if (!end)
    {
        //check to see if its punct or a letter, and if its not - . +
        if ((ispunct(cin.peek()) || isalpha(cin.peek()))
            && cin.peek() != '-'
            && cin.peek() != '+'
            && cin.peek() != '.')
        {
            //if true enter to check it
            cin >> punct_check;

            //if its not what its supposed to be
            if (punct_check != act_punct)
            {
                //let the user know they made a mistake
                cout << "You set your '" << act_punct << "' to '" 
                     << punct_check << "'. Let me fix that for you!\n";
                punct_check = act_punct;//fix their mistake
                ++error;//count an error
            }
        }
        else
        {
            //let them know they forgot the punct
            cout << "You forgot to enter the '" << act_punct << "'!\n";
            punct_check = act_punct;//set the punct
            ++error;//count an error
        }
    }
    //if the last expected input
    else
    {
        //check if its punct or a letter
        if ((ispunct(cin.peek()) || isalpha(cin.peek())))
        {
            //if true enter to check
            cin >> punct_check;
            //if its not what its supposed to be
            if (punct_check != act_punct)
            {
                //let user know they made a mistake
                cout << "You set your '" << act_punct << "' to '" 
                     << punct_check << "'. Let me fix that for you!\n";
                punct_check = act_punct;//fix their mistake
                ++error;//count an error
            }
        }
        else
        {
            //let them know they forgot the punct
            cout << "You forgot to enter the '" << act_punct << "'!\n";
            punct_check = act_punct;//set the punct
            ++error;//count an error
        }
    }
}
