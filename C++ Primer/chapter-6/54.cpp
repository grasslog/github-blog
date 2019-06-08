#include <iostream>
#include <string>
#include <vector>

using namespace std;

int add(int a, int b)
{
    return (a + b);
}
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a/b : 0; }

int main(int argc, char **argv)
{
    typedef int(*p)(int a, int b);
    vector<p> vec{add, subtract, multiply, divide};
    for(auto f : vec) {
        cout << f(3, 3) << endl;
    }

    return 0;
}