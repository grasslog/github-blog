#include <iostream>
#include <string>
using namespace std;

int main()
{
    string mystring;
    while (getline(cin, mystring)) 
    {
        cout << mystring << endl;
    }

    while (cin>>mystring)
    {
        cout << mystring << endl;
    }
    
    return 0;
}