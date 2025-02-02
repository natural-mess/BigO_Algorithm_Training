#include <bits/stdc++.h>
using namespace std;

#define MAX 2002
const int INF = 1e9;
vector<int> dist(MAX, INF);
vector<int> path(MAX, -1);

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

bool bellmanFord(int s)
{
    int u, v, w;
    dist[s] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            u = graph[j].source;
            v = graph[j].target;
            w = graph[j].weight;
            if (dist[u] != INF && (dist[u] + w < dist[v]))
            {
                dist[v] = dist[u] + w;
                path[v] = u;
            }
        }
    }
    
    // negative cycle check
    for (int i = 0; i < m; i++)
    {
        u = graph[i].source;
        v = graph[i].target;
        w = graph[i].weight;
        if (dist[u] != INF && (dist[u] + w < dist[v]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cout << endl;
        cin >> n;
        int busyness[n];
        for (int i = 0; i < n; i++)
        {
            cin >> busyness[i];
        }
        cin >> m;
        int x, y;
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            graph.push_back(Edge{x, y, (busyness[y]-busyness[x])*(busyness[y]-busyness[x])*(busyness[y]-busyness[x])});
        }
        
    }

    return 0;
}

