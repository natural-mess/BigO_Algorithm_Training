#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int ar[n];

    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    sort(ar, ar+n);
    int med = n/2;
    cout << ar[med];

    return 0;
}