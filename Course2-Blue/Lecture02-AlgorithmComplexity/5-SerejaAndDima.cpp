#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sereja = 0;
    int dima = 0;
    int k = n - 1;
    int i = 0;
    bool flag = false;
    int temp;
    while (i<=k)
    {
        if (a[i] >= a[k])
        {
            temp = i;
            i++;
        }
        else
        {
            temp = k;
            k--;
        }
        if (flag == false)
        {
            sereja += a[temp];
            flag = true;
        }
        else
        {
            dima+= a[temp];
            flag = false;
        }
    }

    cout << sereja << " " << dima;

    return 0;
}