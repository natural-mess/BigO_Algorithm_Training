#include <bits/stdc++.h>
using namespace std;

#define MAX 30000
int parent[MAX+5];
int ranks[MAX+5];

void makeSet()
{
    for (int i = 0; i < MAX; i++)
    {
        parent[i] = i;
        ranks[i] = 0;
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
    }
    else if (ranks[up] < ranks[vp])
    {
        parent[up] = vp;
    }
    else
    {
        parent[up] = vp;
        ranks[vp]++;
    }
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    cin.ignore();
    while(t--)
    {
        makeSet();
        string s;
        getline(cin, s);
        int n = s[0] - 'A' + 1;
        int res = 0;
        while (1)
        {
            if (!getline(cin, s) || s.empty())
            {
                break;
            }
            int u = s[0] - 'A';
            int v = s[1] - 'A';
            unionSet(u, v);
        }
        
        for (int i = 0; i < n; i++)
        {
            if (parent[i] == i)
            {
                res++;
            }
        }
        
        cout << res << endl << endl;
    }

    return 0;
}