#ifndef RANDGEN_H_INC
#define RANDGEN_H_INC

#include<cstdlib>

inline long genRandLong(long max, long min)
{
    return rand() / (RAND_MAX / (max - min + 1) + 1) + min;
}
inline char genRandChar(char min, char max)
{
    return static_cast<char>(genRandLong(static_cast<long>(min),
        static_cast<long>(max)));
}

#endif
