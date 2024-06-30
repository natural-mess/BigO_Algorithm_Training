#include<bits/stdc++.h>
using namespace std;
int n, a[1000];

void insertAsc(int x, int a[], int n)
{
    for (int j = n; j >= 0; --j)
        if (a[j - 1] <= x)
        {
            a[j] = x;
            return;
        }
        else
            a[j] = a[j - 1];
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    // Hiện tại có i - 1 phần tử đã được sắp xếp
    for (int i = 1; i <= n; ++i)
    {
        int x = a[i];
        insertAsc(x, a, i);
    }
    for (int i = 1; i <= n; ++i)
        cout << a[i] << " ";
    // => O(n^2): n <= 10000
}