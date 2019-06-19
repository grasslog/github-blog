#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <algorithm>
#include <utility>
#include <memory>
using namespace std;

class A
{
public:
    A(int m):val(m)
    {
        cout << "default construct function." << endl;
    }
    A& operator= (const A& a)
    {
        val = a.val;
        cout << "copy operator." << endl;
        return *this;
    }
    ~A()
    {
        cout << "destroy function." << endl;
    }

    int val;
};

void show1(A& a)
{
    cout << a.val << endl;
}
void show2(A a)
{
    cout << a.val << endl;
}

int main(int argc, char **argv)
{
    A a(10);
    A b(5);
    A c(2);
    c = a;
    show1(a);
    show2(b);
    show2(c);

    vector<A> m;
    m.push_back(a);

    A *d = new A(5);
    show2(*d);
    delete d;

    return 0;
}