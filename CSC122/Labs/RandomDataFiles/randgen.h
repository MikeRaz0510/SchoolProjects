#ifndef RANDGEN_H_INC
#define RANDGEN_H_INC

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<limits>
#include<string>
#include<cctype>
#include<vector>
#include "randgen.h"
#include "input.h"

inline long genRandLong(long max, long min)
{
    return rand() / (RAND_MAX / (max - min + 1) + 1) + min;
}

inline double genRandDouble(double max, double min)
{
    return rand() % RAND_MAX / (RAND_MAX - 1.0) * (max - min) + min;
}

inline char genRandChar(char min, char max)
{
    return static_cast<char>(genRandLong(static_cast<long>(min),
        static_cast<long>(max)));
}

void randWhole(long maxL = 100, long minL = 0, short num = 10);

void randDouble(double maxD = 100.0, double minD = 0.0, short num = 10,
    short places = 2);

void randChar(char maxC = 'z', char minC = 'a', short num = 10);

void randNames(short num = 10, short type = 1);

std::string genRandNames(std::vector<std::string> given, 
    std::vector<std::string> family, short nametype);

bool useDefs(short& num, short& type);

short nametypes(void);

template <typename defaults>
inline bool useDefs(defaults& max, defaults& min, short& num)
{
    bool usedef = true;
    char input;
    std::cout << "Use default values? (Y/N) (Values listed below)\nMax: " << max
        << "\nMin: " << min << "\nNumber: " << num << std::endl;
    std::cin >> input;
    input = toupper(input);
    input == 'Y' ? usedef = true : usedef = false;
    return usedef;
}

template <typename defaults>
inline bool useDefs(defaults& max, defaults& min, short& num, short& places)
{
    bool usedef = true;
    char input;
    std::cout << std::fixed;
    std::cout.precision(1);
    std::cout << "Use default values? (Y/N) (Values listed below)\nMax: " << max
        << "\nMin: " << min << "\nNumber: " << num
        << "\nDecimal places:" << places << std::endl;
    std::cin >> input;
    input = toupper(input);
    input == 'Y' ? usedef = true : usedef = false;
    return usedef;
}

#endif
