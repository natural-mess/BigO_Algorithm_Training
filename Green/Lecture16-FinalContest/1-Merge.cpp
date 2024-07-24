#include<bits/stdc++.h>
using namespace std;

void mergearray(int l[], int nL, int r[], int nR, int a[], int n)
{
    int i = 0, j = 0, k = 0;
    while (i < nL && j < nR) // ca 2 mang deu con phan tu
    {
        if (l[i] > r[j])
        {
            a[k] = l[i];
            k++;
            i++;
        }
        else
        {
            a[k] = r[j];
            k++;
            j++;
        }
    }
    while (i <= nL)
    {
        a[k] = l[i];
        ++k;
        ++i;
    }
    while (j <= nR)
    {
        a[k] = r[j];
        ++k;
        ++j;
    }
}

int main()
{
    int m,n,k;
    cin >> m >> n >> k;
    int a[m], b[n];
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int sizeC = m+n;
    int c[sizeC];
    mergearray(a, m, b, n, c, sizeC);
    cout << c[sizeC-k-1];
    // for (int i = 0; i < sizeC; i++)
    // {
    //     cout << c[i] << " ";
    // }
    
    return 0;
}
