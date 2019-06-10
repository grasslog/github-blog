#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char **argv)
{
    map<string,size_t> word_count;
    fstream in("read.txt");
    string word;

    while(in >> word)
    {
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