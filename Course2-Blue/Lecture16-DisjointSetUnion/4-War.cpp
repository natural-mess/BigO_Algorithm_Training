#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
int parent[MAX+MAX];
int ranks[MAX+MAX];

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
	int n, c, x, y;
	cin >> n;
	for (int i = 0; i < MAX * 2; i++)
    {
		parent[i] = i;
    }
	while (1) 
    {
		cin >> c >> x >> y;
		if (c == 0 && x == 0 && y == 0) 
        {
			break;
		}
		if (c == 1) 
        {
			if (findSet(x) == findSet(y + MAX)) {
				cout << -1 << endl;
				continue;
			}
			unionSet(x, y);
			unionSet(x + MAX, y + MAX);
		}
		else if (c == 2) 
        {
			if (findSet(x) == findSet(y)) 
            {
				cout << -1 << endl;
				continue;
			}
			unionSet(x, y + MAX);
			unionSet(x + MAX, y);
		}
		else if (c == 3) 
        {
			cout << (findSet(x) == findSet(y)) << endl;
		}
		else if (c == 4) 
        {
			cout << (findSet(x) == findSet(y + MAX)) << endl;
		}
	}
	return 0;
}