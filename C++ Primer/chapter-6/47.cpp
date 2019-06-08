#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printVec(vector<int> &vec)
{
#ifndef NDEBUG
        cout << "vector size: " << vec.size() << endl;
#endif
        if(!vec.empty())
        {
            int tmp = vec.back();
            vec.pop_back();
            printVec(vec);
            cout << tmp << " ";
        }
}

int main(int argc, char **argv)
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    printVec(vec);
    cout << endl;

    return 0;
}