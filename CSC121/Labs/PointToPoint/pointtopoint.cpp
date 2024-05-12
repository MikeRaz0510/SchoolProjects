#include<iostream>
#include<limits>

using namespace std;

int main(void)
{
    double x1, x2, x3, y1, y2, y3; // Variables
    char open, comma, close;

    // welcome message and asking for point 1
    cout << "\n\t\tWelcome to Mike's Midpoint Calculator\n\n"
        << "Please enter the coordiantes for the first point in"
        << " standard notation. (x,y)\n"; 
    cin >> open >> x1 >> comma >> y1 >> close; // reading the first point

    // checking to see if the point was entered in standard notation

    while (open != '(' || comma != ',' || close != ')')
    {
       
        cout << "ERROR: Please enter your point in standard notation. (x,y)\n";

        // checking to see if cin has failed.
        if (cin.fail())
        {
            // if cin has failed then clear and ignore it
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // ask for input again 
        cin >> open >> x1 >> comma >> y1 >> close;
    }
        //asking for point 2

    cout << "Please enter the coordainrtes for the second point in"
         << " standard notation. (x,y)\n";
    cin >> open >> x2 >> comma >> y2 >> close; // reading point 2

    // checking to see if the point was entered in statdard notation
    while (open != '(' || comma != ',' || close != ')')
    {
        cout << "ERROR: Please enter your point in standard notation\n";

        // checking to see if cin has failed.
        if (cin.fail())
        {
            // if cin has failed then clear and ignore
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // ask for input again
        cin >> open >> x2 >> comma >> y2 >> close;
    }

    x3 = (x1 + x2) / 2; // calculation for x coordinate of the midpoint
    y3 = (y1 + y2) / 2; // Calculation for y coordinate of the midpoint

    //showing the user the points they entered and the midpoint on the line
    //and thanking them for using the program
    cout << "\n\t\tCalculating\n\nThe midpoint on the line between ("
        << x1 << ',' << y1 << ") and (" << x2 << ','
        << y2 << ") is (" << x3 << "," << y3 
        << ")!\n\nThank you for using Mike's Resistance Calculator!\n";

    return 0;
}
