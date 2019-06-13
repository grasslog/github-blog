#include <iostream>
#include <thread>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <typeinfo>
#include <algorithm>
#include "unistd.h"
using namespace std;
#define NUM_THREADS 5

template<typename T>
vector<T> read_file(string filename)
{

    ifstream file(filename);
    int each_element;
    vector<int> data;
    if (file){
        while(file>>each_element) {
            data.push_back(each_element);
        }
    }
    return data;
}

template<typename T>
void my_merge(T& arr,int l,int mid,int r)
{

    size_t i = 0,j = 0,k = l;
    size_t bound1 = mid-l,bound2 = r-mid;
    T first;
    T second;
    for(size_t i = l;i!=mid;++i){first.push_back(arr[i]);}
    for(size_t i = mid;i!=r;++i){second.push_back(arr[i]);}
    while(i<bound1 & j<bound2)
    {
        if (first[i]<second[j]){ arr[k++] = first[i++];}
        else{arr[k++] = second[j++];}
    }

     while (i<bound1){arr[k++] = first[i++]; }
     while (j<bound2){arr[k++] = second[j++];}
}

template<typename T>
void merge_sort(size_t l,size_t h,T& arr)// merge the arr[l]->arr[h-1]
{
    if (h-l < 5) {sort(arr.begin()+l,arr.begin()+h);
    return ;}

    size_t mid = (l+h)>>1;
    thread sub_thread1(merge_sort<T>,l,mid,ref(arr));
    thread sub_thread2(merge_sort<T>,mid,h,ref(arr));
    sub_thread1.join();
    sub_thread2.join();
    my_merge(arr,l,mid,h);
}


int main()
{
    vector<string> data = {"azcd","afgh","z","hijk","sdf","hlus"};
    thread merge_(merge_sort<decltype(data)>,0,data.size(),ref(data));
    merge_.join();
    for(const auto &x : data){cout<<x<<endl;}
    return 0;
}