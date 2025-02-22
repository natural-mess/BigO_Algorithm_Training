#include <bits/stdc++.h>
using namespace std;

#define MAX 100000
int parent[MAX+5];
int ranks[MAX+5];
int n, q; 
int cnt[MAX+5];  
int maxi = 0; 
priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq; 

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
    if (up != vp) 
    {
		cnt[up] += cnt[vp];
		parent[vp] = up;
		pq.push(make_pair(cnt[up], up));  
		maxi = max(maxi, cnt[up]); 
	}
}

int main()
{
	cin >> n >> q;
    for (int i = 1; i <= n; i++) 
    {
		cnt[i] = 1; 
		parent[i] = i; 
		pq.push(make_pair(1, i)); 
	}

    maxi = 1; 

	for (int i = 1; i <= q; i++) 
    {
		int u, v; 
		cin >> u >> v;
		unionSet(u, v);
		while (true) 
        {
			pair <int, int> tmp = pq.top(); 
			int r = findSet(tmp.second); 
			if (r != tmp.second) 
            {
				pq.pop();
				continue; 
			}

			if (cnt[r] != tmp.first) 
            {
				pq.pop();
				continue; 
			}

			break; 
		}

		cout << (maxi - pq.top().first) << endl; 
	}
	
	return 0;
}