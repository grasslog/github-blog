#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    vector<char> vec1(6, 'a');
    string _string(vec1.begin(), vec1.end());
    cout << _string << endl;

    return 0;
}