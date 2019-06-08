#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
using namespace std;

int main(int argc, char **argv)
{
    list<int> list1(7,8);
    vector<int> vec2(6,8);

    vector<double> vec1(list1.begin(), list1.end());
    vector<double> vec3(vec2.begin(), vec2.end());

    if(list1.size() == vec2.size())
    {
        int flag = vec1.size();
        list<int>::iterator it1 = list1.begin();
        vector<int>::iterator it2 = vec2.begin();
        for(it1; it1 != list1.end(); it1++, it2++)
        {   
            if(*it1 == *it2)
                flag--;
        }
        if(flag == 0)
        {
            cout << "That equals." << endl;
        }
        else 
        {
            cout << "That not equals." << endl;
        }
    }
    else
    {
        cout << "That not equals." << endl;
    }

    return 0;
}