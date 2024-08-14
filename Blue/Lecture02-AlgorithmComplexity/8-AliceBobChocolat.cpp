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
    
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    int trackBob = n-1;
    int trackAlice = 0;
    int alice=0, bob=0;
    int sumAlice = a[0];
    int sumBob = a[n-1];
    for (int i = 0; i < sum; i++)
    {
        if (i==sumAlice && n>0)
        {
            trackAlice++;
            sumAlice = sumAlice+a[trackAlice];
            alice++;
            n--;
        }
        if (i==sumBob && n>0)
        {
            trackBob--;
            sumBob = sumBob+a[trackBob];
            bob++;
            n--;
        }
        if (n==0)
        {
            break;
        }
    }
    cout << alice << " " << bob;
    

    return 0;
}