#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<cmath>
#include "point.h"
#include "city.h"
#include "citylist.h"

using namespace std;


void CityList::buildList(short num)
{
    City newCity;
    vector<City> list;
    list = getList();

    for (short i = 0; i < num; i++)
    {
        newCity.input();
        list.push_back(newCity);
    }
    setList(list);
    return;
}

void CityList::printList(void)
{
    vector<City> myList;
    City currentCity;
    myList = list;
    cout << "City List!\n   Name\t\tCoordinates\n";

    for (vector<City>::size_type i = 0; i < myList.size(); i++)
    {
        currentCity = list[i];
        cout << i + 1 << ": ";
        currentCity.printCity();
    }
    return;
}
