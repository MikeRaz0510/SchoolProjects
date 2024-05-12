#include<iostream>
#include<vector>
#include<limits>
#include<cctype>
#include<iomanip>

using namespace std;
using VDPos = vector<double>::size_type;

//function prototypes
void display(vector<double> rod, short legnth);
void heatSim(vector<double>& rod, const short legnth, bool leftSide);
short valS_Input(void);
char valC_Input(void);

int main(void)
{
    //declare variables
    short legnth, startTemp, heat;
    char end;
    bool leftSide, repeat;

    //input legnth of the rod
    cout << "What is the size of the rod?\t";
    legnth = valS_Input();

    //input starting temperature
    cout << "What is the starting temperature of the rod?\t";
    startTemp = valS_Input();

    //display initial values
    cout << "\nThe initial temperature is " << startTemp
        << " degrees.\nThe rod is " << legnth << " inches long.\n";

    //initialize vector
    vector<double> rod(legnth, startTemp);

    //display starting state of the rod
    display(rod, legnth);

    //input for temperature on the end of the rod
    cout << "What is the temperature on the end of the rod?\n";
    heat = valS_Input();

    
    do
    {
        repeat = false; // set repeat to false
        cout << "What end of the rod are you "
            << "heating? (Right/Left)\n"; //input for right/left
        end = valC_Input(); 
        end = toupper(end); //making entry uppercase

        //switch to set the end value to the desired temp
        switch (end)
        {
        case 'R': rod[legnth - 1] = heat; leftSide = false; break;
        case 'L': rod[0] = heat; leftSide = true; break;
        default: cerr << "Invalid entry! Try again.\n"; repeat = true; break;

        }
    } while (repeat);

    //display rod at the start of heating
    cout << "At time = 0 the temperature of the rod is:\n";
    display(rod, legnth);

    //simulate the heat transfer
    heatSim(rod, legnth, leftSide);

    return 0;
}

//This function displays the values at each segment of the rod. It takes in 
//a vector and the legnth of it as a 
void display(vector<double> rod, short legnth)
{
    for (VDPos x = 0; x < legnth; x++)
    {
        cout << fixed << setprecision(2) << rod[x] << ' ';
    }
    cout << endl;
    return;
}

void heatSim(vector<double>& rod, const short legnth, bool leftSide)
{
    vector<double> preRod = rod;
    short timeSteps, skips;

    cout << "\nHow many seconds would you like to simulate?\t";
    timeSteps = valS_Input();

    cout << "\nDisplay results every nth step?\t";
    skips = valS_Input();

    for (short step = 1; step <= timeSteps; ++step)
    {
       
        for (VDPos x = 1; x < legnth - 1; x++)
        {
            if (leftSide)
            {
                rod[0] = preRod[0];                
                rod[legnth - 1] = ((preRod[legnth - 1] + preRod[legnth - 2]) / 2);
            }
            else
            {
                rod[legnth - 1] = preRod[legnth - 1];               
                rod[0] = ((preRod[0] + preRod[1]) / 2);

            }   

            rod[x] = ((preRod[x - 1] + preRod[x] + preRod[x + 1]) / 3);
           
           
            
        }
        preRod = rod;
        if (step % skips == 0)
        {
            cout << step << " Seconds: ";
            display(rod, legnth);
        }
    }
    cout << "After the time is up, the temperature of the rod will be:\n";
    display(rod, legnth);
}

short valS_Input(void)
{
    short input;
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (cin.fail())
    {
        cerr << "Invalid entry! Try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }
    return input;
}
char valC_Input(void)
{
    char input;
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (cin.fail())
    {
        cerr << "Invalid entry! Try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return input;
}
