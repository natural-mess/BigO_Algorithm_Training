// chay bellmanford tu dinh 1 
// tim phan tu lon nhat trong mang dist, chinh la kqua can tim
#include <bits/stdc++.h>
using namespace std;

#define MAX 102
const int INF = 1e9;
vector<int> dist;

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
int n;

void bellmanford(int s)
{
    dist[s] = 0;
    for (int i = 0; i < (n-1); i++)
    {
        for (auto j:graph)
        {
            int u = j.source;
            int v = j.target;
            int w = j.weight;
            if (dist[u]!=INF && dist[u]+w<dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
}

int main(void)
{
    string input;
    int w;
    cin >> n;
    dist.assign(n + 1, INF);
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            cin >> input;
            if (input != "x")
            {
                w = stoi(input);
                graph.push_back(Edge{i, j, w});
                graph.push_back(Edge{j, i, w});
            }
        }
    }
    bellmanford(1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i]!= INF && dist[i] > ans)
        {
            ans = dist[i];
        }
    }
    cout << ans;
    return 0;
}

