#include <iostream>
#include <limits>
#include <cctype>
#include "Count.h"
#include "Input.h"

using namespace std;

bool Count::upOne(Count& c)
{
    bool okay = false,
        repeat = false;
    char a = 'a',
        s = 's',
        d = 'd',
        f = 'f',
        input;

    std::cout << "The total is" << c.total << "!\n";

    do
    {
        inputValidationChar(input);
        input = tolower(input);

        if (input == a)
        {
            c.total += 1000;
        }
        else if (input == s)
        {
            c.total += 100;
        }
        else if (input == d)
        {
            c.total += 10;
        }
        else if (input == f)
        {
            c.total += 1;
        }
        else
        {
            std::cerr << "Invalid input! Please try again.\n";
            repeat = true;
        }
    } while (repeat);

    if (c.total > c.maxValue)
    {
        c.total = c.total - c.maxValue - 1;
        c.overflow = true;
    }

    return okay;
}

void Count::display(Count& c, bool display_Money)
{
    if (display_Money)
    {
        cout << '$' << c.get_dollars() << '.' << c.get_cents() << '\n';
    }
    else
    {
        cout << c.total << '\n';
    }
    return;
}
