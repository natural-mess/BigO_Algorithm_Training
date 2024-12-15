#include <bits/stdc++.h>
using namespace std;

#define MAX 102
const int INF = 1e9;
vector<int> dist(MAX, INF);
vector<vector<pair<int,int>>> graph;
int path[MAX];

struct option
{
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) const
    {
        return a.second > b.second;
    }
};


void dijkstra(int s)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, option> qu;
    qu.push({s,0});
    dist[s] = 0;
    while(!qu.empty())
    {
        pair<int,int> top = qu.top();
        qu.pop();
        int u = top.first;
        int w = top.second;

        for (int i = 0; i < graph[u].size(); i++)
        {
            pair<int,int> neighbor = graph[u][i];
            if (w + neighbor.second < dist[neighbor.first])
            {
                dist[neighbor.first] = w + neighbor.second;
                qu.push({neighbor.first, dist[neighbor.first]});
                path[neighbor.first] = u;
            }
        }
    }
}

int main()
{
    int n, e, t;
    cin >> n >> e >> t;
    int m;
    cin >> m;
    
    graph = vector<vector<pair<int,int>>>(n+1, vector<pair<int,int>>());
    int a, b, time;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> time;
        graph[a].push_back({b, time});
    }
    
    int mice = 0;
    for (int i = 1; i <= n; i++)
    {
        dijkstra(i);
        if(dist[e] <= t)
        {
            mice++;
        }
       fill(dist.begin(), dist.end(), INF);
    }

    cout << mice;

    return 0;
}
