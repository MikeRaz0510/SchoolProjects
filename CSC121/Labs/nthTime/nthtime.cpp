#include<iostream>
#include<string>
#include<cctype>
#include<limits>
#include<ctime>
#include<cstdlib>
#include "suffix.h"

using namespace std;

//function prototypes
void welcome(string title);
void results(string rand_str, short num, string sfx);
string mess_rand(void);
short num(void);
bool again(void);
void bye(string name);

int main(void)
{
    //Declaring variables
    short numb;
    string sfx, rand_str;
    bool repeat = true;
    string name = "Mike Suffix Addition";

    //seeding random values
    srand(static_cast<unsigned>(time(nullptr)));

    welcome(name); //Welcoming user to the program

    do
    {
        numb = num();//user enters a number
        sfx = suffix(numb);//assign a suffix to the number
        rand_str = mess_rand();//print a random message
        results(rand_str, numb, sfx);//print the results
        repeat = again();//ask to repeart again

    } while (repeat);

    bye(name);//telling the user bye
    return 0;
}

//This function prints out a welcome message. It
//takes in a string that contains the name of the
//program and centers it in the console. 
//it returns nothing.

void welcome(string title)
{
    cout << '\n' << string((80 - (20 + title.size())) / 2, ' ')
        << "Welcome to " << title << " Program!\n\n";
    return;
}

//This function prints out the results of the
//program. It takes in 3 variables. A string 
//containing a randonly generated message,
//a short variable containing the user entered 
//number, and a string, a sufix that the algorithm
//assigns to the number. It returns nothing.

void results(string rand_str, short num, string sfx)
{
    cout << rand_str << num << sfx << '\n';
    return;
}

//This function generates a random message.
//It has no input and it returns a string of the 
//message that it randomly selected.

string mess_rand(void)
{
    //declaring local variables
    short rand_num;
    string rand_str;

    //generating a random number between 1 and 4 because there are 4 messages
    rand_num = rand() % 4 + 1;

    //using the random number to select a message
    switch (rand_num)
    {
    case 1: rand_str = "That would be the "; break;
    case 2: rand_str = "Your number is the "; break;
    case 3: rand_str = "I'd have to say the "; break;
    case 4: rand_str = "It could be the "; break;
    }

    //return the random message
    return rand_str;
}

//This function lets the user enter a number
//it has no input and it returns the user entered 
//number.

short num(void)
{
    short num; // delcaring a local varible

    cout << "Please enter your number!\t"; //prompting the user
    cin >> num;//reading input

    //ignoring anything extra they have entered
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //validating input
    while (cin.fail())
    {
        //clear and ignore what caused cin to fail
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        //error message
        cerr << "Invald Entry! Please enter your number!\t";
        cin >> num;//reading input

        //ignoring anything extra they have entered
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    //return the entered number
    return num;
}

//This function prompts to user to run the program again.
//It has takes no input and returns a bool variable.
bool again(void)
{
    char yes_no;//declaring local variable

    cout << "Run the program again? yes or no?\n";//prompting user
    cin >> yes_no;//reading input
    cin.ignore(numeric_limits<streamsize>::max(), '\n');//ignoring extra input
    yes_no = tolower(yes_no);//making the input lowercase

    //if input is 'y' return true. anything else return false.
    return (tolower(yes_no == 'y'));

}

//This function prints out a goodbye message. It takes in a string for
//the name of the program. It returns nothing.
void bye(string name)
{
    cout << "Thank you for using " << name << " Program";
    return;
}
