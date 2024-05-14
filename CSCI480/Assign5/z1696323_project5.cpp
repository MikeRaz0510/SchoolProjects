/***********************************************
  Driver for Virtual Memory Simulation
  CSCI 480 
  Northern Illinois University
***********************************************/

/********************************************************************
CSCI 480 - Assignment 4 - Semester Spring 2024
Programmer: Mike Rasmussen
Section: 480-1
TA: Yuva Krishna Thanneru
Date Due: 4/17/2024
Purpose: This program simulates virtual memory using a page table
         and physical memory.
*********************************************************************/

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
//the header files of the related classes and data structure
//you can modify based on your filenames
//#include "PageTableEntry.h"  //the struct for a PageTableEntry
//#include "PhysicalMemory.h" //the class PhysicalMemory
//#include "PageTable.h"  //the class PageTable

using namespace std;

vector<string> virtualMemoryList; //layout of the virtual memory
vector<string> runList; //page reference string for the process

//load the virtual memory with each item
void loadVirtualMemory()
{
	virtualMemoryList.push_back("main");
	virtualMemoryList.push_back("load");
	virtualMemoryList.push_back("tax");
	virtualMemoryList.push_back("update");
	virtualMemoryList.push_back("print");
	virtualMemoryList.push_back("holding");
	virtualMemoryList.push_back("activity");
	virtualMemoryList.push_back("net");
}

//load each item to be referenced
void loadRunList()
{
	//load the reference string
	runList.push_back("main");
	runList.push_back("load");
	runList.push_back("holding");
	runList.push_back("main");
	runList.push_back("activity");
	runList.push_back("net");
	runList.push_back("main");
	runList.push_back("update");
	runList.push_back("holding");
	runList.push_back("net");
	runList.push_back("activity");
	runList.push_back("main");
	runList.push_back("tax");
	runList.push_back("net");
	runList.push_back("main");
	runList.push_back("print");
	runList.push_back("net");
}

//The PageTableEntry structure represents each entry in the page table
//within the virtual memory system.
struct PageTableEntry 
{
    //member variables
    bool valid;
    int physicalMemoryIndex;

    //constructor
    PageTableEntry() 
    : valid(false), physicalMemoryIndex(-1) {}
};


class PhysicalMemory 
{
public:

    //constructor
    PhysicalMemory(int memorySize, int algorithmIn)
    : memoryList(memorySize), timeList(memorySize, 0), currentTimeIndex(0), algorithmFlag(algorithmIn) {}

    //This method updates the currentTimeIndex and displays information about the accessed FrameID.
    //It takes in the frameID of the frame accessed
    void access(int frameID) 
    {
        //update the currentTimeIndex if the algorithm is LRU
        //The LRU algorithm updates the timeIndex here because every time a page is accessed 
        //it is updated to be the most recent accessed page. This will allow for the most
        //commonly accessed pages to remain in memory the longest.
        if (algorithmFlag == 0)
        {
            timeList[frameID] = ++currentTimeIndex;
        }
        //Display access information
        cout << "Physical: Accessed frameID: " << frameID << " contains: " << memoryList[frameID] << "\n\n";
    }

    //This method displays info about the physical memory layout
    void printMemory() const 
    {
        cout << "Physical Memory Layout:\n";

        //Display each frame and what it currently contains 
        for (size_t i = 0; i < memoryList.size(); i++) 
        {
            cout << "Frame: " << i << " contains: " << memoryList[i] << endl;
        }
    }

    //This method is used when the requested page is not present in physical memory
    //It will load the missing page into physical memory. It returns the frameID of
    //The new frame
    int swapIn(const string& item) 
    {
        //find the next avaiable frame to be used
        int frameID = getNextAvailableFrame();

        //load the item into the frame
        memoryList[frameID] = item;
        
        //display which item is loaded into the new frame
        cout << "Physical: Swap In: " << item << endl;
    
        //update the currentTimeIndex if the algorithm is FIFO
        //The FIFO algorithm updates the timeIndex here because every time a page is accessed 
        //it is places at the front of the queue. This will allow for the most
        //for pages to leave in the order they were accessed. 
        if (algorithmFlag == 1)
        {
            timeList[frameID] = ++currentTimeIndex;
        }
        //return the frameID
        return frameID;
    }

private:

    //private data members
    vector<string> memoryList;
    vector<int> timeList;
    int currentTimeIndex;
    int algorithmFlag;

    //this method will return the number of the next available frame
    int getNextAvailableFrame() 
    {
        //If there are no available frames get the next available frame based on the selected algorithm
        if (isFull()) 
        {
            return min_element(timeList.begin(), timeList.end()) - timeList.begin();
        } 

        //if there are available frames select the next frame
        else 
        {
            return find(timeList.begin(), timeList.end(), 0) - timeList.begin();
        }
    }

    //check to see if the frames are full
    bool isFull() 
    {
        return all_of(timeList.begin(), timeList.end(), [](int x) { return x != 0; });
    }
};

class PageTable 
{
public:
    //constructor
    PageTable(PhysicalMemory* pmIn, int tableSize)
    : mainPhysicalMemory(pmIn), numFaults(0), entryList(tableSize) {}

    //This method checks if the selected page is available in Physical memory
    void reference(int pageID, const string& item) 
    {
        //If the page is not in physical memory
        if (!entryList[pageID].valid) 
        {
            //display message
            cout << "PageTable: page fault occurred\n";
            
            //count a page fault and load the page into physical memory
            pageFault(pageID, item);

            //access the page in physical memory
            mainPhysicalMemory->access(entryList[pageID].physicalMemoryIndex);           
        }

        //if the page is in physical memory 
        else 
        {
            //access the page
            mainPhysicalMemory->access(entryList[pageID].physicalMemoryIndex);
        }
    }

    //getter for the current number of faults
    int getFaults() const { return numFaults; }

    //This method prints out the PageTable
    void printTable() const 
    {
        //print out header for Page Table
        cout << "\nPage Table snapshot:\n";

        //Print out all info for each page
        for (size_t i = 0; i < entryList.size(); ++i) 
        {
            cout << "Page Index: " << i 
                 << " : Physical Frame Index: " << entryList[i].physicalMemoryIndex 
                 << " : In Use: " << (entryList[i].valid ? "true" : "false") << endl;
        }

        //Display the total number of page faults
        cout << "PageTable: Current number of page faults: " << getFaults() << endl;
    }

private:

    //private data members
    PhysicalMemory* mainPhysicalMemory;
    int numFaults;
    vector<PageTableEntry> entryList;
    

    //this method updates the number of faults, swaps in the selected page into the selected frame
    //and updates the replaced entry
    void pageFault(int pageID, const string& item) 
    {
        //count up the number of faults
        numFaults++;

        //swap in the page into the frame
        int frameID = mainPhysicalMemory->swapIn(item);
        
        //update the replaced entry
        updateReplacedEntry(frameID, pageID);
    }

    //this method updated the replaced entry
    void updateReplacedEntry(int replacedIndex, int pageID) 
    {
        //search for the old entry
        for (auto& entry : entryList) 
        {
            //once found invalidate it and update its index
            if (entry.physicalMemoryIndex == replacedIndex) {
                entry.valid = false;
                entry.physicalMemoryIndex = -1;
            }
        }

        //update the new entry for the new page
        entryList[pageID].valid = true;
        entryList[pageID].physicalMemoryIndex = replacedIndex;
    }
};

//this function accepts a string item name and returns the item's
//matching virtual page index
int itemToPageID(string itemIn)
{
	//for each item in the virtual memory list
	for(size_t i = 0; i < virtualMemoryList.size(); i++)
	{
		//get the current virtual memory list item
		string cItem = virtualMemoryList.at(i);

		//compare the requested run list item with the current virtual memory list item
		int sComp = cItem.compare(itemIn);

		//if the two items match
		if (sComp == 0)
		{
			//return the current virtual memory list index
			return i;
		}
	}

	//if we get here, no match was found
	return -1;
}

int main(int argc, char *argv[])
{
	int physicalMemSize = 4; //you can change as a command line argument
    int algorithm = 1;  //1 for FIFO, 0 or other number for LRU if implemented.
	  
	if (argc == 1) 
	{
		cout << "Default to four frames. You can change via command line argument: ";
		cout << "Usage: ./a.out <number of frames> <1 FIFO, 0 LRU>" << endl;
	}
    if (argc > 1) 
    {
        physicalMemSize = atoi(argv[1]);
    }
    if (argc > 2) 
    {
        algorithm = atoi(argv[2]);  // Set algorithm based on command line input
    }

	cout << "Welcome!" << endl;
	
	loadVirtualMemory();
	loadRunList();

	PhysicalMemory physicalMem(physicalMemSize, algorithm);
	PageTable pTable(&physicalMem, virtualMemoryList.size());

	if (algorithm == 1) //you can add LRU-related printout if implemented
		cout << "FIFO with "<< physicalMemSize <<" physical frames" << endl;
	else if (algorithm == 0) //you can add LRU-related printout if implemented
		cout << "LRU with "<< physicalMemSize <<" physical frames" << endl;

	//for each item in the run list
	for(size_t i = 0; i < runList.size(); i++)
	{
		//fetch the virtual page index for the string item
		int virtualIdx = itemToPageID(runList.at(i));

		//if the virtual page index was found
		if(virtualIdx != -1)
			//reference the item at the specified virtual index
			pTable.reference(virtualIdx, runList.at(i));
		//otherwise the item to virtual index failed
		else
		{
			//print an error message and break
			cout << "Failed to convert reference to virtual memory: " << runList.at(i) << endl;
			break;
		}
	}

	cout << "Now print snapshots:" << endl << endl;

	//print physical memory and page table
	physicalMem.printMemory();
	pTable.printTable();

    return 0;
}