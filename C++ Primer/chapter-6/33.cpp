#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Get_val(vector<int> &a, int ix)
{
    if(ix >= 0) 
    {
        cout << a[ix] << endl;
        ix--;
        Get_val(a, ix);
    }
}

int main(int argc, char *argv[]) 
{
    int a[10] = {2,2,3,5,6,4,7,8,5,55};
    vector<int> sample(a, a+10);
    Get_val(sample, sample.size()-1);

    return 0;
}