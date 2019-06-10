#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <algorithm>
using namespace std;

int main(int argc, char **argv)
{
    string a[5] = {"aa", "11", "00", "88", "shit"};
    
    vector<string> word(a, a+5);
    string wordl;
    while(cin >> wordl)
    {
        if(find(word.begin(), word.end(), wordl) != word.end())
        {
            cout << "You can't input the repeat elements.";
        }
        else
        {
            word.push_back(wordl);
        }
    }

    return 0;
}