#include<bits/stdc++.h>
using namespace std;
int n, a[1000];

void mergearray(int l[], int nL, int r[], int nR, int a[], int n)
{
    int i = 1, j = 1, k = 1;
    while (i <= nL && j <= nR) // ca 2 mang deu con phan tu
    {
        if (l[i] <= r[j])
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

void mergesort(int a[], int n)
{
    if (n <= 1)
        return;
    int mid = n/2;
    int l[mid + 1], r[n - mid + 1];
    for (int i = 1; i <= mid; ++i)
        l[i] = a[i];
    for (int i = mid + 1; i <= n; ++i)
        r[i - mid] = a[i];
    mergesort(l, mid);
    mergesort(r, n - mid);
    mergearray(l, mid, r, n - mid, a, n);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    mergesort(a, n);
    for (int i = 1; i <= n; ++i)
        cout << a[i] << " ";
}