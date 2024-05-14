#ifndef BOX_H_INC
#define BOX_H_INC

#include<iostream>
#include<cctype>
#include<vector>
#include<string>
#include "box.h"


class box
{
    std::string line;
    std::vector<std::string> words;
    char symbol = '*';

public:

    //default constructor
    box(void)
        :line(""), words({}), symbol('*')
    {
    }

    //copy constructor
    box(const box& obj)
        :line(obj.line), words(obj.words), symbol(obj.symbol)
    {
        line = obj.line;
        words = obj.words;
        symbol = obj.symbol;
    }

    //constructor
    box(std::string line)
        :line(line), words(seperateLine(line)), symbol('*')
    {
        set_line(line);
        set_Words(line);
        symbol = '*';
    }
    box(std::string line, char symbol)
        :line(line), words(seperateLine(line)), symbol(symbol)
    {
        set_line(line);
        set_Words(line);
        set_Symbol(symbol);
    }

    //accessors
    inline std::string get_line(void)
    {
        return line;
    }
    inline std::vector<std::string> getWords(void)
    {
        return words;
    }

    inline char get_symbol(void)
    {
        return symbol;
    }

    //mutators
    void set_line(std::string newLine)
    {
        line = newLine;
        return;
    }

    void set_Words(std::string line)
    {
        std::vector<std::string> newWords;
        std::string newline;
        for (std::string::size_type i = 0; i < line.size(); i++)
        {
            newline += line[i];
            if (isspace(line[i + 1]))
            {
                newWords.push_back(newline);
                newline = "";
                i++;
            }
        }
        newWords.push_back(newline);
        newline = "";

        words = newWords;
        return;

    }

    inline void set_Symbol(const char & newSymbol)
    {
        symbol = newSymbol;
        return;
    }

    //methods
    void printBox(std::vector<std::string> vec);
    short lWord(const std::vector<std::string>& vec);
    void boxifyC(void);
    void boxifyL(void);
    void boxifyR(void);
    std::vector<std::string> seperateLine(std::string line);
   
    

};

#endif // !BOX_H_INC
