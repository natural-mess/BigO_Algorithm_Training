#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> p(n+1);
    map<long long, long long> m;
    long long price;
    for (int i = 1; i <= n; i++)
    {
        cin >> price;
        p[i] = price;
        m[price] = i;
    }
    sort(p.begin(), p.end());
    long long minLoss = LLONG_MAX;
    for (int i = 2; i <= n; i++)
    {
        if (m[p[i-1]] > m[p[i]])
        {
            minLoss = min(minLoss, p[i] - p[i-1]);
        }
    }
    

    cout << minLoss;
    
    return 0;
}