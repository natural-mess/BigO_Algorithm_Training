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
    while(t--)
    {
        makeSet();
        int p, t;
        cin >> p >> t;
        cin.ignore();
        vector<set<int>> people(p+1);
        string s;
        int person, tree;
        while (1)
        {
            if (!getline(cin, s) || s.empty())
            {
                break;
            }
            stringstream ss(s);
            ss >> person >> tree;
            people[person].insert(tree);
        }

        for (int i = 1; i < p; i++)
        {
            for (int j = i+1; j < p+1; j++)
            {
                if (people[i] == people[j])
                {
                    unionSet(i, j);
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= p; i++)
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