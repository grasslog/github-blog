#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;

int main(int argc, char **argv)
{
    vector<int> vec1;
    int a;
    while(cin >> a)
    {
        vec1.push_back(a);
        cout << "the vector's size is: " << vec1.size() << endl;
        cout << "the captity is: " << vec1.capacity() << endl;
    }

    return 0;
}