#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    vector<int> vec1;

    istream_iterator<int> str(cin), end;
    unique_copy(str, end, back_inserter(vec1));

    sort(vec1.begin(), vec1.end());

    for(int i = 0; i < vec1.size(); ++i)
    {
        cout << vec1[i] << endl;
    }

    return 0;
}