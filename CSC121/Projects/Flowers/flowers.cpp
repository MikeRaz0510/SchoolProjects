#include <iostream>
#include <cctype>
#include <string>
#include <limits>
#include <ctime>
#include <cstdlib>
#include "suffix.h"
#include "basics.h"

using namespace std;

//function prototypes
short inv_entry(string type);
void opening(void);
short basket(short p, short s, short u, bool& repeat);
void basket_cost(short& p, short& s, short& u, short num);
short validate(void);
char rand_cat(short p, short s, short u);

int main(void)
{
    //Declaring variables
    short p, s, u, num;
    string name = "Flower Inventory";
    bool repeat = true;

    srand(static_cast<unsigned>(time(nullptr)));//seeding random numbers

    welcome(name);//welcoming the user to the program

    p = inv_entry("Pretty");//user enters in pretty flowers
    s = inv_entry("So-So");//user enters in so-so flowers
    u = inv_entry("Ugly");//user enters in ugly flowers

    opening();//letting the user know their entries are saved

    //do/while loop to repeat the pos portion of the program
    do
    {
        //asking the user how many categories per basket
        num = basket(p, s, u, repeat);
        basket_cost(p, s, u, num);//calculating the cost of the basket
    } while (repeat);

    goodbye(name);//saying bye to the user

    return 0;
}

//This function prompts the user to enter how many flowers they have in stock.
//It takes in a string variable that is the name of the flowers the user is
//taking inventory of. it validates the users input. It returns 
//the input as a short variable.
short inv_entry(string type)
{
    short flowers = 0;
    cout << "How many " << type << " flowers are in stock?\t";//prompting user
    flowers = validate();//reading and validating input
    
    while (flowers <= 0)//checking to see if the inpuit is positive
    {
        if (flowers == 0)//checking to see if the value is 0
        {
            //error message
            cerr << "You need more flowers than that to open the store!\n"
                << "Get some more and enter how many you have!\t";
            flowers = validate();//reading and validating input
        }

        else
        {
            //error message
            cerr << "What interdimentional portal did you travel through to"
                 << " end up with negative flowers?\nPlease go back through"
                 << " and come back with a positive amount of flowers and"
                 << " enter them!\t";
            flowers = validate();//reading and validating input
        }        
    }

    return flowers;//return the value of flowers
}

//this function prints out a message on screen. It lets the user know that the
//entering inventory portion of the program is over and its moving on to the 
//pos portion. It takes no input and it returns nothing.
void opening(void)
{
    //centered message
    cout << '\n' << string(((80 - 16) / 2), ' ')
        << "Inventory Saved!\nLets have a great day today and provide "
        << "our customers with the best quality flowers in town!\n\n";
    return;//return
}

//This function asks how many categories are in each basket. It takes in a
//bool variable by reference so that if the user entrers 0 catergories 
//that ends the program. It also takes in 3 short variables, one of each
// flower type. it uses them to calculate the total number of flowers
// so that it can made sure there are enough total flowers to fill a 
// basket. It returns a short variable for the number of 
//categories the user entered.
short basket(short p, short s, short u, bool& repeat)
{
    //declaring local variables
    short num, total;
    bool repeat_loop;


    //calculating total number of flowers
    total = p + s + u;

    //do/while loop to ask for how many categories in each basket
    do
    {
        repeat_loop = false;//repeat this do/while reset to false

        cout << "How many categories in this basket?\t";//prompting user
        num = validate();//reading and validating input

         //checking to see if there are enough flowers for the basket
        while (total < num)
        {
            //error message
            cout << "There are not enough flowers to fill this basket!\nThe"
                << " most categories that can fit in this basket is "
                << total << "!\nHow many categories in this basket?\t";
            num = validate();//validate input
        }



        switch (num)
        {
        //valid entries that dont end the program
        case 1: case 2: case 3: case 4: case 5:
        {
        }break;

        //ends the program
        case 0:
        {
            //closing message
            cout << "\nTime to close the store for the night!\n";
            repeat = false;//set repeat to false by refernce
        }break;

        //catch all invlaid inputs
        default:
        {
            //if cin fails clear and ignore input
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            //error message
            cerr << "Invalid entry! Baskets can only contain between 1 "
                 << "and 5 categories!\n";
            repeat_loop = true;//invalid input so repeat loop 
        }break;
        }
        
    } while (repeat_loop);

        return num;//return the value of num
}

//this function calculates the cost of a basket. It takes in 3 short
//variables by reference, p for pretty flowers, s for so-so flowers, and u
//for ugly flowers. they are called by reference so that they can upadte the 
//inventory counts in real time. it also takes in a short variable num
//that is the number of categories per basket. It returns nothing
void basket_cost(short& p, short& s, short& u, short num)

{
    //declaring local variables
    //constant variables, costs per flowers
    const double p_cost = 15,
        s_cost = 8.5,
        u_cost = 1.8;
    double cost = 0;//total cost, reset to 0 for each new basket
    short x;
    char cat;
    string sfx;
    bool repeat;

    //for loop for calculating the cost of a basket, one catergorie at a time
    for (x = 1; x <= num; ++x)
    {
        //do/while loop to repeat the entry of category type
        do
        {
            //prompting the user to enter the type of category
            cout << "\nWhat is the category of the " << x << suffix(x) 
                 << " bunch?\t";
            cin >> cat;//reading the input

            //ignoring extra input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cat = toupper(cat);//making users entery uppercase
            repeat = false;//setting the loop repeat to flase

            //if user choses a random category select a random category
            if (cat == 'R')
            {
                //setting cat to a random category
                cat = rand_cat(p, s, u);
            }

            switch (cat)
            {
            case 'P':
            {
                //making sure that there is enough pretty in stock
                if (p < 1)
                {
                    //error message
                    cerr << "You do not have enough pretty flowers"
                        << " in stock!\n";
                    repeat = true;//repeat loop
                    break;
                }
                else
                {
                    //add the cost of the category to the total cost
                    cost = cost + p_cost;
                    --p;//subtract 1 from the pretty category
                }
            }break;
            case 'S':
            {
                //making sure that there is enough pretty in stock
                if (s < 1)
                {   
                    //error message
                    cerr << "You do not have enough so-so flowers"
                        << " in stock!\n";
                    repeat = true;//repeat loop
                    break;
                }
                else
                {
                    //add the cost of the category to the total cost
                    cost = cost + s_cost;;
                    --s;//subtract 1 from the so-so category
                }
            }break;
            case 'U':
            {
                //making sure that there is enough pretty in stock
                if (u < 1)
                {
                    //error message
                    cerr << "You do not have enough ugly flowers"
                        << " in stock!\n";
                    repeat = true;//repeat loop
                }
                else
                {
                    //add the cost of the category to the total cost
                    cost = cost + u_cost;
                    --u;//subtract 1 from the ugly category
                }
            }break;
            //catching all invalid inputs
            default:
            {
                //error message
                cerr << "Invalid entry! Type 'P' for Pretty, 'S' for So-So,"
                    << " or 'U' for Ugly!\n";
                repeat = true;//repeat loop
            }
            }
        } while (repeat);
    }
    //there is at least 1 category in the basket print the cost
    if (num != 0)
    {
        //display the cost
        cout << "That basket will cost $" << cost
             << "! Rememeber to thank the customer!\n";
    }
    else
    {
        //display the remaining inventory
        cout << "\t VERIFY INVENTORY\nRemaining Pretty: "
             << p << "\nRemaining So-So: " << s << "\nRemaining Ugly: "
             << u << '\n';
    }
    return;//return
}

//this function validates a users input. it takes in nothing. It reurns
//the validated number.
short validate(void)
{
    short num;

    cin >> num;
    //ignoring extra input
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //if the user enters anything other than a number cin will fail
    while (cin.fail())
    {
        //clear and ignore the input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        /*debugging cout statement*/ cout << '\n' << num << '\n';

        cerr << "Invalid Entry!\t";//error message        
        cin >> num;//reading new input

        //ignoring extra input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }
    return num;
}

//This function randomly selects a category for the customer. It takes in
//the short variables p, s, and u for the number of flowers of each type.
//it returns a char of the selected type.
char rand_cat(short p, short s, short u)
{
    //declaring local variables
    short num;
    char cat = '\0';
    bool repeat = false;
    //do/while loop to only select flowers that are available
    do
    {
        //repeat set to false so the loop doesnt repeat
        repeat = false;

        //generateing a random number
        num = rand() % 3 + 1;
        
        //checking to see if that category can be selected based on inventory
        if (num == 1 && p == 0)
        {
            repeat = true;//if not in stock, repeat loop
        }
        if (num == 2 && s == 0)
        {
            repeat = true;//if not in stock, repeat loop
        }
        if (num == 3 && u == 0)
        {
            repeat = true;//if not in stock, repeat loop
        }        

    } while (repeat);//repeat if true
    
    //switch/case to assign a char to the random number
    switch (num)
    {
    case 1:
    {
        cat = 'P';//set cat and let user know what was selected
        cout << "We've randomly selected Pretty flowers for you!\n";

    }break;

    case 2:
    {
        cat = 'S';//set cat and let user know what was selected
        cout << "We've randomly selected So-so flowers for you!\n";

    }break;

    case 3:
    {
        cat = 'U';//set cat and let user know what was selected
        cout << "We've randomly selected Ugly flowers for you!\n";

    }break;
    }
       
    return cat;//return cat

}
