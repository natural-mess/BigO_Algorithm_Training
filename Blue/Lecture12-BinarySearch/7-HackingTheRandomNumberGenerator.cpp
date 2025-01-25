#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    int mid, left=0, right=n-1;
    int res=0;
    for (int i = 0; i < n; i++)
    {
        left = i+1;
        right = n-1;
        while(left <= right)
        {
            mid = (left + right)/2;

            if (abs(a[mid] - a[i]) == k)
            {
                res++;
                break;
            }
            else if (abs(a[mid] - a[i]) > k)
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
    }
    cout << res;

    return 0;
}
