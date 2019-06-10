#include <bits/stdc++.h>
#include <functional>
using namespace std;
using std::placeholders::_1;

bool check_size(const int &s, string::size_type sz)
{
    return sz > s;
}

int main(int argc, char **argv)
{
    string _string = "MyLove";
    int a[10] = {5, 5, 6, 8, 5, 4, 9, 5, 2, 4};
    vector<int> vec1(a, a+10);

    string::size_type _length = _string.size();

    cout << "The string size more than 6 are: " << count_if(vec1.begin(), vec1.end(), bind(check_size, _l, _length)) << "bit" << endl;

    return 0;
}