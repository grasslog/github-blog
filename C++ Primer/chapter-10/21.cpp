#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    int i = 5;
    auto f = [&i]()->bool {
        if(i == 0)
        {
            return true;
        }
        else 
        {
            --i;
            return false;
        }
    };
    int j = f();
    cout << j << endl;

    return 0;
}