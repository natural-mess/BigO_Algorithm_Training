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
    
    // Initialize DSU for n employees (using 1-indexing)
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        ranks[i] = 0;
    }
    
    // For each language, we store the list of employees who know that language.
    // Languages are numbered 1 to m.
    vector<int> language[105];
    bool anyKnown = false; // will be true if at least one employee knows at least one language
    
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        if(k > 0)
            anyKnown = true;
        for (int j = 0; j < k; j++)
        {
            int lang;
            cin >> lang;
            language[lang].push_back(i);
        }
    }
    
    // For each language, union all employees that know it.
    for (int lang = 1; lang <= m; lang++)
    {
        if (!language[lang].empty())
        {
            int first = language[lang][0];
            for (int j = 1; j < language[lang].size(); j++)
            {
                unionSet(first, language[lang][j]);
            }
        }
    }
    
    // Count the number of connected components (distinct DSU leaders)
    int components = 0;
    for (int i = 1; i <= n; i++)
    {
        if (findSet(i) == i)
            components++;
    }
    
    // If no employee knows any language, we must teach all n employees.
    // Otherwise, we need to connect the components, which costs (components - 1)
    int ans;
    if (!anyKnown)
        ans = n;
    else
        ans = components - 1;
    
    cout << ans << "\n";
    
    return 0;
}