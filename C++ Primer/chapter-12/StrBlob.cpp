#include "StrBlob.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    ifstream in("read.txt");
    string s;
    StrBlob blob;
    while(getline(in,s))
    {
        blob.pushback(s);
    }
    for(StrBlob pbeg(blob.begin()), pend(blob.end()); pbeg != pend; pbeg.incr())
        cout << pbeg.deref() << endl;

    return 0;
}