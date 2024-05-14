#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include <limits>
#include "month.h"

using namespace std;



int main(void)
{
    Month myMonth, otherMonth;
    short placeholder;
    char menu, subMenu;
    bool repeat, istrue;
    string placeStr, month1Str, month2Str;

    do
    {
        repeat = true;

        cout << "\t\tMain Menu:\n1. Input month\n2. Output month\n3. Advance "
            << "month\n4. Compare months\n5. Quit\n";
        cin >> menu;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        menu = toupper(menu);

        switch (menu)
        {
        case '1': case 'I':
        {
            placeholder = myMonth.input();
            myMonth.setMonth(placeStr);
        }break;
        case '2': case 'O':
        {
            cout << "your month is ";
            myMonth.output();
            cout << "!\n";
        }break;
        case '3': case 'A':
        {
            myMonth.advance();
            cout << "Your month has been advanced.";
        }break;
        case '4': case 'C':
        {
            cout << "Compare Months Menu:\n1. Is my month Before\n2. Is my "
                << "month After\n3. Is my month the Same\n4. Quit\n";
            cin >> subMenu;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            subMenu = toupper(subMenu);

            switch (subMenu)
            {
            case '1': case 'B':
            {
                myMonth.getMonth(month1Str);
                otherMonth.getMonth(month2Str);

                cout << month1Str << " is";

                if (!myMonth.before(otherMonth));
                {
                    cout << " not";
                }
                cout << " before " << month2Str << ".\n";
                 
            }break;
            case '2': case 'A':
            {

            }break;
            case '3': case 'S':
            {

            }break;
            case '4': case 'Q': case 'X':
            {

            }break;
            default:
            {
                cerr << "Invalid Entry!";
            }break;
            }
        }break;
        case '5': case 'Q': case 'X':
        {
            repeat = false;
        }
        }
    } while (repeat);

  
    return 0;
}
