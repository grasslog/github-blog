#include <pthread.h>
#include <iostream>
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
struct Leninfo
{
       Leninfo(int _l,int _h,T& _arr):l(_l),h(_h),arr(_arr){}
        int l;
        int h;
        T& arr;
};
vector<int> read_file(string filename)
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
void* merge_sort(void* info)// merge the arr[l]->arr[h-1]
{

    auto arg = (Leninfo<T>*)(info);
    size_t l = arg->l,h = arg->h;
    T& arr = arg->arr;

    if (h-l < 5) { sort(arr.begin()+l,arr.begin()+h);
    return NULL;}

    pthread_t tid1,tid2;
    auto mid = (l+h)>>1;
    Leninfo<T> info1 = Leninfo<T>(l,mid,arr),info2 = Leninfo<T>(mid,h,arr);

    pthread_create(&tid1,NULL,merge_sort<T>,(void*)(&info1));  //merge_sort(l,mid);
    pthread_create(&tid2,NULL,merge_sort<T>,(void*)(&info2));//merge_sort(mid,h);

    void *status1,*status2;
    pthread_join(tid1,&status1);
    pthread_join(tid2,&status2);
    my_merge(arr,l,mid,h);
}

int main()
{
    void* status;
    pthread_t tids;//define the id of thread
    vector<string> data = {"azcd","afgh","z","hijk","sdf","hlus"};
    auto s = Leninfo<vector<string>>(0,data.size(),data);
    pthread_create(&tids,NULL,merge_sort<decltype(data)>,(void*)&(s));
    pthread_join(tids,&status);
    for(const auto &x : data){cout<<x<<endl;}
    pthread_exit(NULL);
    return 0;
}