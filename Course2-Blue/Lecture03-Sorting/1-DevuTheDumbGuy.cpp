#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());

    unsigned long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += (unsigned long long)x*(unsigned long long)a[i]; 
        if (x>1)
        {
            x--;
        }
    }
    cout << sum;

    return 0;
}