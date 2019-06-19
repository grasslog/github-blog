#include <iostream>
#include <string>
using namespace std;

class Hasptr
{
    friend void swap(Hasptr&, Hasptr&);
public:
    Hasptr() {}

    Hasptr(const Hasptr& p):ps(new string(*p.ps)),i(p.i) { }

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

inline void swap(Hasptr& a, Hasptr& b)
{
    using std::swap;
    swap(a.ps, b.ps);
    std::swap(a.i, b.i);
    cout << "123" << endl;
}