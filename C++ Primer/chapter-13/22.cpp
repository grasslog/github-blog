#include <iostream>
#include <string>
using namespace std;

class Hasptr
{
public:
    Hasptr();

    Hasptr(const Hasptr& p):ps(new string(*(p.ps))),i(p.i) { }

    Hasptr& operator= (const Hasptr& p)
    {
        auto new_ps = new string(*p.ps);
        delete ps;
        ps = new_ps;
        return *this;
    }

    ~Hasptr() { delete ps; }
private:
    string *ps;
    int i;
};