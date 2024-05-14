#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cctype>
#include <limits>
#include "randgen.h"
#include "morevec.h"

using namespace std;



vector<string> vecStrIn(void)
{
    vector<string> vecStr;
    string str;
    ifstream data_file;
    string fileName;

    cout << "What is the name of the file?\t";


    getline(cin, fileName);
    data_file.open(fileName);

    while (data_file.fail())
    {
        cout << "Not a vaild file name! Please try again!\n";
        getline(cin, fileName);
        data_file.open(fileName);
    }

    cout << "Reading word list...\n";

    data_file >> str;
    while (!data_file.fail())
    {
        vecStr.push_back(str);
        data_file >> str;
    }
    data_file.clear();
    data_file.ignore(numeric_limits<streamsize>::max(), '\n');

    data_file.close();
    data_file.clear();

    return vecStr;
}

vector<string> selectWords(vector<string> wordList)
{
    vector<string> wordBank;
    string word;
    long randLong;

    while (wordBank.size() < 10)
    {
        randLong = genRandLong(wordList.size() - 1, 0);
        word = wordList[randLong];
        wordBank.push_back(word);
    }

    return wordBank;
}

void vecPrint(vector<string> vec)
{
    for (vector<string>::size_type i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << (i % 5 == 4 ? '\n' : ' ');
    }
}

string longestWordInVec(vector<string> vec)
{
    string longest;

    for (vector<string>::size_type i = 0; i < vec.size(); ++i)
    {
        if (vec[i].size() > longest.size())
        {
            longest = vec[i];
        }
    }

    return longest;
}

void lowercase(vector<string>& vec)
{
    string word;
    for (vector<string>::size_type i = 0; i < vec.size(); ++i)
    {
        word = vec[i];
        for (string::size_type j = 0; j < word.size(); ++j)
        {
            word[j] = tolower(word[j]);
        }
        vec[i] = word;
    }
    return;
}

void uppercase(vector<string>& vec)
{
    string word;
    for (vector<string>::size_type i = 0; i < vec.size(); ++i)
    {
        word = vec[i];
        for (string::size_type j = 0; j < word.size(); ++j)
        {
            word[j] = toupper(word[j]);
        }
        vec[i] = word;
    }
    return;
}

void printGrid(vector<vector<char>> grid, short size)
{
    for (short i = 0; i < size; i++)
    {
        for (short j = 0; j < size; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
