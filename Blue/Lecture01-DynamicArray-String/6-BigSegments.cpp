#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n==1)
    {
        cout << n;
        return 0;
    }
    int a[n][2];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    int minL=0, maxR=0;
    for (int i = 0; i < n; i++)
    {
        if (a[i][0] != a[i][1])
        {
            minL = a[i][0];
            maxR = a[i][1];
            break;
        }
    }
    int count = 0;
    int result=0;
    if (minL==0 || maxR==0)
    {
        cout << -1;
        return 0;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i][0]<=minL && a[i][1]>=maxR)
            {
                minL = a[i][0];
                maxR = a[i][1];
                result = i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (minL<=a[i][0] && a[i][1]<=maxR)
            {
                count++;
            }
        }
        if (count <n)
        {
            cout << -1;
        }
        else
        {
            cout << result+1;
        }
    }

    return 0;
}