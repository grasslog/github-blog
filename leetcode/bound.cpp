void quickSort(int a[], int l, int r)
{
    if(l >= r) return ;
    int m = patition(a, l, r);
    quickSort(a, l, m-1);
    quickSort(a, m+1, r);
}

int patition(int a[], int l, int r)
{
    int v = a[l];
    while(l < r) {
        while(l<r && a[r]>v) r--;
        a[l] = a[r];
        while(l<r && a[l]<=v) l++;
        a[r] = a[l];
    }

    return l;
}