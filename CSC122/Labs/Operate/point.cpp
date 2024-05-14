#include "point.h"

#include <iostream>
#include <cmath>

// read standard 2D point notation (x,y) -- ignore
// window dressing
void Point::Input(void)
{
    char dummy;
    std::cin >> dummy >> x >> dummy >> y >> dummy;
    return;
}



// output standard 2D point notation (x,y)
void Point::Output(void)
{
    std::cout << '(' << x << ", " << y << ')';
    return;
}

// calculate distance between two 2D points --
// the one that called us and the argument
double Point::distance(Point other)
{
    return sqrt(pow(other.x - x, 2.0) +
        pow(other.y - y, 2.0));
}

//calculate the midpoint of the 2 points
Point Point::midpoint(Point other)
{
    Point mid;
    mid.x = (x + other.x) / 2;
    mid.y = (y + other.y) / 2;
    return mid;
}

double Point::operator-(Point other)//- operator overload
{
    return distance(other);//return distance function
}

Point Point::operator/(Point other)// / operator overload
{
    return midpoint(other);// return midpoint funtion
}

// set coordinates to programmer-specified values
void Point::set_x(double new_x)
{
    x = new_x;        // no error checking since anything is legal
    return;
}

// set coordinates to programmer-specified values
void Point::set_y(double new_y)
{
    y = new_y;        // no error checking since anything is legal
    return;
}

// construct Point by default -- no values specified
Point::Point(void)
    : x(0.0), y(0.0)
{
    x = y = 0.0;
}

// construct Point given initial x,y values
Point::Point(double new_x, double new_y)
    : x(new_x), y(new_y)
{
    set_x(new_x);
    set_y(new_y);
}

// copy constructor
Point::Point(const Point & point)
    :x(point.x), y(point.y)
{
    set_x(point.x);
    set_y(point.y);
}

// creates a point flipped about the x axis from us
Point Point::flip_x(void)
{
    return Point(x, -y);
}

// creates a point flipped about the y axis from us
Point Point::flip_y(void)
{
    return Point(-x, y);
}

// creates a point shifted along the x axis from us
Point Point::shift_x(double move_by)
{
    return Point(x + move_by, y);
}

// creates a point shifted along the y axis from us
Point Point::shift_y(double move_by)
{
    return Point(x, y + move_by);
}

//checks if points are equal
bool Point::isEqual(Point other)
{
    bool equal;
    if (x == other.x && y == other.y)
    {
        equal = true;
    }
    else
    {
        equal = false;
    }
    return equal;
}

//checks if points are not equal
bool Point::isNotEqual(Point other)
{
    bool notEqual;
    if (x != other.x || y != other.y)
    {
        notEqual = true;
    }
    else
    {
        notEqual = false;
    }
    return notEqual;
}


bool Point::operator==(Point other)// overload equality operator
{
    return isEqual(other); //return isEqual funtion
}

bool Point::operator!=(Point other)// overload inequality operator
{
    return isNotEqual(other);// return isNotEqual function
}

double Point::operator[](char cord) //[] operator overload
{
   
    cord = tolower(cord); //lowercase the cordinate
    if (cord == 'x')
    {
        return x; //return x for x
    }
    else if (cord == 'y')
    {
        return  y; //return y for y
    }
    else
    {
        std::cerr << "Not a valid cordinate!\n";
    }
   
}
