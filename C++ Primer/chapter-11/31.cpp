#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    string author = "timor";
    multimap<string, string> Library;
    Library.insert(make_pair(author, "hat"));
    Library.insert(make_pair(author, "shoe"));
    Library.insert(make_pair(author, "zhang"));
    Library.insert(make_pair(author, "snow"));

    auto it1 = Library.find(author);
    auto it2 = Library.count(author);

    while(it2)
    {
        if(it1->second == "cat")
    }
}