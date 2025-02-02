#include <bits/stdc++.h>
using namespace std;

struct edge {
    int edgex, edgey, edgez;
};

edge a[1000001];

void insertAsc (edge arr[], int n, edge x)
{
    int i = n;
    while (i>0)
    {
        if (arr[i-1].edgez <= x.edgez)
        {
            break;
        }
        arr[i].edgex = arr[i-1].edgex;
        arr[i].edgey = arr[i-1].edgey;
        arr[i].edgez = arr[i-1].edgez;
        i--;
    }
    arr[i] = x;
}

void insertionSort (edge arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        edge x=arr[i];
        insertAsc(arr, i, x);
    }
}

int main()
{
    int m, k;
    cin >> m >> k;
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[i].edgex = x;
        a[i].edgey = y;
        a[i].edgez = z;
    }
    insertionSort(a, m);
    for (int i = k-1; i >= 0; i--)
    {
        cout << a[i].edgex << " " << a[i].edgey << endl;
    }
    

    return 0;
}
