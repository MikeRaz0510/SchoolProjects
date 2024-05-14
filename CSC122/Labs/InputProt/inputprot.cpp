#include<iostream>
#include<cctype>
#include<limits>
#include<string>

using namespace std;

template <typename inputValType>
inputValType inputVal(void)
{
    inputValType input;

    cin >> input;
    while (cin.fail())
    {
        cerr << "Invalid entry!";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input;
    }

    return input;
}

template <typename inputProtType>
inputProtType inputProt(inputProtType lowBound, inputProtType  upBound,
                        string prompt)
{
    inputProtType num;
    bool validEntry;

    do
    {
        validEntry = false;
        cout << prompt;
        num = inputVal();
        if (num < lowBound)
        {
            cerr << "Entered number too low!\n";
        }
        else if (num > upBound)
        {
            cerr << "entered number too high!\n";
        }
        else
        {
            validEntry = true;
        }
    } while (!validEntry);


    return num;

}

int main(void)
{
    double num;
    string prompt;

    prompt =  "Enter a number between 0 and 100!\t";
    num = inputProt(0.0, 100.0, prompt);

    cout << "your number is " << num << "!\n";




    return 0;
}




