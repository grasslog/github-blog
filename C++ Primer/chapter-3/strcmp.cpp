#include <iostream>
#include <string>
using namespace std;

int main()
{
    string mystring1, mystring2;
    cin >> mystring1 >> mystring2;
    if(mystring1 != mystring2)
    {
        cout << ((mystring1 >= mystring2) ? mystring1 : mystring2) << endl;
    }
}