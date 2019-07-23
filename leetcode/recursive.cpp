#include <bits/stdc++.h>

using namespace std;

vector<int> recursive(vector<int> nums)
{
    int _max, _min;
    
    if(nums.size()<=2)
    {
        if(nums.size()<1) return {INT_MAX, INT_MIN};
        _min = nums[0];
        _max = nums[0];
        if(nums.size()>1&&nums[1]<_min)
        {
            _min = nums[1];
        }
        if(nums.size()>1&&nums[1]>_max) 
        {
            _max = nums[1];
        }
        return {_min, _max};
    }

    vector<int> left, right;
    int len = nums.size();
    int mid = len/2;
    for(int i=0; i<mid; i++) {
        left.push_back(nums[i]);
    }
    for(int i=mid; i<len; i++) {
        right.push_back(nums[i]);
    }

    vector<int> ansl, ansr;
    ansl = recursive(left);
    ansr = recursive(right);

    _min = min(ansl[0],ansr[0]);
    _max = max(ansl[1],ansr[1]);

    vector<int> res;
    res.push_back(_min);
    res.push_back(_max);

    return res;
}

int main(int argc, char **argv)
{

    return 0;
}