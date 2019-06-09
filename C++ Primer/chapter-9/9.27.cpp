#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <forward_list>
using namespace std;

int main(int argc, char **argv)
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};

    forward_list<int> forward_list1(ia, ia+9);

    forward_list<int>::iterator it1 = forward_list1.begin();
    forward_list<int>::iterator it2 = forward_list1.before_begin();

    while(it1 != forward_list1.end())
    {
        if((*it1)%2 == 1)
        {
            it1 = forward_list1.erase_after(it2);
        }
        else
        {
            it2 = it1;
            ++it1;
        }
    }

    forward_list<int>::iterator it4 = forward_list1.begin();
    for(it4; it4 != forward_list1.end(); ++it4)
    {
        cout << *it4 << " ";
    }

    return 0;
}