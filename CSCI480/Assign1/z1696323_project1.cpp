/********************************************************************
CSCI 480 - Assignment 1 - Semester Spring 2024
Programmer: Mike Rasmussen
Section: 480-1
TA: Yuva Krishna Thanneru
Date Due: 1/30/2024
Purpose: This program answers questions about turing. It opens various files,
          extracts data from them, and formats the output.
*********************************************************************/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(void)
{
    //declare variables
    short count = 0;
    int days, hours, minutes, seconds;
    string line, subLine;
    ifstream file;
    size_t found;
    long time;
    double bytes;
    char physID = 'x';

    //A1
    //open the file
    file.open("/proc/sys/kernel/ostype");

    //check for a sucessful open
    if(!file.is_open())
    {
        cerr << "Error opening the file!\n";
    }

    //extract data from the file
    while (getline(file, line))
    {
        //print output
        cout << "\nA: Questions about turing's OS:\n1. The type of turing's OS is "
             << line << ".\n";
    }

    //close the file
    file.close();

    //A2
    //open the file
    file.open("/proc/sys/kernel/hostname");

    //check for a sucessful open
    if(!file.is_open())
    {
        cerr << "Error opening the file!\n";
    }

    //extract data from the file
    while (getline(file, line))
    {
        //print output
        cout << "2. The hostname is "
             << line << ".\n";
    }

    //close the file
    file.close();

    //A3
    //open the file
    file.open("/proc/sys/kernel/osrelease");

    //check for a sucessful open
    if(!file.is_open())
    {
        cerr << "Error opening the file!\n";
    }

    //extract data from the file
    while (getline(file, line))
    {
        //print output
        cout << "3. The osrelease is "
             << line << ".\n";
    }

    //close the file
    file.close();

    //A4
    //open the file
    file.open("/proc/sys/kernel/version");

    //check for a sucessful open
    if(!file.is_open())
    {
        cerr << "Error opening the file!\n";
    }

    //extract data from the file
    while (getline(file, line))
    {
        //print output
        cout << "4. The version is "
             << line << ".\n";
    }

    //close the file
    file.close();

    //B1
    //open the file
    file.open("/proc/cpuinfo");

    //check for a sucessful open
    if(!file.is_open())
    {
        cerr << "Error opening the file!\n";
    }

    while (getline(file, line))
    {
        //search the file
        found = line.find("processor");
        
        //if the substring is found count up 
        if (found != string::npos)
        {
            count++;
            //find the position of processor on the line
            found = line.find(":");
            
            //reset the line to keep searching
            line = line.substr(found + 1, string::npos);
        }
            
    }

    //print output
    cout << "\nB: Questions about turing's processors:\n1. Turing has "
             << count << " processors.\n";



    //close the file
    file.close();

    //B2
    //open the file
    file.open("/proc/cpuinfo");

    //check for a sucessful open
    if(!file.is_open())
    {
        cerr << "Error opening the file!\n";
    }

    //reset the count
    count = 0;

    while (getline(file, line))
    {
        //search the file
        found = line.find("physical id");
        
        //if the substring is found count up 
        if (found != string::npos)
        {
    
            //find the position of processor on the line
            found = line.find(":");
            
            //reset the line to keep searching
            line = line.substr(found + 2, 1);

            //check if the physical id is unique
            if (line[0] != physID)
            {
                //count each unique physical id
                count++;
                //save the new physical id 
                physID = line[0];
            }
        }
            
    }

    //print the output
    if (count == 1)
    {
        cout << "4. Turing has "
             << count << " physical multi-core chip.\n";
    }
    else
    {
        cout << "4. Turing has "
             << count << " physical multi-core chips.\n";
    }

    //close the file
    file.close();

    //B3
    //open the file
    file.open("/proc/uptime");

    //check for a sucessful open
    if(!file.is_open())
    {
        cerr << "Error opening the file!\n";
    }

    //extract data from the file
    while (getline(file, line))
    {
        //find the space on the line separating the 2 values
        found = line.find(" ");

        //extract the first number
        subLine = line.substr(0, found);
        
        //print output
        cout << "3. Turing has been up for "
             << subLine << " seconds.\n";
    }

    //B4
    //convert the string to an int
    time = stol(subLine);

    //calculate days hours minutes and seconds
    days = time / (24 * 3600);
    hours = (time % (24 * 3600)) / 3600;
    minutes = (time % 3600) / 60;
    seconds = time % 60;

    //print output
    cout << "4. Turing has been up for "
         << days << " days, "
         << hours << " hours, "
         << minutes << " minutes, and "
         << seconds << " secondse.\n";

    //close the file
    file.close();

     //C1
    //open the file
    file.open("/proc/cpuinfo");

    //check for a sucessful open
    if(!file.is_open())
    {
        cerr << "Error opening the file!\n";
    }

    //extract data from the file
    while (getline(file, line))
    {
        //search the file
        found = line.find("vendor_id");
        
        //if the substring is found extract the data and print it
        if (found != string::npos)
        {
            //find the position of the ":" on the line
            found = line.find(":");
            
            //extract the data from after the ":"
            subLine = line.substr(found+2, string::npos);
            
            //print output
            cout << "\nC: Questions about processor 0:\n1. The vendor is "
                 << subLine << ".\n";
            
            //end the loop
            break;
        }
    }

    //C2
    //extract data from the file
    while (getline(file, line))
    {
        //search the file
        found = line.find("model name");
        
        //if the substring is found extract the data and print it
        if (found != string::npos)
        {
            //find the position of the ":" on the line
            found = line.find(":");
            
            //extract the data from after the ":"
            subLine = line.substr(found+2, string::npos);
            
            //print output
            cout << "2. The model name is "
                 << subLine << ".\n";
            
            //end the loop
            break;
        }
    }

    //C3 and C4
    //extract data from the file
    while (getline(file, line))
    {
        //search the file
        found = line.find("address sizes");
        
        //if the substring is found extract the data and print it
        if (found != string::npos)
        {
            //find the position of the ":" on the line
            found = line.find(":");
            
            //extract the data from after the ":"
            subLine = line.substr(found+2, 7);
            
            //print output
            cout << "3. The physical address size is "
                 << subLine << ".\n";

            //find the position of the "," on the line
            found = line.find(",");
            
            //extract the data from after the ","
            subLine = line.substr(found+2, 7);
            
            //print output
            cout << "4. The virtual address size is "
                 << subLine << ".\n";
            
            //end the loop
            break;
        }
    }

    //close the file
    file.close();

    //D1, D2, D3, and D4
    //open the file
    file.open("/proc/stat");

    //check for a sucessful open
    if(!file.is_open())
    {
        cerr << "Error opening the file!\n";
    }

    //extract data from the file
    while (getline(file, line))
    {
        //search the file
        found = line.find("cpu5");
        
        //if the substring is found extract the data and print it
        if (found != string::npos)
        {
            //D1
            //find the position of the " " on the line
            found = line.find(" ");
            
            //extract the data from after the " "
            subLine = line.substr(found+1, 6);

            //convert to seconds
            seconds = stol(subLine) / 100;

            //get rid of the data we have already used
            line = line.substr(found+1, string::npos);
            
            //print output
            cout << "\nD: Questions about processor 5:\n1. Processor 5 has spent "
                 << seconds << " seconds in user mode.\n";

            //skip the data in the next column 
            found = line.find(" ");
            line = line.substr(found+1, string::npos);

            //D2
            //find the position of the next " " on the line
            found = line.find(" ");

            //extract the data from after the " "
            subLine = line.substr(found+1, 6);

            //convert to seconds
            seconds = stol(subLine) / 100;

            // get rid of the data we have already used
            line = line.substr(found+1, string::npos);

            //print output
            cout << "2. Processor 5 has spent "
                 << seconds << " seconds in system mode.\n";

            //D3
            //find the position of the next " " on the line
            found = line.find(" ");
            
            //extract the data from after the " "
            subLine = line.substr(found+1, 9);

            //convert to seconds
            seconds = stol(subLine) / 100;

            //print output
            cout << "3. Processor 5 has spent "
                 << seconds << " seconds in idle mode.\n";

            //D4
            //convert the string of the total seconds into a long int
            time = stol(subLine) / 100;

            //calculate days hours minutes and seconds
            days = time / (24 * 3600);
            hours = (time % (24 * 3600)) / 3600;
            minutes = (time % 3600) / 60;
            seconds = time % 60;

            //print output
            cout << "4. Processor 5 has spent "
                 << days << " days, "
                 << hours << " hours, "
                 << minutes << " minutes, and "
                 << seconds << " seconds in idle mode.\n";
            
            //end the loop
            break;
        }
    }

    //close the file
    file.close();

    //E   
    //open the file
    file.open("/proc/swaps");

    //check for a sucessful open
    if(!file.is_open())
    {
        cerr << "Error opening the file!\n";
    }

    //extract data from the file
    while (getline(file, line))
    {
        //search the file
        found = line.find("partition");
        
        //if the substring is found extract the data and print it
        if (found != string::npos)
        {

            // get rid of the data in front of what we want
            line = line.substr(found, string::npos);

            //find the first number on the line
            found = line.find_first_of("1234567890");
            
            //extract the data
            subLine = line.substr(found, 8);

            bytes = stol(subLine);
            bytes /= 1024;
            
            //print output
            cout << "\nE: Turing's swap device has "
                 << bytes << " MB.\n\n";
            
            //end the loop
            break;
        }
    }

    //close the file
    file.close();


    return 0;
}
