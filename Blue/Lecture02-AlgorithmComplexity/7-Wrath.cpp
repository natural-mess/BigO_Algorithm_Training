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
    vector<int> add(n,0);
    vector<int> final(n,0);
    // 0 1 0 10
    // add
    // 0  0  0  0

    // 0  0  0  0
    // 1 -1  0  0
    // 1 -1  0  0
    // 2 -1  0 -1
    // final
    // 0 0 0 0
    
    // 2 1 1 0
    for (int i = 0; i < n; i++)
    {
        add[max(i-a[i],0)] += 1;
        add[i] -= 1;
    }
    final[0] = add[0];
    for (int i = 1; i < n; i++)
    {
        final[i] = final[i-1] + add[i];
    }
    int res=0;
    for (int i = 0; i < n; i++)
    {
        if (final[i]==0)
        {
            res++;
        }
    }
    cout << res;

    return 0;
}