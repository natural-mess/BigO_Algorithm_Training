#include <bits/stdc++.h>
using namespace std;

#define MAX 105
const int INF = 1e9;
bool visited[MAX];
vector<int> dist(MAX, INF);
vector<int> path(MAX, -1);

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

bool bfs(int s, int t)
{
    fill(visited, visited+(n+1), false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (auto i: graph)
        {
            int u = i.source;
            int v = i.target;

            if (u == x && !visited[v])
            {
                visited[v] = 1;
                q.push(v);
                if (v==t)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool bellmanford (int s, int t)
{
    int u, v, w;
    dist[s] = 100;
    for (int i = 0; i < (n-1); i++)
    {
        for (auto edge: graph)
        {
            u = edge.source;
            v = edge.target;
            w = edge.weight;
            if (dist[u] > 0 && dist[v] < dist[u] + w)
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    
    for (int i = 0; i < (n-1); i++)
    {
        for (auto edge: graph)
        {
            u = edge.source;
            v = edge.target;
            w = edge.weight;
            if (dist[u] > 0 && dist[v] < dist[u] + w && bfs(u, t))
            {
                return true;
            }
        }
    }
    return dist[t] > 0;
}

int main()
{
    while (1)
    {
        cin >> n;
        if (n==-1)
        {
            break;
        }

        fill(dist.begin(), dist.end(), -INF);
        fill(path.begin(), path.end(), -1);
        
        graph.clear();

        int power[n], numOfRoom, roomNum;
        for (int i = 1; i <= n; i++)
        {
            cin >> power[i] >> numOfRoom;
            while (numOfRoom--)
            {
                cin >> roomNum;
                graph.push_back(Edge{i, roomNum, power[i]});
            }
        }
        bool retVal = bellmanford(1, n);
        cout << ((retVal)?("winnable") : ("hopeless")) << endl;
    }

    return 0;
}