/*	Mike Rasmussen
*	z1696323
*	CSCI340 PE1
* 
*	I certify that this is my own work and where appropriate an extension 
* 	of the starter code provided for the assignment.
*/

#include "josephus.h"

#include <list>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <getopt.h>

using namespace std;


void print_underlined_string(const string &message);
void print_list(const list<string> &collection, const unsigned &eliminations, int num_cols);


/**
* Print a 'Usage' message and exit(1).
*
* @param a0 The name of the command to include in the usage message.
*****************************************************************************/
static void usage(const char *a0)
{
    std::cerr << "Usage: " << a0 << " [-n number of people] [-m modulus] [-p print frequency] [-c print columns]" << std::endl;
    exit(1);
}


/**
* Create a std::list of prople with generated ID/names and reduce the
* list as per the Josephus problem algorithm.
*****************************************************************************/
int main(int argc, char **argv)
{
    unsigned num_people = 41;       // The number of people to start with
    unsigned modulus = 3;           // The count used to determine the elimination
    unsigned print_frequency = 13;  // How often to print the state of the system
    unsigned num_cols = 12;         // Number of colums to print per line

    int opt;
    while ((opt = getopt(argc, argv, "n:m:p:c:")) != -1)
    {
        switch (opt)
        {
        case 'n':
            std::istringstream(optarg) >> num_people;
            break;
        case 'm':
            std::istringstream(optarg) >> modulus;
            break;
        case 'p':
            std::istringstream(optarg) >> print_frequency;
            break;
        case 'c':
            std::istringstream(optarg) >> num_cols;
            break;
        default:
            usage(argv[0]);
        }
    }

    if (optind < argc)
        usage(argv[0]); // If we get here, there was extra junk on command line

    /*
    The main() must create an empty std::list container and then call std::generate_n() 
    with a std::back_inserter on your, currently empty, list to insert the IDs/names for 
    the initial N number of people by using the provided generator class. Note that the SEQ 
    class is provided for use as the last argument to generate_n() that you will have to 
    construct passing it the number of people N for for which it will generate names 
    (for example SEQ(num_people). Once the list generated, print it using print_list() 
    and initialize an iterator to the first element in your list. Advance your iterator 
    by one each time through then loop until you reach the next element to eliminate. 
    After each elimination, if it is time, call print_list() to see an incremental state of the 
    elimination process. Your elimination loop continues until only one person remains in 
    the list where you will print the list one last time to see the last survivor.
    */

    unsigned int elims = 0;

    //The main() must create an empty std::list container
    list<string> myList;

    //call std::generate_n() with a std::back_inserter on your, currently empty, 
    //list to insert the IDs/names for the initial N number of people by using 
    //the provided generator class.
    generate_n(back_inserter(myList), num_people, SEQ(num_people));

    //Once the list generated, print it using print_list()
    print_list(myList, elims, num_cols);
    cout << endl;

    //initialize an iterator to the first element in your list.
    //Advance your iterator by one each time through then loop until you reach the next element to eliminate.
    int count = 0;
    for( auto it = myList.cbegin(); myList.size() > 1; ++it)
    {
            if(it == myList.cend())
            {
                it = myList.cbegin();
            }
        
        //after counting the number of people between eliminations
        if (count % modulus == (modulus-1))
        {

            //eliminate person at this positon
            it = myList.erase(it);
            --it; //update iterator so the next person isnt skipped
            ++elims; 

            //After each elimination, if it is time, call print_list() to see an incremental state of the 
            //elimination process.
            if (elims % print_frequency == 0)
            {
                print_list(myList, elims, num_cols);
                cout << endl;
            }
        }
        ++count;

    }    

    //print the list one last time to see the last survivor
    cout << "Eliminations Completed\n";
    print_list(myList, elims, num_cols);


  return 0;
}

/**
 * Print the given message with an underline that matches the length of the message text. 
 * Use this to print the heading for the list in print_list().
 *  
 * @brief This Function will print out a string of underlines that is as long as the message
 * 
 * @param message This is the message the function will take in and calculate how many underlines
 *                long the underline needs to be.
 ************************************************************************/
void print_underlined_string(const string &message)
{
    cout << message << endl << string(message.size(), '-') << endl;
}

/**
 * Print a heading including the number of eliminations and the contents of collection with num_cols
 * elements on each line. When eliminations is zero, print Initial group of people as the table heading. 
 * Otherwise, print After eliminating N people where N is the number of eliminations.
 * 
 * @brief This function will print out the list of people remaining
 * 
 * @param collection This is the list the function takes in to print out
 * @param eliminations this is the number of people that have been eliminated 
 *                     at the point that this print function has been called.
 * @param num_cols This is the number of columns to print per line.
 ************************************************************************/
void print_list(const list<string> &collection, const unsigned &eliminations, int num_cols)
{
    unsigned int pos = 0; //position tracker
    if (eliminations == 0)
    {
        print_underlined_string("Initial group of people");
    }
    //I made it say person for 1 elimination, but am leaving it out to match refrence outputs exactly :(
    /*
    else if (eliminations == 1)
    {
        print_underlined_string("After eliminating " + to_string(eliminations) + " person");

    }
    */
    else
    {
        // adds the number of eliminations to the message as a string
        print_underlined_string("After eliminating " + to_string(eliminations) + " people");

    }

    for (auto it=collection.cbegin(); it != collection.cend(); ++it)
    {   
        //print out the current person at the iterators position
        //if at the specified number of columns or the end of the list, go to a new line
        //else print a comma
        cout << *it << (((pos % num_cols == static_cast<unsigned int>(num_cols-1)) || (pos == collection.size()-1)) ? "\n" : ", ");
        ++pos;

    }
}
