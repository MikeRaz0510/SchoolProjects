#ifndef month_h_inc
#define month_h_inc

#include <string>

class Month
{
    short month;
    std::string monthName, monthAbv;
public:

    Month();
    short input(void);
    void output(void);
    short getMonth(void);
    void getMonth(std::string& s);
    void setMonth(short x);
    void setMonth(std::string s);
    short advance(void);
    bool before(Month month);
    bool after(Month month);
    bool same(Month month);

};

#endif 

