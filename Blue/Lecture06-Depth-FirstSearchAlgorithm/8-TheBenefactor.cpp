#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 50002u

vector<vector<pair<int, int>>> arr;
int d[MAX_SIZE];
vector<pair<int, int>> graph[MAX_SIZE];
int ans = 0;
int x;

// graph[0] = [0]first, second, [1]first, second

void dfs(int i)
{
    for (pair<int,int> j:graph[i])
    {
        if (d[j.first] == -1)
        {
            d[j.first] = d[i] + j.second;
            if (d[j.first] > ans)
            {
                ans = d[j.first];
                x = j.first;
            }
            dfs(j.first);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b, l;
        cin >> n;

        // init
        for (int i = 1; i <= n; i++)
        {
            d[i] = -1;
            graph[i].clear();
        }

        // input
        for (int i = 0; i < (n-1); i++)
        {
            cin >> a >> b >> l;
            graph[a].push_back({b,l});
            graph[b].push_back({a,l});
        }
        ans = 0;
        d[1] = 0;
        dfs(1);
        memset(d, -1, sizeof(d));
        d[x] = 0;
        dfs(x);
        cout << ans << endl;

    }

    return 0;
}
