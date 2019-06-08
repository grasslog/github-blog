#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool find1(vector<int>::iterator a, vector<int>::iterator b, int c)
{
    for(a; a != b; a++) 
    {
        if(*a == c) 
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char **argv)
{
    vector<int> vec(20);
    vec[0] = 4;
    vec[1] = 5;
	vec[2] = 2;
	vec[3] = 8;
	vec[4] = 9;
	vec[5] = 6;
	vec[6] = 7;
    int find_member = 1;
    if(find1(vec.begin(), vec.end(), find_member))
    {
        cout << " We have found it. " << endl;
    }
    else 
        cout << "Sorry, there is none. " << find_member << " in the range. " << endl;

    return 0;
}