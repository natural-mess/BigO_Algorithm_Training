#include <bits/stdc++.h>
using namespace std;

#define MAX 105
const double INF = 1.000000e9;
vector<double> dist((MAX*(MAX-1))/2, -1.0);

int n, m;

struct Edge
{
    int source;
    int target;
    double weight;
    Edge(int source, int target, double weight)
    {
        this->source = source;
        this->target = target;
        this->weight = weight;
    }
};
vector<Edge> graph;

double bellmanford(int s)
{
    int u, v;
    double w;
    dist[s] = 1.0;
    for (int i = 0; i < (n-1); i++)
    {
        for (auto edge: graph)
        {
            u = edge.source;
            v = edge.target;
            w = edge.weight;

            if (dist[v] < dist[u]*w)
            {
                dist[v] = dist[u]*w;
            }
        }
    }

    return dist[n];
}

int main()
{
    while (cin>>n, n!=0)
    {
        fill(dist.begin(), dist.end(), -1.0);
        graph.clear();
        cin >> m;
        int a, b;
        double p;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> p;
            graph.push_back(Edge{a, b, p/100.0});
            graph.push_back(Edge{b, a, p/100.0});
        }
        cout << fixed << setprecision(6) << bellmanford(1)*100.0 << " percent" << endl;
    }
    return 0;
}
