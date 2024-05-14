#include <iostream>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include <limits>
#include <string>
#include <vector>
#include <iomanip>
#include "randgen.h"

using namespace std;

void menu(void);


int main(void)
{
    srand(static_cast<unsigned>(time(nullptr)));

    menu();

    return 0;
}

void menu(void)
{
    char menu,
         maxC,
         minC;
    long maxL,
         minL;
    double maxD,
           minD;
    short num,
          places,
          type;
    bool repeat;

    do
    {
        repeat = true;

        cout << "\tMain Menu:\n1. create random Whole number data file\n"
            << "2. create random Decimal number data file\n"
            << "3. create random Character data file\n"
            << "4. create random Name data file\n5. Quit\n";

        cin >> menu;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cerr << "Invalid choice, please try again\n";
            cin >> menu;
        }

        menu = toupper(menu);

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      

        switch (menu)
        {
        case '1': case 'W':
        {
            randWhole(maxL = 100, minL = 0, num = 10);

        }break;

        case '2': case 'D':
        {
            randDouble(maxD = 100.0, minD = 0.0, num = 10, places = 2);
        }break;

        case '3': case 'C':
        {
            randChar(maxC = 'z', minC = 'a', num = 10);
        }break;

        case '4': case 'N':
        {
            randNames(num = 10, type = 1);
           
        }break;
        case '5': case 'Q': case 'X':
        {
            repeat = false;
        }break;
        default:
        {
            cerr << "Invalid choice, please try again!";
        }break;


        }
    } while (repeat);

    return;
}
