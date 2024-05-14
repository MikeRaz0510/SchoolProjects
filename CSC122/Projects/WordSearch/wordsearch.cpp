#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cctype>
#include "randgen.h"
#include "morevec.h"

using namespace std;


long chooseDirection(void);
bool placedSuccessful(vector<vector<char>>& grid, string word, short gridsize);
void userGuess(char& guess1, char& guess2);


int main(void)
{
    vector<string> wordList, wordBank;
    string longestWord,
        word;
    long placeholder;
    short gridsize;
    char guess1,
        guess2;

    srand(static_cast<unsigned>(time(nullptr)));
   
    wordList = vecStrIn();
    cout << "Calcualting size...\n";
    placeholder = wordList.size();
    cout << placeholder << endl;

    cout << "Selecting word bank...\n";

    wordBank = selectWords(wordList);
    lowercase(wordBank);
    cout << "Selection complete!\nHere are your words!\n";
    vecPrint(wordBank);

    cout << "Finding Longest word...\n";
    longestWord = longestWordInVec(wordBank);
    cout << "Foud longest word! The longest word is " << longestWord
        << "!\nIt is " << longestWord.size() << " characters long!\n";
    gridsize = static_cast<short>(longestWord.size()) + 4;

    vector<vector<char>> grid(gridsize, vector<char>(gridsize, '0'));
    
    
    for (short i = 0; i < gridsize; i++)
    {
        for (short j = 0; j < gridsize; j++)
        {
            grid[0][i] = i + 65;
            grid[j][0] = j + 65;
            grid[i][gridsize-1] = i + 65;
            grid[gridsize - 1][j] = j + 65;
        }
    }
    for (short i = 1; i < gridsize - 1; i++)
    {
        for (short j = 1; j < gridsize - 1; j++)
        {
            grid[i][j] = genRandChar('z', 'a');
        }
    }
    
    
    for (vector<string>::size_type i = 0; i < wordBank.size(); ++i)
    {
        word = wordBank[i];
        if (placedSuccessful(grid, word, gridsize))
        {
            cout << "Word Placed!\n";
            //printGrid(grid, gridsize);
        }
        else
        {
            cerr << "FAILED!\n";
        }
    }

    printGrid(grid, gridsize);
    vecPrint(wordBank);

    userGuess(guess1, guess2);


    return 0;
}


long chooseDirection(void)
{
    long num;
    num = genRandLong(8, 1);
    return num;
}

bool placedSuccessful(vector<vector<char>>& grid, string word, short gridsize)
{
    bool repeat,
         placed;
    long rand1,
         rand2;
    long way;

    do
    {
        repeat = false;
        way = chooseDirection();
        rand1 = genRandLong(gridsize - 2 , 1);
        rand2 = genRandLong(gridsize - 2 , 1);
        cout << way << ' ' << rand1 << ' ' << rand2 << ' ' << word << ' ' << word.size() << endl;
        switch (way)
        {
        case 1: //right
        {
            
            if ((rand2 + static_cast<long>(word.size()) < (gridsize - 2)))
            {
                for (string::size_type j = 0; j < word.size(); ++j)
                {
                    grid[rand1][rand2] = word[j];
                    rand2++;
                }
            }
                else
                {
                    repeat = true;
                    placed = false;
                    cerr << "Place failed trying again!\n";
                    break;
                }

            
        }break;
        case 2: //left
        {
                if (rand2 - static_cast<long>(word.size()) > 1)
                {
                    cout << rand2 - word.size() << endl;
                    for (string::size_type j = 0; j < word.size(); ++j)
                    {
                        grid[rand1][rand2] = word[j];
                        rand2--;
                    }
                }
                else
                {
                    repeat = true;
                    placed = false;
                    cerr << "Place failed trying again!\n";
                    break;
                }
            
        }break;
        case 3: //down
        {
            
                if ((rand1 + static_cast<long>(word.size()) < (gridsize - 2)))
                {
                    for (string::size_type j = 0; j < word.size(); ++j)
                    {
                        grid[rand1][rand2] = word[j];
                        rand1++;
                    }
                }
                else
                {
                    repeat = true;
                    placed = false;
                    cerr << "Place failed trying again!\n";
                    break;
                }
            
        }break;
        case 4: // up
        {
            
            if (rand1 - static_cast<long>(word.size()) > 1)
            {
                for (string::size_type j = 0; j < word.size(); ++j)
                {
                    grid[rand1][rand2] = word[j];
                    rand1--;
                }
            }
                else
                {
                    repeat = true;
                    placed = false;
                    cerr << "Place failed trying again!\n";
                    break;
                }
            
        }break;
        case 5: //up right
        {
            
            if ((rand1 - static_cast<long>(word.size()) > 1) &&
                (rand2 + static_cast<long>(word.size()) < (gridsize - 2)))
            {
                for (string::size_type j = 0; j < word.size(); ++j)
                {
                    grid[rand1][rand2] = word[j];
                    rand1--;
                    rand2++;
                }
            }
                else
                {
                    repeat = true;
                    placed = false;
                    cerr << "Place failed trying again!\n";
                    break;
                }
            
        }break;
        case 6: //up left
        {
            if ((rand1 - static_cast<long>(word.size()) > 1) && 
                (rand2 - static_cast<long>(word.size()) > 1))
            {
                cout << "I got here\n";
                cout << rand1 - word.size() << endl;
                cout << rand2 - word.size() << endl;
                for (string::size_type j = 0; j < word.size(); ++j)
                {
                    grid[rand1][rand2] = word[j];
                    rand1--;
                    rand2--;
                }
            }
                else
                {
                    repeat = true;
                    placed = false;
                    cerr << "Place failed trying again!\n";
                    break;
                }
            
        }break;
        case 7: //down right
        {
           
            if ((rand1 + static_cast<long>(word.size()) < (gridsize - 2)) &&
                (rand2 + static_cast<long>(word.size()) < (gridsize - 2)))
            {
                for (string::size_type j = 0; j < word.size(); ++j)
                {
                    grid[rand1][rand2] = word[j];
                    rand1++;
                    rand2++;
                }
            }
                else
                {
                    repeat = true;
                    placed = false;
                    cerr << "Place failed trying again!\n" ;
                    break;
                }
            
        }break;
        case 8: //down left
        {
            
            if ((rand1 + static_cast<long>(word.size()) < (gridsize - 2)) &&
                (rand2 - static_cast<long>(word.size()) > 1))
            {
                for (string::size_type j = 0; j < word.size(); ++j)
                {
                    grid[rand1][rand2] = word[j];
                    rand1++;
                    rand2--;
                }
            }
                else
                {
                    repeat = true;
                    placed = false;
                    cerr << "Place failed trying again!\n";
                    break;
                }
            
        }break;
        default:
        {
            cerr << "Sometihng really bad happened if youre seeing this :(\n";
        }
        break;
        }
        } while (repeat);
        placed = true;

        return placed;    
}

void userGuess(char & guess1, char & guess2)
{
    char comma;
    cout << "Type in the coordinates of the beginning of the word (ex: B,F)\t";
    cin >> guess1 >> comma >> guess2;
    guess1 = toupper(guess1);
    guess2 = toupper(guess2);

    cout << "You guessed " << guess1 << ',' << guess2 << "!\n";
    return;
}
