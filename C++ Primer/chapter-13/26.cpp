#include <iostream>
#include <string>
using namespace std;

class Hasptr1
{
public:
    Hasptr1(const string& s = string()):ps(new string(s)),i(0),use(new size_t(1)) { }

    Hasptr1(const Hasptr1& p):ps(p.ps),i(p.i),use(p.use) { ++*use; }

    Hasptr1& operator= (const Hasptr1& p1)
    {
        ++*p1.use;
        if(--*use == 0)
        {
            delete ps;
            delete use;
        }
        ps = p1.ps;
        use = p1.use;
        i = p1.i;

        return *this;
    }
private:
    string *ps;
    size_t *use;
    int i;
};