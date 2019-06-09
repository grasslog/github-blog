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
    list<int> list1(5,7);
    deque<int> deque1;
    deque<int> deque2;
    list<int>::iterator it1 = list1.begin();
    for(it1; it1 != list1.end(); it1++)
    {
        if((*it1)%2 == 0)
        {
            deque1.push_back(*it1);
        }
        else
        {
            deque2.push_back(*it1);
        }
    }

    deque<int>::iterator it2 = deque1.begin();
    deque<int>::iterator it3 = deque2.begin();
    cout << "Oushu is: ";
    for(it2; it2 != deque1.end(); it2++)
    {
        cout << *it2 << " ";
    }
    cout << endl;
    cout << "jishu is: ";
    for(it3; it3 != deque2.end(); it3++)
    {
        cout << *it3 << " ";
    }

    return 0;
}