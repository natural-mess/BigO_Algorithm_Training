#include <bits/stdc++.h>
using namespace std;

#define MAX 10002

int n, m, x, y;
vector <int> a[MAX];
bool visited[MAX];
int res = 0;
vector <int> stor;

void dfs (int i)
{
    visited[i] = true;
    res++;
    for (auto j: a[i])
    {
        if (visited[j] == false)
        {
            dfs(j);
        }
    }
}

int main()
{
    cin >> n >> m;
    memset(visited, false, sizeof(visited));
    
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
    }

    
    for (int i = 1; i <= n; i++)
    {
        dfs(i);
        stor.push_back(res);
        memset(visited, false, sizeof(visited));
        res = 0;
    }

    
    sort (stor.begin(), stor.end(), greater<int>());
    
    cout << stor[0];
    return 0;
}
