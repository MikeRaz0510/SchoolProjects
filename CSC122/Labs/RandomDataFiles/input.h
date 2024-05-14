#ifndef INPUT_H_INC
#define INPUT_H_INC

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<limits>
#include"input.h"

template <typename inType>
inline inType input(inType input)
{
    std::cin >> input;
    return input;
}

std::vector<std::string> vecStrIn(void);


#endif

