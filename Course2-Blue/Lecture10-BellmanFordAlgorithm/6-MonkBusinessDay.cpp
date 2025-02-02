#include <bits/stdc++.h>
using namespace std;

#define MAX 1002
const int INF = 1e9;
vector<int> dist(MAX, -INF);

struct Edge
{
    int source;
    int target;
    int weight;
    Edge (int source, int target, int weight)
    {
        this->source = source;
        this->target = target;
        this->weight = weight;
    }
};
vector<Edge> graph;

int n, m;

bool bellmanford(int s)
{
    dist[s] = 0;
    int u, v, w;

    for (int i = 0; i < (n-1); i++)
    {
        for (auto j:graph)
        {
            u = j.source;
            v = j.target;
            w = j.weight;
            if (dist[u]!=-INF && dist[u]+w>dist[v])
            {
                dist[v] = dist[u]+w;
            }
        }
    }
    
    /* check positive cycle  */
    for (auto i:graph)
    {
        u = i.source;
        v = i.target;
        w = i.weight;
        if (dist[u]!=-INF && dist[u]+w>dist[v])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;

        int i, j, C;
        
        fill(dist.begin(), dist.end(), -INF);
        graph.clear();

        for (int k = 0; k < m; k++)
        {
            cin >> i >> j >> C;
            graph.push_back(Edge(i, j, C));
        }
        cout << (bellmanford(1)?"Yes":"No") << endl;
    }
    return 0;
}