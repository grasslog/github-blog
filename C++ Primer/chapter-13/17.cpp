#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class A
{
public:
    A()
    {
        static int vall = 10;
        val = vall++;
    }
    A(A &a)
    {
        val = a.val + 5;
    }

    int val;
};

void show2(A a)
{
    cout << a.val << endl;
}
void show3(const A& a)
{
    cout << a.val << endl;
}
int main(int argc, char **argv)
{
    A a, b = a, c = b;
    show2(a);
    show2(b);
    show2(c);
    cout << "------------------------------" << endl;
    show3(a);
    show3(b);
    show3(c);

    return 0;
}