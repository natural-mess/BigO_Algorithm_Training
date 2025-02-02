#include<bits/stdc++.h>
using namespace std;

typedef struct
{
    int number;
    int index=-1;
} number;

void insertAsc (number arr[], int n, int x)
{
    int i = n;
    while (i>0)
    {
        if (arr[i-1].number <= x)
        {
            break;
        }
        arr[i].number = arr[i-1].number;
        i--;
        
    }
    arr[i].number = x;
}

void insertDes (number arr[], int n, int x)
{
    int i = n;
    while (i>0)
    {
        if (arr[i-1].number >= x)
        {
            break;
        }
        arr[i].number = arr[i-1].number;
        i--;
        
    }
    arr[i].number = x;
}

void insertionSort (number arrEven[], int n, number arrOdd[], int m)
{
    for (int i = 0; i < n; i++)
    {
        int x=arrEven[i].number;
        insertAsc(arrEven, i, x);
    }

    for (int i = 0; i < m; i++)
    {
        int x=arrOdd[i].number;
        insertDes(arrOdd, i, x);
    }
}

bool isEven(int x)
{
    bool ret = false;
    if (x%2==0)
    {
        ret = true;
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    number even[n], odd[n];
    int j=0, k=0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        
        if (isEven(a[i])==true)
        {
            even[j].number = a[i];
            even[j].index = i;
            j++;
        }
        else
        {
            odd[k].number = a[i];
            odd[k].index = i;
            k++;
        }
    }

    insertionSort(even, j, odd, k);

    int p = 0, q = 0;
    for (int i = 0; i < n; ++i)
    {
        if (even[p].index == i)
        {
            cout << even[p].number << " ";
            p++;
        }
        else if (odd[q].index == i)
        {
            cout << odd[q].number << " ";
            q++;
        }
    }
}