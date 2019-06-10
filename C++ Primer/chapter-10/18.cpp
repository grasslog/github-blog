#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void elimDups(vector<string> &s)
{
    sort(s.begin(), s.end());
    vector<string>::iterator str = unique(s.begin(), s.end());
    s.erase(str, s.end());
}
void biggis(vector<string> &s, vector<string>::size_type sz)
{
    elimDups(s);
    stable_sort(s.begin(), s.end(), [](const string &a, const string &b){return a.size() < b.size(); });
    auto it1 = partition(s.begin(), s.end(), [sz](const string &s){return s.size() <= sz; });
    for(it1; it1 != s.end(); ++it1)
    {
        cout << *it1 << " ";
    }
}

int main(int argc, char **argv)
{
    string a[10] = {"diuwudh","udh","diudh","wudh","diuwu","h","diuw","diuwudhg257","h","d"};
    vector<string> vec1(a, a+10);
    biggis(vec1, 4);

    return 0; 
}