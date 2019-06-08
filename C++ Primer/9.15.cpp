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
    vector<int> vec2(7,8);

    vector<double> vec1(list1.begin(), list1.end());
    vector<double> vec3(vec2.begin(), vec2.end());

    if(vec1.size() == vec3.size())
    {
        int flag = vec1.size();
        vector<double>::iterator it1 = vec1.begin();
        vector<double>::iterator it2 = vec3.begin();
        for(it1; it1 != vec1.end(); it1++,it2++)
        {
            if(*it1 == *it2)
                flag--;
        }
        if(flag == 0)
        {
            cout << "equal." << endl;
        }
        else 
        {
            cout << "not equal." << endl;
        }
    }
    else 
    {
           cout << "not equal." << endl;        
    }
    return 0;
}