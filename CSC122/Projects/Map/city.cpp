#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<cmath>
#include "point.h"
#include "city.h"

using namespace std;

City City::input(void)
{
    string name;
    Point cityLoc;
    double x, y;
    cout << "Enter the name of this city.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    if (setName(name))
    {
        setName(name);
    }
    else
    {
        cerr << "Not a valid city name\n";
    }

    cout << "Enter the x coordinate for the city\t";
    cin >> x;
    cout << "Enter the y coordinate for the city\t";
    cin >> y;

    cityLoc = Point(x, y);
    if (setLocation(cityLoc))
    {
        setLocation(cityLoc);
    }

    City myCity(name, cityLoc);

    return myCity;
}

void City::printCity(void)
{
    Point currentLocation = getLocation();
    string cityName = getName();
    double x = currentLocation.get_x(),
        y = currentLocation.get_y();
    cout << cityName << "\t(" << x << ',' << y << ")\n";

    return;
}
