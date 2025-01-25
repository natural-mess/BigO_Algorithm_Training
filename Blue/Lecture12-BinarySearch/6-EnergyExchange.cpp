#include <bits/stdc++.h>
using namespace std;

#define MAX_A 1000
#define ERROR 1e-7

int main()
{
    int n;
    double k;
    cin >> n >> k;
    vector<int> a(n);
    double maxEnergy = 0.0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (maxEnergy < a[i])
        {
            maxEnergy = a[i];
        }
    }
    double left = 0.0, right = 1000.0;
    double mid;
    double energyReceive, energyLost;
    while(right-left > ERROR)
    {
        mid = (left+right)/2.0;
        energyReceive = 0.0;
        energyLost = 0.0;
        for (auto i:a)
        {
            if (i > mid)
            {
                energyLost += (i - mid) * (1.0 - (k/100.0));
            }
            else if (i < mid)
            {
                energyReceive += (mid - i);
            }
        }
        
        if (energyLost >= energyReceive)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    cout << fixed << setprecision(6) << left;
    return 0;
}