#include <iostream>
#include<limits>
#include <cctype>
#include<string>
#include<vector>
#include "month.h"

using namespace std;


int main(void)
{
	Month myMonth, other(5);
	string month;
	short num;
	
	//testing string constructor and both output overloads
	other.output();
	cout << endl;
	other.output(true);
	cout << endl;
	
	//testing int input
	cout << "Enter Your month as a number!\t";
	cin >> num;
	myMonth.input(num);
	myMonth.output();
	cout << endl;
	myMonth.output(true);
	cout << endl;

	//testing string input
	cout << "Enter Your month as a string!\t";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, month);
	myMonth.input(month);
	myMonth.output();
	cout << endl;
	myMonth.output(true);
	cout << endl;

	//testing before, after, and same and operators < > and ==
	cout << "Enter a new month and Ill tell you its relation to may!\n";
	cin >> num;
	myMonth.input(num);
	if (myMonth < other)
	{
		myMonth.output(true);
		cout << " is before ";
		other.output(true);
		cout << endl;
	}
	else if (myMonth > other)
	{
		myMonth.output(true);
		cout << " is after ";
		other.output(true);
		cout << endl;
	}
	else if (myMonth == other)
	{
		myMonth.output(true);
		cout << " is the same as ";
		other.output(true);
		cout << endl;
	}

	//testing advance
	cout << "Enter a new month\n";
	cin >> num;
	myMonth.input(num);
	myMonth.output();
	cout << endl;
	myMonth.output(true);
	cout << "\nAdvancing the default amount (1 month forward).\n";
	myMonth.advance();
	myMonth.output();
	cout << endl;
	myMonth.output(true);
	cout << "\nAdvancing 3 months forward.\n";
	myMonth.advance(3);
	myMonth.output();
	cout << endl;
	myMonth.output(true);
	cout << "\nReversing 11 months back.\n";
	myMonth.advance(-11);
	myMonth.output();
	cout << endl;
	myMonth.output(true);
	cout << "\nNow you pick how many months to move.\n";
	cin >> num;
	myMonth.advance(num);
	myMonth.output();
	cout << endl;
	myMonth.output(true);
	cout << "\nPick how many months to move and ill use the + operator.\n";
	cin >> num;
	myMonth + num;
	myMonth.output();
	cout << endl;
	myMonth.output(true);
	cout << endl;

	return 0;
}





