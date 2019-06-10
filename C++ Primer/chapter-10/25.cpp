#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;
using namespace placeholders;

void elimDups(vector<string> &s)
{
    sort(s.begin(), s.end());
    vector<string>::iterator str = unique(s.begin(), s.end());
    s.erase(str,s.end());
}
bool check_size(const string &s, string::size_type sz)
{
    return s.size() <= sz;
}
void biggis(vector<string> &s, vector<string>::size_type sz)
{
    elimDups(s);
    stable_sort(s.begin(), s.end(),[](const string &a, const string &b){ return a.size() < b.size(); });
    auto it1 = partition(s.begin(), s.end(), bind(check_sizem _1, sz));
}