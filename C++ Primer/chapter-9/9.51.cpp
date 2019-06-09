#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Date
{
public:
    unsigned _year;
    unsigned _month;
    unsigned _day;
    void _show()
    {
        cout << _year << "year" << _month <<"month" << _day << "day" << endl;
    }

    Date(string);
};

Date::Date(string s)
{
    int flag = 0;
    string number = "0123456789/";
    string coma = ",";
    unsigned pos,pos1,pos2,pos3;
    unsigned _pos, pos1;

    if((pos = s.find_first_not_of(number)) == string::npos)
    {
        flag = 1;
    }
    if((pos = s.find_first_not_of(coma)) != string::npos)
    {
        flag = 2;
    }

    switch(flag)
    {
    case 1:
        pos1 = 0;
        pos1 = s.find_first_of("/", pos1);
        _day = sto(s.substr(0,pos1));
        
    }
}