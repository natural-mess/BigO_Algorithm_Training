#include <bits/stdc++.h>
using namespace std;

// tim duong di ngan nhat giua 2 tuong dai bat ki
// neu co chu trinh am nghia la luon co duong di ngan hon
// tao mang dist la 2 chieu

#define MAX 100+2
const long long INF = 1e18;
long long dist[MAX][MAX];

struct Edge
{
    int source;
    int target;
    long long weight;
    Edge (int source, int target, long long weight)
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
    dist[s][s] = 0;
    for (int i = 0; i < (n-1); i++)
    {
        for (auto j: graph)
        {
            int u = j.source;
            int v = j.target;
            long long w = j.weight;
            if (dist[s][u]!=INF && dist[s][u]+w<dist[s][v])
            {
                dist[s][v] = dist[s][u] + w;
            }
        }
    }
    for (int i = 0; i < (n-1); i++)
    {
        for (auto j: graph)
        {
            int u = j.source;
            int v = j.target;
            long long w = j.weight;
            if (dist[s][u]!=INF && dist[s][u]+w<dist[s][v])
            {
                dist[s][v] = -INF;
            }
        }
    }
}

int main(void)
{
    int caseCount = 1;
    while (cin>>n, n!=0)
    {
        graph.clear();
        // fill(dist.begin(), dist.end(), INF);
        string city;
        long long distance;
        string cityList[MAX];

        for (int i = 0; i < n; i++)
        {
            cin >> cityList[i];
            for (int j=0; j<n; j++)
            {
                dist[i][j] = INF;
                cin >> distance;
                if (i!=j && distance == 0)
                {
                    continue;
                }
                if (i==j && distance >= 0)
                {
                    distance = 0;
                }
                graph.push_back((Edge){i, j, distance});
            }
        }
        
        int q;
        cin >> q;
        int u, v;
        for (int i = 0; i < n; i++)
        {
            bellmanford(i);
        }
        
        cout << "Case #" << caseCount++ << ":" << endl;
        for (int i = 0; i < q; i++)
        {
            cin >> u >> v;
            // fill(dist.begin(), dist.end(), INF);
            // bellmanford(u);
            long long ans = dist[u][v];
            if (ans == -INF)
            {
                cout << "NEGATIVE CYCLE" << endl;
            }
            else
            {
                cout << cityList[u] << "-" << cityList[v] << " "; 
                if (ans == INF)
                {
                    cout << "NOT REACHABLE" << endl;
                }
                else
                {
                    cout << ans << endl;
                }
            }
            
        }
    }
    return 0;
}