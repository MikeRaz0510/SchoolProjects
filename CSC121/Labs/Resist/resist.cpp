#include <iostream>
#include <limits>

using namespace std;

int main(void)
{
	short  resist_1; //resistance 1
	short  resist_2; //resistance 2
	short resist_S; //resistance in serise
	double resist_P; //resistance in paralell

	// Welcome and asking for input
	cout << "\n\t\t Welcome to Mike's Resistance Calculator\n\n"
		<< "Please enter the resistance of your first resistor\n\n"; 

    cin >> resist_1;  // reading user input

    // ignoring anything entered after the resistance
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
		
    // asking for second input
	cout << "Please enter the resistance of your second resistor\n\n";
	cin >> resist_2; // reading uer input

    //ignoring extra input again
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
    // showing the user what they input
	cout << "You entered " << resist_1 << " ohms and " << resist_2 
		<< " ohms. \n";

    resist_S = resist_1 + resist_2;			// Calculating in Series
	resist_P = (1 / (1 / static_cast<double>(resist_1) 
		+ 1 / static_cast<double>(resist_2))); // Calculating in parallel

    // Showing the user the results and thanking them for using the program
	cout << "\n\t\tCalculating\n\nIf both resistors are placed in "
		<< "series, the total resistance would equal " << resist_S
		<< " ohms.\n\nIf both resistors are placed in parallel, the total"
		<< " resistance would equal " << resist_P << " ohms.\n\n"
		<< "Thank you for using Mike's Resistance Calculator!\n";
    
    return 0; 
}
