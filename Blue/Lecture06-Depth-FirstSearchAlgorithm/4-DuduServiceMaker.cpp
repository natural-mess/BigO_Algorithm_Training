#include <bits/stdc++.h>
using namespace std;

#define MAX 10000 +2
#define MAX3 30000 + 2

int t;
int n, m;
int x, y;

vector <int> a[MAX];
int visited[MAX], check[MAX];
int path[MAX];
int res = 0;

void dfs (int i)
{
    visited[i] = 0;
    check[i] = true;
    for (auto j: a[i])
    {
        if (check[j] == true)
        {
            res = 1;
        }
        if (visited[j] == -1)
        {
            dfs(j);
        }
    }
    check[i] = false;
}

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        memset(visited, -1, sizeof(visited));
        memset(check, 0, sizeof(check));

        for (int i = 1; i <= n; i++) 
        {
            a[i].clear();
        }

        for (int i = 1; i <= m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            // a[y].push_back(x);
        }
        res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] < 0)
            {
                if (res == 1)
                    break;
                dfs(i);
            }
            
        }

        
        (res==1)? (cout << "YES" << endl) : (cout << "NO" << endl);

    }

    return 0;
}

