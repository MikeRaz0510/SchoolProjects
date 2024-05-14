#include<iostream>
#include<cctype>
#include<vector>
#include<string>
#include "box.h"

using namespace std;


void box::printBox(vector<string> vec)
{
    for (vector<string>::size_type i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << endl;
        ;
    }

    return;
}

short box::lWord(const vector<string> & vec)
{
    short longest = 0;

    for (vector<string>::size_type i = 0; i < vec.size(); i++)
    {
        if (vec[i].size() > longest)
        {
            longest = vec[i].size();
        }
    }
    return longest;
}

void box::boxifyC(void)
{
    short longest = 0;
    char userSymbol;
    vector<string> myWords;
    string tandb;
 

    userSymbol = get_symbol();
    myWords = getWords();
    longest = lWord(myWords) + 2;
    tandb = string(longest, userSymbol);

    for (vector<string>::size_type i = 0; i < myWords.size(); i++)
    {
        if (myWords[i].size() < longest && myWords[i][0] != userSymbol)
        {
            myWords[i].insert(0, 1, userSymbol);
            myWords[i].push_back(userSymbol);
        }
        while (myWords[i].size() < longest)
        {

            myWords[i].insert(1, 1, ' ');
            if (myWords[i].size() < longest)
            {
                myWords[i].insert(myWords[i].size() - 1, 1, ' ');
            }

        }
    }

    cout << tandb << endl;
    printBox(myWords);
    cout << tandb << endl;
}


void box::boxifyL(void)
{
    short longest = 0;
    char userSymbol;
    vector<string> myWords;
    string tandb;

    userSymbol = get_symbol();
    myWords = getWords();
    longest = lWord(myWords) + 2;
    tandb = string(longest, userSymbol);

    for (vector<string>::size_type i = 0; i < myWords.size(); i++)
    {
        if (myWords[i].size() < longest && myWords[i][0] != userSymbol)
        {
            myWords[i].insert(0, 1, userSymbol);
            myWords[i].push_back(userSymbol);
        }
        while (myWords[i].size() < longest)
        {
            myWords[i].insert(myWords[i].size() - 1, 1, ' ');
        }
    }

    cout << tandb << endl;
    printBox(myWords);
    cout << tandb << endl;
}


void box::boxifyR(void)
{
    short longest = 0;
    char userSymbol;
    vector<string> myWords;
    string tandb;

    userSymbol = get_symbol();
    myWords = getWords();
    longest = lWord(myWords) + 2;
    tandb = string(longest, userSymbol);

    for (vector<string>::size_type i = 0; i < myWords.size(); i++)
    {
        if (myWords[i].size() < longest && myWords[i][0] != userSymbol)
        {
            myWords[i].insert(0, 1, userSymbol);
            myWords[i].push_back(userSymbol);
        }
        while (myWords[i].size() < longest)
        {
            myWords[i].insert(1, 1, ' ');
        }
    }

    cout << tandb << endl;
    printBox(myWords);
    cout << tandb << endl;
}

std::vector<std::string> box::seperateLine(std::string line)
{
    std::vector<std::string> newWords;
    std::string newline;
    for (std::string::size_type i = 0; i < line.size(); i++)
    {
        newline += line[i];
        if (isspace(line[i + 1]))
        {
            newWords.push_back(newline);
            newline = "";
            i++;
        }
    }
    newWords.push_back(newline);
    newline = "";

    return newWords;
}
