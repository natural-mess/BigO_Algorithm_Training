#include <bits/stdc++.h>
using namespace std;

#define MAX 50002
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
    int N;
    cin >> N;
    int caseCount = 1;

    while(N--)
    {
        int n, m, s, t, w;
        cin >> n >> m >> s >> t;

        graph = vector<vector<pair<int,int>>>(n, vector<pair<int,int>>());

        int tempS, tempT, tempW;

        for (int i = 0; i < m; i++)
        {
            cin >> tempS >> tempT >> tempW;
            graph[tempS].push_back({tempT, tempW});
            graph[tempT].push_back({tempS, tempW});
        }
        dijkstra(s);
        if (dist[t]!=INF)
        {
            cout << "Case #" << caseCount++ << ": " << dist[t] << endl;
        }
        else
        {
            cout << "Case #" << caseCount++ << ": " << "unreachable" << endl;
        }
        
        fill(dist.begin(), dist.end(), INF);
        memset(path, 0, sizeof(path));
    }

    return 0;
}
