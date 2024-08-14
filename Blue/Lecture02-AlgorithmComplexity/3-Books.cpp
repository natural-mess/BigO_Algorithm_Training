#include <bits/stdc++.h>
using namespace std;

// vector<int> storeTime(100001);

int main()
{  
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int sum = 0;
    int st = 0;
    int i;
    int res = 0;
    for (i = 0; i < n; i++)
    {
        sum = sum + a[i];
        while (sum > t)
        {
            sum = sum - a[st];
            st++;
        }
        res = max(res, i-st+1);
    }
    

    cout << res;
    

    return 0;
}