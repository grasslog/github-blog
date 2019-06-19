#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Hasptr1
{
    friend void swap(Hasptr1&, Hasptr1&);
    friend bool operator<(const Hasptr1& s1, const Hasptr1& s2);
    friend void show(vector<Hasptr1>& vec);
public:
    Hasptr1(const string& s = string()):ps(new string(s)), i(0), use(new size_t(1)) { }
    Hasptr1(const Hasptr1& p):ps(p.ps), i(p.i), use(p.use) { ++*use; }
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

    ~Hasptr1()
    {
        if(*use == 0)
        {
            delete ps;
            delete use;
        }
    }
private:
    string *ps;
    size_t *use;
    int i;
};

inline void swap(Hasptr1& a, Hasptr1& b)
{
    using std::swap;
    swap(a.ps, b.ps);
    std::swap(a.i, b.i);
    cout << "123" << endl;
}

bool operator< (const Hasptr1& s1, const Hasptr1& s2)
{
    cout << "Defined Operator< " << endl;
    return *s1.ps < *s2.ps;
}

void show(vector<Hasptr1>& vec)
{
    vector<Hasptr1>::iterator it1 = vec.begin();
    for(it1; it1 != vec.end(); ++it1)
    {
        cout << *(it1->ps) << endl;
    }
}

int main(int argc, char **argv)
{
    vector<Hasptr1> vec1;
    Hasptr1 a("l");
    Hasptr1 b("llll");
    Hasptr1 c("lll");
    vec1.push_back(a);
    vec1.push_back(b);
    vec1.push_back(c);
    vector<Hasptr1>::iterator it1 = vec1.begin();
    sort(vec1.begin(), vec1.end());
    show(vec1);
    return 0;
}