#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<limits>
#include"input.h"

using namespace std;

vector<string> vecStrIn(void)
{
    vector<string> names;
    string name;
    ifstream data_file;
    string fileName;


    getline(cin, fileName);
    data_file.open(fileName);

    while (data_file.fail())
    {
        cout << "Not a vaild file name! Please try again!\n";
        getline(cin, fileName);
        data_file.open(fileName);
    }

    data_file >> name;
    while (!data_file.fail())
    {
        names.push_back(name);
        data_file >> name;
    }
    data_file.clear();
    data_file.ignore(numeric_limits<streamsize>::max(), '\n');

    data_file.close();
    data_file.clear();

    return names;
}
