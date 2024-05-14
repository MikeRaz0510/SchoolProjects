#ifndef MONTH_H_INC
#define MONTH H INC

#include <iostream>
#include<limits>
#include <cctype>
#include<string>
#include<vector>



class Month
{
	//only private member vairable
	short month;

	

public:

	//const vector of month names
	const std::vector<std::string> names = { "january","february","march",
		"april","may","june","july","august","september","october",
		"november","december" };


	//default constructor
	Month(void)
		:month(0)
	{

	}

	//copy constructor
	Month(const Month& obj)
		:month(obj.month)
	{
		month = obj.month;
	}

	//constructors
	Month(short num)
		:month(num)
	{
		setMonth(num-1);
	}
	//THIS CONSTRUCTOR IS CAUSING A SEGMENTATION FAULT ON ARES WHEN I INITILIZE
	//OTHER AS other("may"); SO I AM JUST GOING TO INITILIZE IT AS other(5) TO
	//USE THE OTHER CONSTRUCTOR THAT WORKS BECAUSE IT IS 4:51 AM AND IM TIRED
	Month(std::string s)
		:month(setMonth(s, true))
	{
		month = setMonth(s, true);
	}
	//accessors
	inline short getMonth(void) const
	{
		return month;
	}
	inline short getMonth(const std::string& s) const
	{
		short num = getMonth();

		for (std::vector<std::string>::size_type i = 0; i < names.size(); i++)
		{
			if (names[i] == s)
			{
				num = static_cast<short>(i);
			}
		}

		return num;
	}

	//mutators
	inline bool setMonth(short  num)
	{
		bool okay = false;
		if (num >= 0 && num <= 11)
		{
			okay = true;
			month = num;
		}
		else
		{
			std::cerr << "Invalid entry!\n";
		}
		return okay;
	}

	inline bool setMonth(std::string& s)
	{
		bool okay = false;

		for (std::vector<std::string>::size_type i = 0; i < names.size(); i++)
		{
			if (names[i] == s)
			{
				month = static_cast<short>(i);
				okay = true;
			}
		}
		return okay;
	}

	inline short setMonth(const std::string& s, bool returnShort = true)
	{
		for (std::vector<std::string>::size_type i = 0; i < names.size(); i++)
		{
			if (names[i] == s)
			{
				month = static_cast<short>(i);

			}
		}

		return month;

	}

	//methods
	inline void input(short num)
	{
		setMonth(num-1);
	}

	inline void input(const std::string& s)
	{
		setMonth(s);
	}


	inline void output(void) const
	{
		short num;

		num = getMonth();

		std::cout << num + 1;
	}

	inline void output(bool displayString) const
	{
		short num;
		std::string monthName;
		num = getMonth();
		if (displayString)
		{
			monthName = names[num];
			std::cout << monthName;
		}
		else
		{
			std::cout << num + 1;
		}

	}

	inline void advance(short num = 1)
	{
		short newNum = getMonth();

		if (newNum + num >= 12 || newNum + num < 1)
		{
			newNum = ((newNum + num) % 12 + 12) % 12;
			setMonth(newNum);
		}

		else
		{
			setMonth(month + num);
		}

		return;
	}

	inline bool before(Month other) const
	{
		bool isBefore = false;

		if (month < other.month)
		{
			isBefore = true;
		}
		return isBefore;
	}

	inline bool after(Month other) const
	{
		bool isAfter = false;

		if (month > other.month)
		{
			isAfter = true;
		}
		return isAfter;
	}

	inline bool same(Month other) const
	{
		bool isSame = false;

		if (month == other.month)
		{
			isSame = true;
		}
		return isSame;
	}

	//operators
	inline bool operator<(Month other) const
	{
		return before(other);
	}
	inline bool operator>(Month other) const
	{
		return after(other);
	}
	inline bool operator==(Month other) const
	{

		return same(other);
	}

	inline void operator+(short num)
	{
		return advance(num);
	}

	//destructors
	

};

#endif // !MONTH_H_INC
