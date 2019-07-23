#include <iostream>
using namespace std;

int main()
{
    int b = 3;
    const int &a = 3;

    cout << b << " " << a << endl;

    return 0;
}