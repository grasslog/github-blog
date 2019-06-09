#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void func(string &s, string &oldval, string &newval)
{
    int _size = oldval.size();
    string::iterator it1 = s.begin();
    string::iterator it2 = newval.begin();
    string::iterator it3 = newval.end();

    for(it1; it1 <= (s.end()-oldval.size()+1); ++it1)
    {
        if((s.substr(it1-s.begin(), _size) == oldval))
        {
            it1 = s.erase(it1, it1+_size);
        }
    }
}