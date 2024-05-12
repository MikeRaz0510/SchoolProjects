/*	Mike Rasmussen
*	z1696323
*	CSCI340 PE1
* 
*	I certify that this is my own work and where appropriate an extension 
* 	of the starter code provided for the assignment.
*/

#include "graph.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <list>

/**
 * @brief This function is a depth first traversal of the graph. It prints
 *        out the traversal and the edges it has traversed
 * 
 * @param v the current vertex index
***************************************************************************/
void Graph::Depthfirst(int v) 
{
    //declare variables
    int gSize = this->Getsize();
    std::vector<bool> visited(gSize, false);
    std::vector<char> verticies {'A','B','C','D','E','F','G'};

    //set current vertex to visited
    visited[v] = true;

    std::cout << verticies[v] << " ";

    for (auto i = adj_list[v].begin(); i != adj_list[v].end(); ++i)
    {
        if (!visited[*i])
        {
            Depthfirst(*i);
        }
    }    
    
}
/**
 * @brief Construct a new Graph:: Graph object
 * 
 * @param filename The name of the file we are reading from
***************************************************************************/

Graph::Graph(const char* filename)
{
    //declare variables
    std::ifstream inputFile;
    std::string inputString;
    int count = 0;


   //open the file
    inputFile.open(filename);

    //Read in size
    inputFile >> size;

    //read in lines until there is no more input
    while(getline(inputFile, inputString))
    {
        //(re)set count to 0
        count = 0;

        //for the string we read in with getline
        for(int i = 0; inputString[i]; ++i)
        {
            //if there is a space or tab at the pos i
            if (inputString[i] != ' ' && inputString[i] != '\t')
            {
                //skip over all the spaces and tabs
                inputString[count++] = inputString [i];
            }
        }
        //set the input string at the position of the count to the null char
        inputString[count] = '\0';

        //if the labels vector is empty
        if (labels.empty())
        {
            //traverse the input string
            for (unsigned int i = 0; i < inputString.size(); ++i)
            {
                //if the input string is not a tab
                if (inputString[i] != '\t')
                {
                    //add the value at the pos i to the back of the labels vector
                    labels.push_back(inputString[i]);
                }
            }
        }
        //if labels vector already has values in it
        else
        {
            //create an empty temp list
            std::list<int> temp;

            //traverse the input string starting at pos1
            for (int i = 1; i <= size; ++i)
            {
                //if the value at the pos i is equal to 1
                if (inputString[i] == '1')
                {
                    //store the loaction of all the 1s inside a temp list
                    temp.push_back(i);
                }
            }
            //add the temp list to the vector
            adj_list.push_back(temp);
        }
    }   

    //close the file
    inputFile.close();
}

/**
 * @brief Destroy the Graph:: Graph object
 * 
***************************************************************************/
Graph::~Graph()
{
    //clear the vectors
    adj_list.clear();
    labels.clear();
}

/**
 * @brief Accessor for the size variable
 * 
 * @return int returns the size of the graph
***************************************************************************/
int Graph::Getsize() const 
{ 
  return size;
}

/**
 * @brief 
 * 
***************************************************************************/
void Graph::Traverse() 
{
    std::cout << "------- traverse of graph ------" << std::endl;
    //traverse the graph
    Depthfirst(adj_list[1].front());
    std::cout << "--------- end of traverse -------" << std::endl;

}

/**
 * @brief Prints out the graph
 * 
***************************************************************************/
void Graph::Print() const 
{
    //declare variables
    std::vector<char> verticies {'A','B','C','D','E','F','G'};
    int gSize = this->Getsize();

    std::cout << "Number of verticies in the graph: " << gSize << std::endl << std::endl;
    std::cout << "-------- graph -------\n";

    //traverse the labels
    for (int i = 0; i < gSize; ++i)
    {
        //print the labels
        std::cout << labels[i] << ": ";
        int printed = 0;
        
        //print out the adjactnt vertecies
        for (auto j: adj_list[i])
        {
            //if the vertex is the first one on the line, dont print a , in front
            if(printed == 0)
            {
                std::cout << verticies[j-1];
            }
            else
            {
                std::cout << ", " << verticies[j-1];
            }
            //update the count
            ++printed;
        }
        std::cout << std::endl;
    }

    std::cout << "------- end of graph ------" << std::endl << std::endl;
    return;
}