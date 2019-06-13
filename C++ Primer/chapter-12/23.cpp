#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    char *s1 = "abc";
    char *s2 = "efg";
    string si = "a";
    string sl = "b";
    char *p = new char[strlen(s1)+strlen(s2)+1];
    strcpy(p, s1);
    strcat(p, s2);
    cout << p << endl;
    strcpy(p, (si+sl).c_str());
    cout << p << endl;
    delete [] p;

    return 0;
}