#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void elimDups(vector<string> &s)
{
    cout << "before sort: " ;
    for(int i = 0; i<s.size(); i++)
    {
        cout << s[i] << " ";
    }
    cout<< endl << "after sort: ";
    sort(s.begin(), s.end());
    for(int i = 0; i<s.size(); i++)
    {
        cout << s[i] << " ";
    }
    cout << endl << "after unique sort: ";
    vector<string>::iterator str = unique(s.begin(), s.end());
    cout << s.size() << endl;
    for(int i = 0; i<s.size(); i++)
    {
        cout << s[i] << " ";
    }
    cout << endl << "after erase: ";
    s.erase(str,s.end());
    cout << s.size() << endl;
    for(int i = 0; i<s.size(); i++)
    {
        cout << s[i] << " ";
    }
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main(int argc, char**argv)
{
	string a[10] = {"because","I","Like","Like","C++","very","very","much","that's","why"};
	vector<string> s(a,a+10);
	elimDups(s);
	stable_sort(s.begin(),s.end(),isShorter);//将自定义的函数传递进来,先长度、后字典序
	cout<<endl<<"stable_sort排序后：";
	for (int i = 0; i<s.size(); ++i)
	{
		cout<<s[i]<<" ";
	}
 
	return 0;

}