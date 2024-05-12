#include<string>


//This function assigns a string to be the suffix of a number. It takes in a
//number. it returns the string it assigned to that number.
std::string suffix(short num)
{
    //declaring local variables
    short tens, ones;
    std::string sfx;

    //digit extraction
    tens = (num % 100) / 10;
    ones = num % 10;

    //if the tens place is a '1' then the suffix is always "th"
    if (tens == 1)
    {
        sfx = "th";
    }

    //else, check the ones place
    else
    {
        switch (ones)
        {
        case 1: sfx = "st"; break;
        case 2: sfx = "nd"; break;
        case 3: sfx = "rd"; break;
        default: sfx = "th"; break;
        }
    }

    //return the assigned suffix
    return sfx;
}
