#include <bits/stdc++.h>
using namespace std;

void insertionSortAsc(int a[], int n, int x)
{
    int i = n;
    while (i>0)
    {
        if (a[i-1]<=x)
        {
            break;
        }
        a[i] = a[i-1];
        i--;
    }
    a[i] = x;
}

void insertionSort (int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        insertionSortAsc(a, i, x);
    }
    
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    double median;
    insertionSort(a, n);
    // for (int i = 0; i < n; ++i)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    if (n%2!=0)
    {
        median = a[n/2];
    }
    else
    {
        median = (a[n/2-1]+a[n/2])/2.0;
    }
    cout << median;
}
