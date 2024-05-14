#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <limits>
#include "box.h"

using namespace std;

//prototypes
void menu(void);
void boxify(char symbol,short allignment);
void settings(char& symbol, short& allignment);

//main
int main(void)
{
    menu();
    return 0;
}

void menu(void)
{
    //declare variables
    char menu, symbol = '*';
    short allignment = 1;
    bool repeat;

    do
    {
        repeat = true;


        cout << "MAIN MENU:\n1. Boxify\n2. Settings\n3. Exit\n";
        cin >> menu;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        menu = tolower(menu);

        switch (menu)
        {
        case '1': case 'b':
        {
            boxify(symbol, allignment);
        }break;
        case '2': case 's':
        {
            settings(symbol, allignment);
        }break;
        case '3': case 'e': case 'q':
        {
            repeat = false;
        }break;
        default :
        {
            cerr << "Not a vaild choice try again\n";
        }break;
        }
    } while (repeat);



}

void boxify(char newSymbol, short allignment)
{
    string line;
    vector<string> words, reset;
    short longest = 0;

    box box;

    box.set_Symbol(newSymbol);

    cout << "Enter your line\n";
    getline(cin, line);
    box.set_line(line);
    box.set_Words(line);
    words = box.getWords();
    reset = words;

    longest = box.lWord(words);

    switch (allignment)
    {
    case 1: box.boxifyC(); break;
    case 2: box.boxifyL(); break;
    case 3: box.boxifyR(); break;
    }
    words = reset;
    

}

void settings(char & symbol, short & allignment)
{
    char menu, allign;
    bool repeat, repeat2;

    cout << "SETTINGS\n1. Border\n2. Allignment\n3. Exit\n";
    cin >> menu;
    menu = tolower(menu);

    do
    {
        repeat = false;
        switch (menu)
        {
        case '1': case 'b':
        {
            cout << "What do you want the border character to be?\n";
            cin >> symbol;
            cout << "You set the border to be the character '" << symbol
                << "'" << endl;
        }break;
        case '2': case 'a':
        {
            cout << "Where do you want the text alligned?\n1. Center\n2. Left"
                << "\n3. Right\n";
            cin >> allign;
            allign = tolower(allign);
            do
            {
                repeat2 = false;
                switch (allign)
                {
                case '1': case 'c':
                {
                    allignment = 1;
                }break;
                case '2': case 'l':
                {
                    allignment = 2;
                }break;
                case '3': case 'r':
                {
                    allignment = 3;
                }break;
                default:
                {
                    cerr << "Invalid entry! Try again!\n";
                    repeat2 = true;
                }
                }
            } while (repeat2);
        }break;
        case '3': case 'e': case 'q':
        {
            
        }break;
        default:
        {
            cerr << "Invalid Entry! Please try again.\n";
            repeat = true;
        }
        }
    } while (repeat);
}
