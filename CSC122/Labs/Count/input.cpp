#include <iostream>
#include <limits>
#include "Input.h"

using namespace std;


void inputValidation(short& num)
{
    cin >> num;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> num;
    }
    return;
}

void inputValidationLong(long& num)
{
    cin >> num;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> num;
    }
    return;
}

void inputValidationChar(char& in)
{
    cin >> in;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> in;
    }
    return;
}
