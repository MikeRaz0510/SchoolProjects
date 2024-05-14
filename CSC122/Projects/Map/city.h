#ifndef CITY_H_INC
#define CITY_H_INC

#include<iostream>
#include "point.h"
class City
{
    std::string name;
    Point location;
public:
    //accessors
    inline std::string getName(void)
    {
        return name;
    }

    inline Point getLocation(void)
    {
        return location;
    }

    inline bool setName(std::string newName)
    {
        bool okay = true;
        name = newName;
        return okay;
    }
    inline bool setLocation(double& x, double& y)
    {
        bool okay = true;
        location = Point(x, y);
        return okay;
    }
    inline bool setLocation(Point newCity)
    {
        bool okay = true;
        location = newCity;
        return okay;
    }

    //default constructor 
    City()
        :name(""), location()
    {
    }

    //copy constructor
    City(const City& obj)
        :name(obj.name), location(obj.location)
    {
        name = obj.name;
        location = obj.location;
    }

    //constructors
    City(std::string newName, double newX, double newY)
        : name(newName), location(Point(newX, newY))
    {
        setName(newName);
        setLocation(newX, newY);

    }City(std::string newName, Point newLocation)
        : name(newName), location(newLocation)
    {
        setName(newName);
        setLocation(newLocation);
    }

    //methods
    City input(void);
    void printCity(void);
};

#endif
