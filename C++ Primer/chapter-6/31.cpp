#include <iostream>
#include <string>
using namespace std;

char &Get_val(string &a, int ix) 
{
    return a[ix];
}

int main(int argc, char *argv[])
{
    string s = "an apple ";
    cout << "Before...:" << s << endl;
    Get_val(s,0) = 'A';
    cout << "After change...:" << s << endl;

    return 0; 
}