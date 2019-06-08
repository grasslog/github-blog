#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
using namespace std;

int main(int argc, char **argv)
{
    deque<string> deque1;
    string buf;
    while(cin >> buf)
    {
        deque1.push_back(buf);
    }
    deque<string>::iterator it1 = deque1.begin();
    for(it1; it1 != deque1.end(); it1++)
    {
        cout << *it1 << endl;
    }

    return 0;
}