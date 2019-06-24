#include "bits/stdc++.h"
using namespace std;
#define NUM_THREADS 5

template<typename T>
struct Leninfo
{
    Leninfo(int _l, int _h, T& _arr):l(_l),h(_h),arr(_arr){}
    int l;
    int h;
    T &arr;
};

vector<int> read_file(string filename)
{
    ifstream file(filename);
    int each_element;
    vector<int> data;
    if(file) {
        while(file >> each_element) {
            data.push_back(each_element);
        }
    }

    return data;
}

template<typename T>
void* my_merge(T& arr, int l, int mid, int r)
{
    size_t i = 0,j = 0, k = l;
    size_t bound1 = mid-l, bound2 = r-mid;
    T first;
    T second;
    for(size_t t = l; t!=mid; t++) {first.push_back(arr[t]); }
    for(size_t t = mid; t!=r; t++) {second.push_back(arr[t]); }
    while(i < bound1 && j < bound2) {
        if(first[i] < second[j]) {
            arr[k++] = first[i++];
        }else {
            arr[k++] = second[j++];
        }
    }
    while(i < bound1) {
        arr[k++] = first[i++];
    }
    while(j < bound2) {
        arr[k++] = second[j++];
    }
}

template<typename T>
void *merge_sort(void *info)
{
    auto args = (struct Leninfo<T>*)(info);
    size_t l, h;
    l = args->l;
    h = args->h;
    T& data = args->arr;

    if(h - l < 5) {
        sort(data.begin()+l, data.begin()+h);
        return nullptr;
    }

    pthread_t tid1, tid2;
    auto mid = (l+h)>>1;
    Leninfo<T> info1 = Leninfo<T>(l,mid,data), info2 = Leninfo<T>(mid,h,data);

    pthread_create(&tid1,nullptr,merge_sort<T>,&info1);
    pthread_create(&tid2,nullptr,merge_sort<T>,&info2);

    void *status1, *status2;
    pthread_join(tid1, &status1);
    pthread_join(tid2, &status2);

    my_merge(data, l, mid, h);
}

void rand_num(vector<int> &nums, size_t n)
{
    if(n < 0) return ;
    for(int i=0; i<n; i++) {
        nums.push_back(rand()%n);
    }
}

int main()
{
    void *status;
    vector<int> data;
    rand_num(data, 50);
    auto info = Leninfo<vector<int>>(0,data.size(),data);
    pthread_t tid;
    pthread_create(&tid,NULL,merge_sort<decltype(data)>,(void *)&info);
    pthread_join(tid, &status);

    for(const auto &x : data) {
        cout << x << " ";
    }
    cout << endl;

    pthread_exit(nullptr);
    return 0;
}