#include <bits/stdc++.h>
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

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
}