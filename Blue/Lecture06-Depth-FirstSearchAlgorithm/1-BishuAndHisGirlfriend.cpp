#include <bits/stdc++.h>
using namespace std;
int n, x, y, q, visited[1002], place[1002], d[1002];
vector <int> a[1002];

void dfs(int i)
{
    visited[i] = true;
    for (auto j: a[i])
    {
        if (visited[j] == false)
        {
            d[j] = min(d[j], d[i]+1);
            dfs(j);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
        d[i] = n + 1;
    }

    for (int i = 1; i <= n-1; i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    
    d[1] = 0;
    dfs(1);
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> place[i];
    }
    int res = place[1];
    for (int i = 2; i <= q; i++)
    {
        if (d[res] > d[place[i]])
        {
            res = place[i];
        }
        if (d[place[i]] == d[res])
        {
            res = min(res, place[i]);
        }
    }
    cout << res;
    

    return 0;
}
