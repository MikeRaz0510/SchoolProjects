/*	Mike Rasmussen
*	z1696323
*	CSCI340 PE1
* 
*	I certify that this is my own work and where appropriate an extension 
* 	of the starter code provided for the assignment.
*/

#include <iostream>
#include <string>
#include <deque>
#include <stack>
#include "car.h"
#include "garage.h"

using namespace std;

void get_input_vals(const std::string &line, char &xact_type, std::string &license);


int main(void)
{
    /*
    *Write a main() to read the transaction records from stdin, 
    *parse them by calling get_input_vals(), and process an arrival 
    *or departure based on the value of the transaction code by 
    *calling the appropriate method on a garage object (that should 
    *be a variable in your main().) 
    * 
    */

    string input;
    char act = '\0';
    string license = "";
    garage garageName;
    bool repeat = true;

    //make this a do/while loop
    do
    {
        getline(cin, input);
        get_input_vals(input, act, license);

        if (input == "")
        {
            repeat = false;
            break;
            
        }

        switch (act)
        {
            case 'A':  {garageName.arrival(license);}break;
            case 'D':  {garageName.departure(license);}break;
            default: {cout << "\'"<< act << '\'' <<": invalid action!\n";}break;
        }

        cout << endl;

    } while (!cin.fail() && repeat);

}

/**
 * @brief This function will read in the input and then either add or remove
 *        cars from the garage
 * 
 * @param line The full line of input incuding the action and license
 * @param xact_type the action of the vehicle, either arival or departue
 * @param license  the license of the car that will be making an action
 ************************************************************************/
void get_input_vals(const std::string &line, char &xact_type, std::string &license)
{
    /*
    *This is a helper function that extracts the individual components 
    *to an arrival or a departure event, and license is the license plate 
    *number of the arriving/departing car
    * 
    */

    char delim = ':';
   
    //find the positions of the : chars 
    size_t pos = line.find_first_of(delim);
    size_t pos2 = line.find_last_of(delim);
   
    //set license to be the supstring between the : chars
    license = line.substr(pos+1, pos2-2);
    xact_type = line[0];

   return;

}


// car.h methods
/**
 * @brief This function increases the number of moves that the car makes
 *        it returns nothing 
 ************************************************************************/
void car::move()
{
    ++num_moves;
    return;
}

/**
 * @brief This is an accessor for the private num_moves variable
 * 
 * @return returns the number of moves as an int
 ************************************************************************/
int car::get_num_moves() const
{
    return num_moves;
}

/**
 * @brief This is an accessor for the private license variable
 * 
 * @return returns the license as a string
 ************************************************************************/
const string &car::get_license() const
{
    return license;
}

/**
 * @brief Overload the << operator
 * 
 * @param lhs the steam we will be returning to the function
 * @param rhs the object that we are trying to print out the id and license of
 * @return std::ostream& 
 ************************************************************************/
std::ostream& operator<<(std::ostream& lhs, const car& rhs)
{
    lhs << "Car " << rhs.id << " with license plate \"" << rhs.license << "\"";
    return lhs;
}

// garage.h methods

/**
 * @brief This method adds the car to the garage
 * 
 * @param license it takes in the license of the car being added
 ************************************************************************/
void garage::arrival(const std::string &license)
{
    /*
     *
     *Create a car object and use it to print itself as part of a message 
     *announcing its arrival. If the garage is already full of cars (as defined 
     *by parking_lot_limit) then print a message so indicating that fact (see the 
     *reference output.) If the garage is not already full then add the car to the 
     *parking_lot deque.
     *
     */
    //create a new car object
    car newCar(next_car_id, license);

    cout << newCar << " has arrived.\n";
    ++next_car_id;

    //see if there is room in the garage
    if (parking_lot_limit == parking_lot.size())
    {
        cout << "    But the garage is full!\n";
    }
    else
    {
        //add car to the back of the deque
        parking_lot.push_back(newCar);
    }

    return;
}

/**
 * @brief This method removes a car from the garage. It moves all the other cars 
 *        ahead of the one being removed and places them back where they were
 * 
 * @param license it takes in the license of the car being removed
 ************************************************************************/
void garage::departure(const std::string &license)
{

    /*
     *
     *Check each of the car elements in the parking_lot deque to see if any of 
     *them have the given license. If no such car is found then print a message 
     *stating that "the garage is full" (see the reference output for specific 
     *formatting.) Otherwise (the car has been found), move the car elements 
     *that are in the way (that are closer to the exit) one at-a-time out of 
     *the deque and into a std::stack<car> (increasing the number of times each 
     *have been moved along the way) and then:
     *
     *   *Remove the car with the given license from the parking_lot deque
     *
     *   *Print the removed car's information and the fact that it has departed 
     *    and the number of times it has been moved (plus 1 for the departure!... 
     *    see reference output for formatting.)
     *   
     *   *Move all the cars in the stack back into the deque so that they remain in
     *   the same order that they were before.
     * 
     * 
     */

    bool found = false;
    size_t pos = 0;
    stack<car> parkOrder;
    int moves;

    //search for a car with the license plate given
	for (size_t i = 0; i < parking_lot.size(); ++i)
	{
		if (parking_lot[i].get_license() == license)
        {
            found = true;
            pos = i;
            break;
        }
        
    }
    
    
    if (found)
    {
        //counter for number of cars moved
        int numOfCarsMoved = 0;

        //we need to move all the cars in front of the car trying to leave
        //therefore we can move cars until we get the the position of the car
        //trying to leave
        while (numOfCarsMoved <= static_cast<int>(pos))
        {                
            //When we get to the car leaving
            if (numOfCarsMoved == static_cast<int>(pos))
            {
                parking_lot.front().move();
                moves = parking_lot.front().get_num_moves();

                //print departing message
                cout << parking_lot.front() << " has departed,\n";
                cout << "    car was moved " << moves << " time" << (moves > 1 ? "s" : "") << " in the garage.\n";
                
                //remove the car from the deque
                parking_lot.pop_front();
                
            }

            //While we are at a car not leaving
            else
            {
                //Add the front car to the stack
                parkOrder.push(parking_lot.front());
                
                //remove the front car from the deque
                parking_lot.pop_front();
            
            }

            //incement number of cars moved
            ++numOfCarsMoved;
            
        }

        //empty the stack back into the deque
        while (!parkOrder.empty())
        {
            //put the top of the stack on the front of the deque
            parking_lot.push_front(parkOrder.top());

            //up the car num_of_moves counter
            parking_lot.front().move();

            //remove the top of the stack
            parkOrder.pop();
        }        
    }

    //if not found
    else
    {
        cout << "No car with license plate \"" << license << "\" is in the garage.\n";
    }
        

	

}

