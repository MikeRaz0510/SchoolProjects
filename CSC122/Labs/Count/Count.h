#ifndef Count_H_Inc
#define Count_H_Inc

#include<iostream>
#include "Input.h"

class Count
{
private:

    short dollarHundreds = 0,
        dollarTens = 0,
        dollarOnes = 0,
        centTens = 0,
        centOnes = 0,
        dollars = 0,
        cents = 0;
    long total = 0,
        maxValue = 9999;
    bool overflow = false;



public:

    //constructors
    Count(void)
        : total{ 0 },
        maxValue{ 9999 },
        overflow{ false }
    {
    }
    Count(const Count& c)
        : total{ c.total },
        maxValue{ c.maxValue },
        overflow{ c.overflow }
    {
    }

    Count(short newTotal, short newMax)
        : Count{}
    {
        set_total(newTotal);
        set_maxValue(newMax);
    }



    //accessors
    inline short get_dollarHundreds(void)
    {
        dollarTens = (total % 100000) / 10000;
        return dollarHundreds;
    }
    inline short get_dollarTens(void)
    {
        dollarTens = (total % 10000) / 1000;
        return dollarTens;
    }
    inline short get_dollarOnes(void)
    {
        dollarOnes = (total % 1000) / 100;
        return dollarOnes;
    }
    inline short get_centTens(void)
    {
        centTens = (total % 100) / 10;
        return centTens;
    }
    inline short get_centOnes(void)
    {
        centOnes = total % 10;
        return centOnes;
    }
    inline short get_dollars(void)
    {
        dollars = (total % 10000) / 100;
        return dollars;
    }
    inline short get_cents(void)
    {
        cents = (total % 100);
        return cents;
    }
    inline long get_total(void)
    {
        return total;
    }
    inline long get_maxValue(void)
    {
        return maxValue;
    }
    inline bool get_overflow(const bool& overflow)
    {
        return overflow;
    }

    //mutators
    inline bool set_dollarHundreds(short newDollarHundreds)
    {
        bool okay = false;
        inputValidation(newDollarHundreds);
        while (newDollarHundreds < 0 || newDollarHundreds > 9)
        {
            std::cerr << "Enter a single digit number!";
            inputValidation(newDollarHundreds);
        }
        if (newDollarHundreds >= 0 && newDollarHundreds <= 9)
        {
            dollarHundreds = newDollarHundreds;
            okay = true;
        }
        return okay;
    }
    inline bool set_dollarTens(short newDollarTens)
    {
        bool okay = false;
        inputValidation(newDollarTens);
        while (newDollarTens < 0 || newDollarTens > 9)
        {
            std::cerr << "Enter a single digit number!";
            inputValidation(newDollarTens);
        }
        if (newDollarTens >= 0 && newDollarTens <= 9)
        {
            dollarTens = newDollarTens;
            okay = true;
        }
        return okay;
    }
    inline bool set_dollarOnes(short newDollarOnes)
    {
        bool okay = false;
        inputValidation(newDollarOnes);
        while (newDollarOnes < 0 || newDollarOnes > 9)
        {
            std::cerr << "Enter a single digit number!";
            inputValidation(newDollarOnes);
        }
        if (newDollarOnes >= 0 && newDollarOnes <= 9)
        {
            dollarOnes = newDollarOnes;
            okay = true;
        }
        return okay;
    }
    inline bool set_centTens(short newCentTens)
    {
        bool okay = false;
        inputValidation(newCentTens);
        while (newCentTens < 0 || newCentTens > 9)
        {
            std::cerr << "Enter a single digit number!";
            inputValidation(newCentTens);
        }
        if (newCentTens >= 0 && newCentTens <= 9)
        {
            centTens = newCentTens;
            okay = true;
        }
        return okay;
    }

    inline bool set_centOnes(short newCentOnes)
    {
        bool okay = false;
        inputValidation(newCentOnes);
        while (newCentOnes < 0 || newCentOnes > 9)
        {
            std::cerr << "Enter a single digit number!";
            inputValidation(newCentOnes);
        }
        if (newCentOnes >= 0 && newCentOnes <= 9)
        {
            centOnes = newCentOnes;
            okay = true;
        }
        return okay;
    }
    bool set_total(long newTotal)
    {
        bool okay = false;
        inputValidationLong(newTotal);
        while (newTotal < 0 || newTotal > maxValue)
        {
            std::cerr << "Enter a positive number less than " << maxValue << "!\t";
            inputValidationLong(newTotal);
        }
        if (newTotal >= 0 && newTotal <= maxValue)
        {
            total = newTotal;
            okay = true;
        }
        return okay;
    }
    inline bool set_maxValue(long newMaxValue)
    {
        bool okay = false;
        inputValidationLong(newMaxValue);
        while (newMaxValue < 100 || newMaxValue > 99999)
        {
            std::cerr << "please enter a number over 100 but less than 100,000";
            inputValidationLong(newMaxValue);
        }
        if (newMaxValue >= 100 && newMaxValue <= 99999)
        {
            maxValue = newMaxValue;
            okay = true;
        }
        return okay;
    }

    //helpers
    bool upOne(Count& c);

    void display(Count& c, bool display_Money);

    /*inline bool set_overflow(bool newOverflow)
    {
        bool okay = false;
        overflow = newOverflow;
        okay = true;
        return okay;
    }*/



};
#endif // !Count_H_Inc

