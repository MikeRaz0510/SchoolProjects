#ifndef MOREVEC_H_INC
#define MOREVEC_H_INC

#include<vector>
#include<string>

std::vector<std::string> vecStrIn(void);
std::vector<std::string> selectWords(std::vector<std::string> wordBank);
void vecPrint(std::vector<std::string> vec);
std::string longestWordInVec(std::vector<std::string> vec);
void lowercase(std::vector<std::string>& vec);
void uppercase(std::vector<std::string>& vec);
void printGrid(std::vector<std::vector<char>> grid, short size);


#endif
