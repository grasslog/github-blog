#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void func(int val)
{
    vector<string> svec;
    svec.reserve(1000);
    string mystring = "string";
    for(int i=0; i<val; i++)
    {
        svec.push_back(mystring);
    }
    svec.resize(svec.size() + svec.size()/2);
    cout << "Input " << val << " and size " << svec.size() << endl;
    cout << "Input " << val << " and capacity " << svec.capacity() << endl;
}

int main(int argc, char **argv)
{
    func(256);
    func(512);
    func(1000);
    func(1024);

    return 0;
}