#include <bits/stdc++.h>
using namespace std;

#define MAX 5002
const int INF = 1e9;
vector<int> dist(MAX, INF);

int n, m;

struct Edge
{
    int source;
    int target;
    int weight;
    Edge(int source, int target, int weight)
    {
        this->source = source;
        this->target = target;
        this->weight = weight;
    }
};
vector<Edge> graph;

void bellmanford(int s)
{
    int u, v, w;
    dist[s] = 0;

    for (int i = 0; i < (n-1); i++)
    {
        for (auto j: graph)
        {
            u = j.source;
            v = j.target;
            w = j.weight;
            if (dist[u]!=INF && dist[u]+w<dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    
    /* negative cycle path */
    for (int i = 0; i < (n-1); i++)
    {
        for (auto j: graph)
        {
            u = j.source;
            v = j.target;
            w = j.weight;
            if (dist[u]!=INF && dist[u]+w<dist[v])
            {
                dist[v] = -INF;
            }
        }
    }
}

int main()
{
    int q, s;
    while(1)
    {
        cin >> n >> m >> q >> s;
        if (n==0 && m==0 && q==0 && s==0)
        {
            break;
        }

        graph.clear();
        fill(dist.begin(), dist.end(), INF);

        int u, v, w;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            graph.push_back(Edge(u, v, w));
        }
        bellmanford(s);
        int truyVan;
        for (int i = 0; i < q; i++)
        {
            cin >> truyVan;
            if (dist[truyVan] == INF)
            {
                cout << "Impossible\n";
            }
            else if (dist[truyVan] == -INF)
            {
                cout << "-Infinity\n";
            }
            else
            {
                cout << dist[truyVan] << endl;
            }
        }
        cout << endl;
    }

    return 0;
}