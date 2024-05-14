#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<cmath>
#include "point.h"
#include "city.h"
#include "citylist.h"

using namespace std;


int main(void)
{
    //declaring variables
    CityList myList;
    vector<City> cities;
    char menu;
    bool repeat = true;
    do
    {
        cout << "MAIN MENU\n1. Enter city info\n2. calculate Distance between"
            << " two cities\n3. Print cities\n4. Quit\n";
        cin >> menu;
        menu = tolower(menu);

        switch (menu)
        {
        case '1': case 'e':
        {
            short num;
            cout << "How many cities will you enter? (max 9)\n";
            cin >> num;
            myList.buildList(num);
            cities = myList.getList();
        }break;
        case '2': case 'd':
        {
            //Declaring variables
            City city1,
                 city2;
            Point loc1,
                  loc2;
            string name1,
                   name2;
            double dist;
            short input1,
                  input2;
            bool skip = false;

            //check for less than 2 cities
            if (cities.size() < 2)
            {
                cerr << "You need to enter at least 2 cities!\n";
                break;
            }

            //checking for exactly 2 cities
            else if (cities.size() == 2)
            {
                input1 = 1;
                input2 = 2;
                skip = true;
            }

            //if 2 cities then skip this loop
            if (!skip)
            {
                cout << "Pick the first city!\n";
                myList.printList();
                cin >> input1;
                cout << "Pick the second city!\n";
                myList.printList();
                cin >> input2;
                while (input1 == input2)
                {
                    cerr << "The distance between those is 0 genius. Pick a "
                        << "DIFFERENT city!\n";
                    cin >> input2;
                }
            }

            //accessing data
            city1 = cities[input1 - 1];
            city2 = cities[input2 - 1];
            loc1 = city1.getLocation();
            loc2 = city2.getLocation(); 
            name1 = city1.getName();
            name2 = city2.getName();
           
            //calculation
            dist = loc1 - loc2;
           
            //results
            cout << name1 << " is " << dist << " units away from " << name2
                << ".\n";
        }break;
        case '3': case 'p':
        {
            myList.printList();
        }break;
        case '4': case 'q': case 'x':
        {
            repeat = false;
        }break;
        default:
        {
            cerr << "Invalid menu selection, Try again!\n";
        }break;
        }
    } while (repeat);

   
    return 0;
}

