#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool compareIsbn(string &s1)
{
    if(s1.size() > 5)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int main(int argc, char **argv)
{
    string a[10] = {"diuwudh","udh","diudh","wudh","diuwu","h","diuw","diuwudhg257","h","d"};
    vector<string> vec1(a, a+10);
    vector<string>::iterator it1 = vec1.begin();
    vector<string>::iterator it2;
    it2 = partition(vec1.begin(), vec1.end(),[](const string &a){ return a.size() > 5; });
    cout << "After sort the vector more than 5 are : ";
    for(it1; it1 != it2; ++it1)
    {
        cout << *it1 << " ";
    }

    return 0;
}