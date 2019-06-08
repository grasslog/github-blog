#include <iostream>
#include <string>
#include <vector>
using namespace std;

// default parameter

string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
    return (ctr > 1) ? word+ending : word;
}

int main(int argc, char *argv[])
{
    cout << "two words plural: " << make_plural(1, "success", "es") << "  " << make_plural(1, "failuer") << endl;
    cout << "two words plural: " << make_plural(2, "success", "es") << "  " << make_plural(2, "failure") << endl;

    return 0;
}