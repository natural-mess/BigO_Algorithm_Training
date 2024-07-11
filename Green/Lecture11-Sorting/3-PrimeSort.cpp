#include<bits/stdc++.h>
using namespace std;

void insertAsc (int arr[], int n, int x)
{
    int i = n;
    while (i>0)
    {
        if (arr[i-1] <= x)
        {
            break;
        }
        arr[i] = arr[i-1];
        i--;
        
    }
    arr[i] = x;
}

void insertionSort (int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int x=arr[i];
        insertAsc(arr, i, x);
    }
    
}

bool isPrime(int x)
{
    bool ret;
    int count = 0;
    if (x<=1)
    {
        ret = false;
    }
    else
    {
        for (int i=2; i<x; i++)
        {
            if (x%i==0)
            {
                count++;
            }
        }
        (count==0)? (ret = true) : (ret = false);
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    int b[n];
    int j=0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        
        if (isPrime(a[i])==false)
        {
            b[j] = a[i];
            j++;
        }
    }

    insertionSort(b,j);
    int k=0;
    for (int i = 0; i < n; ++i)
    {
        if (isPrime(a[i])==false)
        {
            cout << b[k] << " ";
            k++;
        }
        else
        {
            cout << a[i] << " ";
        }
    }
}