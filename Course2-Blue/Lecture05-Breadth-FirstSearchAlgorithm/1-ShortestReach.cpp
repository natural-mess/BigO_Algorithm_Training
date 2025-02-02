#include<bits/stdc++.h>
using namespace std;
int n, m, q, x, y, st, d[1002], visited[1002];
vector < int > a[1002];
int main()
{
//    freopen("a.inp", "r", stdin);
    cin >> q;
    for (int ii = 1; ii <= q; ++ii)
    {
        cin >> n >> m;
        queue < int > qu;
        for (int i = 1; i <= n; ++i)
        {
            visited[i] = false;
            d[i] = -1;
            a[i].clear();
        }
        for (int i = 1; i <= m; ++i)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        cin >> st;
        d[st] = 0;
        qu.push(st);
        visited[st] = true;
        while (!qu.empty())
        {
            int x = qu.front();
            qu.pop();
            for (auto i: a[x])
            {
                if (visited[i] == false)
                {
                    visited[i] = true;
                    d[i] = d[x] + 6;
                    qu.push(i);
                }
            }
        }
        for (int i = 1; i <= n; ++i)
            if (i != st)
                cout << d[i] << " ";
        cout << '\n';
    }
}