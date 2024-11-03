#include <bits/stdc++.h>
using namespace std;

#define MAX 100000+2

int t, n, e;
bool visited[MAX];
vector <int> a[MAX];

void dfs (int i)
{
    visited[i] = true;
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
    cin >> t;

    while (t--)
    {
        int x, y, count = 0;
        cin >> n;
        cin >> e;
        if (e == 0)
        {
            cout << n;
            return 0;
        }
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < MAX; i++) 
        {
            a[i].clear();
        }

        for (int i = 0; i < e; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }

        for (int i = 0; i < n; i++)
        {
            if (visited[i]==false)
            {
                dfs(i);
                count++;
            }
        }
        cout << count << endl;
        
    }
    


    return 0;
}