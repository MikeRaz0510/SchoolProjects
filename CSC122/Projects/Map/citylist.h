#ifndef CITYLIST_H_INC
#define CITYLIST_H_INC

#include<vector>
#include<iostream>
#include<string>
#include "city.h"
#include "point.h"

class CityList
{
    std::vector<City> list;
public:

    //accessor
    inline std::vector<City> getList(void)
    {
        return list;
    }
    //mutator
    inline bool setList(const std::vector<City>& newList)
    {
        bool okay = true;
        list = newList;
        return okay;
    }

    //default constructor
    CityList()
        :list({})
    {
    }

    //copy constructor
    CityList(const CityList& obj)
        :list(obj.list)
    {
        list = obj.list;
    }

    //constructors
    CityList(std::vector<City> newList)
        :list(newList)
    {
        setList(newList);
    }

    //methods
    void buildList(short num);
    void printList(void);

};

#endif
