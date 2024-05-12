/*	Mike Rasmussen
*	z1696323
*	CSCI340 PE1
* 
*	I certify that this is my own work and where appropriate an extension 
* 	of the starter code provided for the assignment.
*/


#include "twosearch.h"

#include <getopt.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/**
* see: 
* https://en.wikipedia.org/wiki/Usage_message
* https://www.ibm.com/docs/en/aix/7.2?topic=commands-usage-statements
*
* @param a0 The value of argv[0] (the name of the command) so that it 
*   can be printed.
*
* @note This function will terminate the application via exit(1).
******************************************************************************/
static void usage(const char *a0)
{
    std::cerr << "Usage: " << a0 << " [-l rand_low] [-h rand_high] [-a a_size] [-b b_size] [-x a_seed] [-y b_seed] [-c print_cols] [-w col_width]" << std::endl;
    std::cerr << "    rand_low   = rand() low bound (default=1)" << std::endl;
    std::cerr << "    rand_high  = rand() high bound (default=1000)" << std::endl;
    std::cerr << "    a_size     = size of vector A (default=200)" << std::endl;
    std::cerr << "    b_size     = size of vector B (default=100)" << std::endl;
    std::cerr << "    a_seed     = random seed for vector A (default=1)" << std::endl;
    std::cerr << "    b_seed     = random seed for vector B (default=3)" << std::endl;
    std::cerr << "    print_cols = number of colums per line (default=16)" << std::endl;
    std::cerr << "    col_width  = printed column value width (default=4)" << std::endl;
    exit(1);
} // End of usage()

/**
* Parse the command-line args, create and sort vector A, create vector B,
* search vector A for those elements appearing in vector B using both
* a linear and binary search, and print the hit-rate (the percentage of 
* items in B that have been located in A.)
*
* If an invalid command-line arg is encountered, print a Usage statement 
* and terminte with an exit-status of 1.
*
* @return zero
******************************************************************************/
int main(int argc, char **argv)
{
    // Demonstrate the use of getopt() to override default config parameters 
    int rand_low = 1;
    int rand_high = 1000;
    int a_size = 200;
    int b_size = 100;
    int a_seed = 1;
    int b_seed = 3;
    int print_cols = 16;
    int col_width = 4;

    int opt;
    // see: http://faculty.cs.niu.edu/~winans/CS340/2022-sp/#getopt
    while ((opt = getopt(argc, argv, "a:b:c:h:l:w:x:y:")) != -1)
    {
        switch(opt)
        {
        case 'a':
            // see https://en.cppreference.com/w/cpp/string/basic_string/stol
            a_size = std::stoi(optarg); // override the default for a_size
            break;

        case 'b':
            b_size = std::stoi(optarg);
            break;
        case 'c':
            print_cols = std::stoi(optarg);
            break;
        case 'h':
            rand_high = std::stoi(optarg);
            break;
        case 'l':
            rand_low = std::stoi(optarg);
            break;
        case 'w':
            col_width = std::stoi(optarg);
            break;
        case 'x':
            a_seed = std::stoi(optarg);
            break;
        case 'y':
           // b_seed = std::stoi(optarg);
            break;
            
        default:
            // got an arg that is not recognized...
            usage(argv[0]);     // pass the name of the program so it can print it
        }
    }

    // Make sure there are not any more arguments (after the optional ones)
    if (optind < argc)
        usage(argv[0]);

    // Add application logic here...
    /**
     * Define two vectors (A and B) with sizes a_size and b_size.
     * Pass the A vector to init_vector(...) with the coresponding seed value a_seed, rand_low, and rand_high.
     * Pass the B vector to init_vector(...) with the coresponding seed value b_seed, rand_low, and rand_high.
     * Print the elements of the A vector by calling the subroutine print_vector(...).
     * Sort the elements of the A vector by calling the subroutine sort_vector(...).
     * Print the elements of A vector after sorting its elements by calling the subroutine print_vector(...).
     * Print the elements of the B vector by calling the subroutine print_vector(...).
     * Search for each value in vector B in vector A using the linear search algorithm by calling the subroutine search_vector(...).
     * Print the statistical values for the linear search by calling the subroutine print_stat().
     * Search for each value in vector B (again) in vector A using the binary search algorithm by calling the subroutine search_vector(...).
     * Print the statistical values for the binary search by calling the subroutine print_stat().
     */

    //Define two vectors (A and B) with sizes a_size and b_size.
    vector<int> A(a_size,0), B(b_size,0);

    //Pass the A vector to init_vector(...) with the coresponding seed value a_seed, rand_low, and rand_high.
    init_vector(A, a_seed, rand_low, rand_high);
    //Pass the B vector to init_vector(...) with the coresponding seed value a_seed, rand_low, and rand_high.
    init_vector(B, b_seed, rand_low, rand_high);

    //Print the elements of the A vector by calling the subroutine print_vector(...).
    cout << "Vector A:\n";
    print_vector(A, print_cols ,col_width);

    //Sort the elements of the A vector by calling the subroutine sort_vector(...).
    sort_vector(A);

    //Print the elements of A vector after sorting its elements by calling the subroutine print_vector(...).
    cout << "Vector A Sorted:\n";
    print_vector(A, print_cols, col_width);

    //Print the elements of the B vector by calling the subroutine print_vector(...).
    cout << "Vector B:\n";
    print_vector(B, print_cols, col_width);

    //Search for each value in vector B in vector A using the linear search algorithm by calling the subroutine search_vector(...).
    int found = search_vector(A,B, &linear_search);

    //Print the statistical values for the linear search by calling the subroutine print_stat().
    cout << "Linear Search: ";
    print_stat(found, A.size());

    //Search for each value in vector B (again) in vector A using the binary search algorithm by calling the subroutine search_vector(...).
    found = search_vector(A,B, &binary_search);

    //Print the statistical values for the binary search by calling the subroutine print_stat().
    cout << "Binary Search: ";
    print_stat(found, A.size());










    





    return 0;

} // End of main()

// Function Definitions

/**
 * @brief Assign random valued to the elements in vec by using the seed value.
 * Initialize the random number generator by calling srand(seed) and then
 * generate a random number between lo and hi by using rand()%(hi-lo+1)+lo.
 * 
 * @param vec The vector that we are initilizing. we are calling it by reference 
 * so we are chaging that vector.
 * 
 * @param seed The seed we are using to generate random numbers
 *  
 * @param lo The lowest number we want to randomly generate
 *  
 * @param hi The higest number we want to randomly generate
 * 
 */
void init_vector(std::vector<int> &vec, int seed, int lo, int hi)
{
    int size= vec.size();

    //Initialize the random number generator by calling srand(seed)
    srand(seed);

    //Assign random valued to the elements in vec
    for (int i = 0; i < size; i++)
    {
        //generate a random number between lo and hi by using rand()%(hi-lo+1)+lo
        vec[i] = rand() % (hi - lo + 1) + lo;
    }
    return;
}

/**
 * @brief Print the given vector v with print_cols elements on each line and with 
 * each numeric value padded out to col_width wide (use std::setw()). See the 
 * reference output for the formatting details and alignment. Note that there 
 * is an aditional space printed after the element value and before the 
 * pipe character |.
 * 
 * @param v The vector that we want to print
 * 
 * @param print_cols the number of columns to print.
 *  
 * @param col_width The width of the columns printed.
 */
void print_vector(const std::vector<int> &v, int print_cols, int col_width)
{
    //using this variable to fill out the vector tables with blank spaces
    int colPosTracker = 0;

    //Formating line of dashes on top of table
    cout << string((col_width * print_cols) + print_cols + 1, '-') << endl << '|';
    
    //Print the given vector v
    for (int i = 0; i < static_cast<int>(v.size()); i++)
    {
        //using setw() to set width of each column
        cout << setw(col_width - 1) << v[i] << " |";
        
        //adding a new row after the 16th number in the vector 
        if (i % print_cols == print_cols - 1)
        {
            cout << "\n|";
        }

        //filling in the last row of the table with blank spaces
        while (i == static_cast<int>(v.size()) - 1 && (i % print_cols) + colPosTracker < print_cols - 1)
        {
            cout << string(col_width, ' ') << '|';
            colPosTracker++;
        }
    }

    //Formating line of dashes on bottom of table
    cout << endl << string((col_width * print_cols) + print_cols + 1, '-') << endl;
    return;
}

/**
 * @brief Implement a sort algorithm to sort the elements of vector v in ascending 
 * order. For this function, use the std::sort() function from the STL.
 * 
 * @param v The vector we will sort.
 */
void sort_vector(std::vector<int> &v)
{
    //Implement a sort algorithm to sort the elements of vector v in ascending order
    sort(v.begin(), v.end());
    return;

}
/**
 * @brief Implement a generic search algorithm. This will take a pointer to 
 * the search routine p() that must be called once for each element that is 
 * in v2 to be searched for in v1. It must count the number of successful 
 * searches and return that value. (Note that this returned value is one 
 * of the parameters to be passed to print_stat() in your main().
 * 
 * @param v1 The vector that will be searched.
 * 
 * @param v2 The vector that will search for its values in another vector
 *  
 * @param p a Pointer to the search algorithm to be used.
 *  
 * @return int 
 */
int search_vector(const std::vector<int> &v1, const std::vector<int> &v2, bool (*p)(const std::vector<int> &, int))
{
    //Implement a generic search algorithm
    int count = 0;

    for (unsigned int i = 0; i < v2.size(); i++)
    {
       if (p(v1, v2[i]))
       {
        count++;
       }
    }
    return count;
}   
/**
 * @brief Print the percent of successful searches as a floating-point 
 * number on stdout, where found is the total number of successful 
 * searches and total is the size of the test vector that is searched. 
 * Note that the reference output includes test printed from main() 
 * that indicates the type of search and output from print_stat() 
 * that indicates portion of the output that is the same for both 
 * searches and the percentage.
 * 
 * @param found The number of items for vector B succesfully found in
 * Vector A.
 *  
 * @param total The total number of items searched in Vector A.
 */
void print_stat(int found, int total)
{
    //Print the percent of successful searches
    double percent = static_cast<double>(found) / total;
    cout << fixed << setprecision(2);
    cout << "Percent of sucessful searches = " << percent * 100 << '%' << endl;

    return;
}
/**
 * @brief A linear search algorithm, where x is the value to search for 
 * in vector v. It simply starts searching for x from the beginning of 
 * vector v to the end, but it stops searching when there is a match. If 
 * the search is successful, it returns true; otherwise, it returns false. 
 * To implement this routine, use the std::find() function from the 
 * STL: https://en.cppreference.com/w/cpp/algorithm/find Note that 
 * std::find() requires the use of iterators to specify the range of 
 * values to check in v. See https://en.cppreference.com/w/cpp/container/vector 
 * for a discussion of how to use vector.begin() and vector.end() to get 
 * the iterators needed for std::find(). Note that the example on page 
 * https://en.cppreference.com/w/cpp/container/vector/begin that shows 
 * how to call std::accumulate() looks very similar to how you need 
 * to call std::find()!
 * 
 * @param v This is the vector being searched.
 * 
 * @param x This is the value we are searching for
 *  
 * @return true = value found 
 * @return false = value not found
 */
bool linear_search(const std::vector<int> &v, int x)
{
    bool found = false;
    
    auto it = find(v.begin(), v.end(), x);

    (it != v.end()) ? found = true : found = false;

    return found;

}
/**
 * @brief A binary search algorithm, where x is the value to search for 
 * in vector v. If the search is successful, it returns true; otherwise, 
 * it returns false. To implement this routine, simply call the 
 * std::binary_search() function from the 
 * STL: https://en.cppreference.com/w/cpp/algorithm/binary_search 
 * Note that the example showing how to call std::binary_search() is 
 * exactly the same way you want to call std::find() in your 
 * linear_search() function!
 * 
 * @param v This is the vector being searched
 * 
 * @param x This is the value we are searching for
 * 
 * @return true = value found
 * 
 * @return false = value not found
 */
bool binary_search(const std::vector<int> &v, int x)
{
    return binary_search(v.begin(), v.end(), x);
}

