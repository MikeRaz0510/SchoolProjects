#include <iostream>
#include "point.h"


using namespace std;

//overload input and output operators
istream& operator>>(istream& is, Point & obj);
ostream& operator<<(ostream& os, Point& obj);

//driver function
int main(void)
{
	//declare variables
	Point Point1, Point2, mid, copy;
	double ans, myX, myY;
	bool equal, unequal;

	//input test
	cout << "Enter your first point\t(x,y)\n";
	cin >> Point1;
	cout << "Enter your second point\t(x,y)\n";
	cin >>Point2;

	//copy test
	copy = Point1;
	cout << "The coppied point is " << copy << endl;

	//Output test
	cout << "Your first point is:\t" << Point1 << "\nYour second point is:\t"
		<< Point2 << endl;

	// - and / operator test
	ans = Point1 - Point2;
	mid = Point1 / Point2;
	cout << "The distance between the points is " << ans 
		 << "\nThe midpoint of the line made by the points is"
		 << mid << endl;

	// == and != operator test
	equal = Point1 == Point2;
	unequal = Point1 != Point2;
	if (equal)
	{
		cout << "The points are equal\n";
	}
	else
	{
		cout << "The points are not equal\n";
	}
	if (unequal)
	{
		cout << "The points are not equal\n";
	}
	else
	{
		cout << "The points are equal\n";
	}

	// [] operator test
	myX = Point1['x'];
	myY = Point1['y'];
	cout << "Extracted " << myX << " as x cordiante and " << myY
		<< " as y cordinate!\n";
	
	// end of driver funtion
	return 0;

}

//>> operator def
istream& operator>>(istream& is, Point & obj)
{
	obj.Input();
	return is;
	

}

//<< operator def
ostream& operator<<(ostream& os, Point& obj)
{
	obj.Output();
	return os;

}