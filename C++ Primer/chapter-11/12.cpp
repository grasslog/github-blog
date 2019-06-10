#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    vector<pair<string,int>> vecl(12);
    ifstream inl("read.txt");
    string str;
    size_t i = 0;
    while(inl >> str)
    {
        vecl[i].first = str;
        ++i;
    }
    ifstream in2("write.txt");
    int val;
    size_t j = 0;
    while(in2 >> val)
    {
        vecl[j].second = val;
        ++j;
    }

    vector<pair<string,int>>::iterator it1 = vecl.begin();
    cout << "The vector elements are: " << endl;
    for(it1; it1 != vecl.end(); ++it1)
    {
        cout << it1->first << " " << it1->second << endl;
    }

    return 0;
}