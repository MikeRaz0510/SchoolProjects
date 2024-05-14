#include<iostream>
#include<cctype>
#include<limits>
#include<string>
#include "Count.h"
#include "Input.h"

using namespace std;

void menu(Count& c, bool & displayMoney);
void settings(Count& c, bool & displayMoney);

int main(void)
{
    Count count1;
    short input{};
    bool displayMoney;

    menu(count1, displayMoney);

    /*
    cout << "Enter your max!(max: " << count1.get_maxValue() << ")\t";
    
    count1.set_maxValue(input);

    cout << "Enter your number!(max: " << count1.get_maxValue() << ")\t";

    count1.set_total(input);
    

    cout << "dollar tens place: " << count1.get_dollarTens()
         << "\ndollar ones place: " << count1.get_dollarOnes()
         << "\nCent Tens Place: " << count1.get_centTens() 
         << "\ncent ones place: " << count1.get_centOnes() 
         << "\nDollars: " << count1.get_dollars()
         << "\nCents: " << count1.get_cents() 
         << "\nTotal: " << count1.get_total() << endl;

    */
    return 0;
}

void menu(Count& c, bool & displayMoney)
{
    char menu;
    bool repeat = true;

    do
    {

        cout << "\t\tMain Menu\n1: use Counter\n2: Display count\n" 
             << "3: Settings\n4: eXit\n";
        inputValidationChar(menu);
        menu = tolower(menu);

        switch (menu)
        {
        case '1': case 'c':
        {

        }break;
        case '2': case 'd':
        {
            c.display(c, displayMoney);
        }break;
        case '3': case 's':
        {
            settings(c, displayMoney);
        }break;
        case '4': case 'x': case 'q':
        {
            repeat = false;
        }break;
        default:
        {
            cerr << "Invalid Entry, Please try again";
        }
        }
    } while (repeat);

    return;
}

void settings(Count& c, bool& displayMoney)
{
    char settings;
    bool repeat = true;
    long input;

    do
    {

        cout << "\t\tSettings Menu\n1: set Max\t" << c.get_maxValue()
             << "\n2: set Keys\n3: set Display\n"
            << "4: display Overflow\n5: eXit\n";

        inputValidationChar(settings);
        settings = tolower(settings);

        switch (settings)
        {
        case '1': case 'm':
        {
            inputValidationLong(input);
            c.set_maxValue(input);
        }break;
        case '2': case 'k':
        {

        }break;
        case '3': case 'd':
        {
            cout << "Display count as a money value? (y/n)\n";
            displayMoney = setDisplayMoney();

        }break;
        case '4': case 'o':
        {

        }break;
        case '5': case 'x': case 'q':
        {
            repeat = false;
        }break;
        default:
        {
            cerr << "Invalid entry, please try again\n";
        }break;
        }
    } while (repeat);
    return;
}

bool setDisplayMoney(void)
{
    bool displayMoney = false;
    char input;

    inputValidationChar(input);
    input = tolower(input);
    if (input == 'y')
    {
        displayMoney = true;
    }
    else if (input == 'n')
    {
        displayMoney = false;
    }
    return displayMoney;

}
