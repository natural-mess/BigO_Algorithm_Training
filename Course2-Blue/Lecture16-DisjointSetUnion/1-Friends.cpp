#include <bits/stdc++.h>
using namespace std;

#define MAX 30000
int parent[MAX+5];
int ranks[MAX+5];
int countFriend[MAX+5];

void makeSet()
{
    for (int i = 1; i <= MAX; i++)
    {
        parent[i] = i;
        ranks[i] = 0;
        countFriend[i] = 1;
    }
}

int findSet(int u)
{
    if (parent[u]!=u)
    {
        parent[u] = findSet(parent[u]);
    }
    return parent[u];
}

void unionSet(int u, int v)
{
    int up = findSet(u);
    int vp = findSet(v);
    if (up == vp)
    {
        return;
    }
    if (ranks[up] > ranks[vp])
    {
        parent[vp] = up;
        countFriend[up] = countFriend[up] + countFriend[vp];
    }
    else if (ranks[up] < ranks[vp])
    {
        parent[up] = vp;
        countFriend[vp] = countFriend[vp] + countFriend[up];
    }
    else
    {
        parent[up] = vp;
        ranks[vp]++;
        countFriend[vp] = countFriend[vp] + countFriend[up];
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        makeSet();
        int n, m;
        cin >> n >> m;
        int a, b;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            unionSet(a, b);
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            res = max(res, countFriend[i]);
        }
        cout << res << endl;
    }

    return 0;
}