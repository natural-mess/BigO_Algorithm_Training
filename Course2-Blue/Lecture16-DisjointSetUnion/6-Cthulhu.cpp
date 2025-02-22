#include <bits/stdc++.h>
using namespace std;

#define MAX 100
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

//For a person x, parent[x] represents their friend group, and parent[x + MAX] represents their enemy group.
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
	int n, m;
	cin >> n >> m;

    if (n != m) 
    {
        cout << "NO";
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
		parent[i] = i;
    }

    int x, y;
    for (int i = 0; i < m; i++) 
    {
        cin >> x >> y;
        unionSet(x, y);
    }

    int res = 0;
    for (int i = 1; i <= n; i++) 
    {
        if (i == parent[i]) 
        {
            res++;
            if (res > 1) 
            {
                break;
            }
        }
    }

    cout << (res == 1 ? "FHTAGN!" : "NO");
	
	return 0;
}