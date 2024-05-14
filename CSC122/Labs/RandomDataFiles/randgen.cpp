#include<iostream>
#include<cstdlib>
#include<fstream>
#include<limits>
#include<string>
#include<vector>
#include<cctype>
#include "randgen.h"
#include "input.h"

using namespace std;


void randWhole(long maxL, long minL, short num)
{
    bool defs;
    defs = useDefs(maxL, minL, num);
    long randLong;
    ofstream reportFile;
    string fileName;
    if (!defs)
    {
        cout << "Enter your max whole number!\t";
        maxL = input(maxL);
        cout << "Enter your min whole number!\t";
        minL = input(minL);
        cout << "How many numbers would you like to generate?\t";
        num = input(num);
    }

    cout << "What would you like to name your file?\t";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    getline(cin, fileName);
    reportFile.open(fileName);

    for (long i = 1; i <= num; ++i)
    {
        randLong = genRandLong(maxL, minL);
        reportFile << randLong << endl;
    }

    reportFile.close();
    reportFile.clear();
}

void randDouble(double maxD, double minD, short num, short places)
{
    bool defs;
    defs = useDefs(maxD, minD, num, places);
    double randDouble;
    ofstream reportFile;
    string fileName;
    if (!defs)
    {
        cout << "Enter your max decimal number!\t";
        maxD = input(maxD);
        cout << "Enter your min decimal number!\t";
        minD = input(minD);
        cout << "How many numbers would you like to generate?\t";
        num = input(num);
        cout << "How many decimal places would you like?\t";
        places = input(places);

    }

    cout << "What would you like to name your file?\t";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    getline(cin, fileName);
    reportFile.open(fileName);

    for (long i = 1; i <= num; ++i)
    {
        randDouble = genRandDouble(maxD, minD);
        reportFile << fixed;
        reportFile.precision(places);
        reportFile << randDouble << endl;
    }

    reportFile.close();
    reportFile.clear();
}

void randChar(char maxC, char minC, short num)
{
    char randChar;
    bool defs;
    ofstream reportFile;
    string fileName;

    defs = useDefs(maxC, minC, num);

    if (!defs)
    {
        cout << "Enter your max character! "
            << "(for a - z, z is max and a is min)\t";
        maxC = input(maxC);
        cout << "Enter your min character!"
            << "(for a - z, z is max and a is min)\t";
        minC = input(minC);
        cout << "How many characters would you like to generate?\t";
        num = input(num);
    }

    cout << "What would you like to name your file?\t";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    getline(cin, fileName);
    reportFile.open(fileName);

    for (long i = 1; i <= num; ++i)
    {
        randChar = genRandChar(maxC, minC);
        reportFile << randChar << endl;
    }

    reportFile.close();
    reportFile.clear();
}

void randNames(short num, short type)
{
    vector<string> given{}, family{};
    ofstream reportFile;
    string name, fileName;

    cout << "What is the name of the file containing the given names?\t"
        << endl;
    given = vecStrIn();
   
    cout << "What is the name of the file containing the family names?\t"
        << endl;
    family = vecStrIn();

    if (!useDefs(num, type))
    {
        cout << "How many names do you have?\t";
        cin >> num;
        type = nametypes();
    }

    cout << "What would you like to name your file?\t";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    getline(cin, fileName);
    reportFile.open(fileName);

    for (long i = 1; i <= num; ++i)
    {
        name = genRandNames(given, family, type);
        reportFile << name << endl;
    }

    reportFile.close();
    reportFile.clear();

    return;

}

string genRandNames(vector<string> given, vector<string> family, short nametype)
{
    long randVal, randVal2, randVal3, middle;
    string name;
    switch (nametype)
    {
    case 1:
    {
        randVal = genRandLong(given.size() - 1, 0);
        name = given[randVal];
    }break;
    case 2:
    {
        randVal = genRandLong(family.size() - 1, 0);
        name = family[randVal];
    }break;
    case 3:
    {
        randVal = genRandLong(given.size() - 1, 0);
        randVal2 = genRandLong(family.size() - 1, 0);
        name = given[randVal] + ' ' + family[randVal2];
    }break;
    case 4:
    {
        middle = genRandLong(5, 1);
        randVal = genRandLong(given.size() - 1, 0);
        randVal2 = genRandLong(family.size() - 1, 0);
        middle < 4 ? randVal3 = genRandLong(given.size() - 1, 0)
            : randVal3 = genRandLong(family.size() - 1, 0);
        name = given[randVal] + ' ' + (middle < 4 ? given[randVal3]
            : family[randVal3]) + ' ' + family[randVal2];

    }break;
    default:
    {
        cerr << "Im not sure how you managed to break it, but you did!\n";
    }break;


    }

    return name;
}

bool useDefs(short& num, short& type)
{
    bool usedef = true;
    char input;

    cout << "Use default values? (Y/N) (Values listed below)\nNumber: "
        << num << "\nType: given names\n";

    cin >> input;
    input = toupper(input);
    input == 'Y' ? usedef = true : usedef = false;
    return usedef;
}

short nametypes(void)
{
    char input;
    short output;
    bool repeat = false;
    do
    {
        repeat = false;
        cout << "How many names should each person have?\n1. Given name\n"
            << "2. Family name\n3. given And family names\n"
            << "4. given Middle and family names\n";
        cin >> input;
        input = toupper(input);

        switch (input)
        {
        case '1': case 'G':
        {
            output = 1;

        }break;
        case '2': case 'F':
        {
            output = 2;

        }break;
        case '3': case 'A':
        {
            output = 3;

        }break;
        case '4': case 'M':
        {
            output = 4;

        }break;
        default:
        {
            cerr << "Invalid entry, try again!";
            repeat = true;
        }break;
        }
    } while (repeat);

    return output;
}
