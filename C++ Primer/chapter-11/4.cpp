#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>
using namespace std;

int main(int argc, char **argv)
{
    map<string,size_t> word_count;
    fstream in("read.txt");
    string word;

    while(in >> word)
    {
        string::iterator it1;
        for(it1 = word.begin(); it1 != word.end(); ++it1)
        {
            *it1 = tolower(*it1);
        }
        word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
        ++word_count[word];
    }

    map<string, size_t>::iterator mapi;
    for(mapi = word_count.begin(); mapi != word_count.end(); ++mapi)
    {
        cout << mapi->first << " ";
        cout << mapi->second << " " << endl;
    }

    return 0;
}