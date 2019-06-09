#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    vector<int> vec1(1,3);
    int a = vec1.front();
    int b = vec1[0];
    int c = vec1.at(0);
    int d = *vec1.begin();
    cout << a << " " << b << " " << c << " " << d << endl;

    return 0;
}