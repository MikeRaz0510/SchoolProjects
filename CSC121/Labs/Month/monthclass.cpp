#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include <limits>
#include "month.h"

using namespace std;





short Month::input(void)
{
    string monthStr;
    short monthSho;
    bool repeat;

    getline(cin, monthStr);

    for (short i = 0; i < monthStr.size(); ++i)
    {
        monthStr[i] = toupper(monthStr[i]);
    }

    do
    {
        repeat = false;
        if (monthStr == "JANUARY" || monthStr == "JAN" || monthStr == "1")
        {
            month = 1;
        }
        else if (monthStr == "FEBRUARY" || monthStr == "FEB" || monthStr == "2")
        {
            month = 2;
        }
        else if (monthStr == "MARCH" || monthStr == "MAR" || monthStr == "3")
        {
            month = 3;
        }
        else if (monthStr == "APRIL" || monthStr == "APR" || monthStr == "4")
        {
            month = 4;
        }
        else if (monthStr == "MAY" || monthStr == "5")
        {
            month = 5;
        }
        else if (monthStr == "JUNE" || monthStr == "JUN" || monthStr == "6")
        {
            month = 6;
        }
        else if (monthStr == "JULY" || monthStr == "JUL" || monthStr == "7")
        {
            month = 7;

        }
        else if (monthStr == "AUGUST" || monthStr == "AUG" || monthStr == "8")
        {
            month = 8;
        }
        else if (monthStr == "SEPTEMBER" || monthStr == "SEP" || monthStr == "9")
        {
            month = 9;
        }
        else if (monthStr == "OCTOBER" || monthStr == "OCT" || monthStr == "10")
        {
            month = 10;
        }
        else if (monthStr == "NOVEMBER" || monthStr == "NOV" || monthStr == "11")
        {
            month = 11;
        }
        else if (monthStr == "DECEMBER" || monthStr == "DEC" || monthStr == "12")
        {
            month = 12;
        }
        else
        {
            cerr << "Invalid Entry! PLease try again";
            repeat = true;
        }
    } while (repeat);

    return month;
}

void Month::output(void)
{
    cout << month;
    return;
}

Month::Month(void)
{
}

void Month::setMonth(short x)
{
    month = x;
    return;
}

void Month::setMonth(string monthStr)
{
    if (monthStr == "JANUARY" || monthStr == "JAN")
    {
        month = 1;
    }
    else if (monthStr == "FEBRUARY" || monthStr == "FEB")
    {
        month = 2;
    }
    else if (monthStr == "MARCH" || monthStr == "MAR")
    {
        month = 3;
    }
    else if (monthStr == "APRIL" || monthStr == "APR")
    {
        month = 4;
    }
    else if (monthStr == "MAY")
    {
        month = 5;
    }
    else if (monthStr == "JUNE" || monthStr == "JUN")
    {
        month = 6;
    }
    else if (monthStr == "JULY" || monthStr == "JUL")
    {
        month = 7;

    }
    else if (monthStr == "AUGUST" || monthStr == "AUG")
    {
        month = 8;
    }
    else if (monthStr == "SEPTEMBER" || monthStr == "SEP")
    {
        month = 9;
    }
    else if (monthStr == "OCTOBER" || monthStr == "OCT")
    {
        month = 10;
    }
    else if (monthStr == "NOVEMBER" || monthStr == "NOV")
    {
        month = 11;
    }
    else if (monthStr == "DECEMBER" || monthStr == "DEC")
    {
        month = 12;
    }

    return;
}

short Month::getMonth(void)
{
    return month;
}
void Month::getMonth(string& s)
{
    s = monthName;
    return;
}

short Month::advance(void)
{
    return month + 1;

}

bool Month::before(Month m)
{
    return month < m.month;
}

bool Month::after(Month m)
{
    return month > m.month;
}

bool Month::same(Month m)
{
    return month == m.month;
}
