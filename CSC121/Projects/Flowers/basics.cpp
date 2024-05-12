#include<iostream>
#include<string>


//This function welcomes the user to the program. 
//It centers the welcome message in the centerof the console. It takes
// in a string that is the name of the program. It returns nothing.
void welcome(std::string welcome)
{
    //centered welcome message
    std::cout << std::string(((80 - 23 - welcome.size()) / 2), ' ')
        << "Welcome to the " << welcome << " program\n"
        << std::string(((80 - 50) / 2), ' ') 
        << "Designed by Mike for the Busy Bee Blossom Boutique\n\n";
    return;
}

//This function prints out a goodbye message to the user. It takes in a string
//that is the name of the program. IT returns nothing.
void goodbye(std::string s)
{
    //goodbye message
    std::cout << "Thank you for using the " << s
        << " Program! Have a good night!\n";
    return;//return
}

