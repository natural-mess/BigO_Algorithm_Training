#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 105;
const int INF = 1e8;

int dist[MAX_N];
bool mark[MAX_N][MAX_N][3 * MAX_N];

struct Edge {
    int u, v, c;
};

vector<Edge> savedEdges, tempEdges;
vector<pair<int, int>> adjList[MAX_N];
bool visited[MAX_N];
int path[MAX_N];
int n, m, test;
int degree[MAX_N];

int prim(int source, vector<Edge> &edges) 
{
    fill(dist, dist + MAX_N, INF);
    fill(visited, visited + MAX_N, false);
    fill(path, path + MAX_N, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    dist[source] = 0;

    while (!pq.empty()) 
    {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto &edge : adjList[u])
        {
            int v = edge.first;
            int c = edge.second;

            if (visited[v] || mark[u][v][c] || dist[v] <= c) 
                continue;

            dist[v] = c;
            path[v] = u;
            pq.push({c, v});
        }
    }

    int totalWeight = 0;
    for (int i = 1; i <= n; i++) 
    {
        if (dist[i] == INF) return -1;
        totalWeight += dist[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (path[i] != -1) {
            edges.push_back({path[i], i, dist[i]});
        }
    }

    return totalWeight;
}

int main() 
{
    cin >> test;

    while (test--) 
    {
        memset(mark, false, sizeof(mark));
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
        {
            adjList[i].clear();
            degree[i] = 0;
        }

        for (int i = 0; i < m; i++)
        {
            int u, v, c;
            cin >> u >> v >> c;
            degree[u]++;
            degree[v]++;
            adjList[u].push_back({v, c});
            adjList[v].push_back({u, c});
        }

        savedEdges.clear();
        int mstWeight = prim(1, savedEdges);
        cout << mstWeight;

        int secondMstWeight = INF;

        for (auto &edge : savedEdges) 
        {
            int u = edge.u, v = edge.v, c = edge.c;
            mark[u][v][c] = mark[v][u][c] = true;
            degree[u]--; 
            degree[v]--;

            tempEdges.clear();
            int startNode = 1;
            while (startNode <= n && degree[startNode] == 0)
                startNode++;

            int currentWeight = prim(startNode, tempEdges);
            if (currentWeight >= 0) 
            {
                secondMstWeight = min(secondMstWeight, currentWeight);
            }

            mark[u][v][c] = mark[v][u][c] = false;
            degree[u]++; 
            degree[v]++;
        }

        if (secondMstWeight == INF) 
            secondMstWeight = mstWeight;
        cout << secondMstWeight;
    }

    return 0;
}