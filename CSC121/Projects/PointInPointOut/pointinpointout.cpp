#include<iostream>
#include<limits>
#include<cmath>

using namespace std;

int main(void)
{
    double x1, x2, x_midpoint, y1, y2, y_midpoint, x_distance, y_distance, line_distance; // Variables
    short error = 0; // error count
    char open, comma, close; // char variables can be reused

    // Asking for the first point
    cout << "Please enter the coordinates of the first point in standard"
        << "notation (x,y)\n";
    cin >> open >> x1 >> comma >> y1 >> close; //reading input for first point

    //checking to see if ( was enetered correctly and counting an error if it was

    if (open != '(')
    {
        cout << "You forgot to use an open parenthesis before the"
            << "x coordinate. Remember, standard notation is (x,y)\n";
        error++;
    }

    // checking to see if , was entered correctly and countintg an error if it was

    if (comma != ',')
    {
        cout << "You forgot to use a comma to seperate the points."
            << "Remember standard notation is (x,y)\n";
        error++;
    }

    // checking to see if ) was entered correctly and counting an error if it was

    if(close != ')')
    {
        cout << "You forgot to use an close parenthesis after the"
            << "y coordinate. Remember, standard notation is (x,y)\n";
        error++;
    }

    // if there were any errors remind user to use standard notation

    if (error >= 1)
    {
        cout << "\nPlease use standad notation! (x,y)\n";
    }

    // asking for second point
    cout << "Please enter the coordinmates of the second point"
        << "in standard notation.. (x,y)\n";
    cin >> open >> x2 >> comma >> y2 >> close; 
    error = 0; // reset error back to 0

        //checking to see if ( was enetered correctly and counting an error if it was

    if (open != '(')
    {
        cout << "You forgot to use an open parenthesis before the"
            << "x coordinate. Remember, standard notation is (x,y)\n";
        error++;
    }

    // checking to see if , was entered correctly and countintg an error if it was

    if (comma != ',')
    {
        cout << "You forgot to use a comma to seperate the points."
            << "Remember standard notation is (x,y)\n";
        error++;
    }

    // checking to see if ) was entered correctly and counting an error if it was

    if (close != ')')
    {
        cout << "You forgot to use an close parenthesis after the"
            << "y coordinate. Remember, standard notation is (x,y)\n";
        error++;
    }

    // if there were any errors remind user to use standard notation

    if (error >= 1)
    {
        cout << "\nPlease use standad notation! (x,y)\n";
    }




    x_midpoint = (x1 + x2) / 2;
    y_midpoint = (y1 + y2) / 2;

    cout << "The midpoint of the line segment between (" << x1 << ',' << y1
        << ") and (" << x2 << ',' << y2 << ") is (" << x_midpoint << ','
        << y_midpoint << ").\n";
    x_distance = x1 - x2;
    y_distance = y1 - y2;
    line_distance = sqrt(pow(x_distance, 2) + pow(y_distance, 2));
    cout << "The distance between (" << x1 << ',' << y1 << ") and (" << x2
        << ',' << y2 << ") is " << line_distance << " units.\n";








    return 0;
}
