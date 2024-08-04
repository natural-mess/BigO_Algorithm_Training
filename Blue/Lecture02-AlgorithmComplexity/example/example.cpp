#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[100005], visited[100005];

int main()
{
//    freopen("a.inp", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int st = 1;
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i > 1 && a[i] == a[st])
            ++st;
        while (a[st] == a[st + 1] && st + 1 <= i)
            ++st;
        if (visited[a[i]] == 0)
        {
            ++cnt;
            visited[a[i]] = 1;
        }
        if (cnt == k)
        {
            cout << st << " " << i;
            return 0;
        }
    }
    cout << -1 << " " << -1;
    return 0;
}