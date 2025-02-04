#include <bits/stdc++.h>
using namespace std;

#define MAX 3005
const int INF = 1e9;
vector<pair<int, int>> graph[MAX];
vector<int> dist(MAX, INF);
int path[MAX];
bool visited[MAX];
int N, M;

void printMST()
{
    long long ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (path[i] == -1)
        {
            continue;
        }
        ans += dist[i];
        // cout << path[i] << " - " << i << ": " << dist[i] << endl;
    }
    cout << ans << endl;
}

struct option
{
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const
    {
        return a.second > b.second;
    }
};

void prims(int src)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, option> pq;
    pq.push({src, 0});
    dist[src] = 0;
    while(!pq.empty())
    {
        int u = pq.top().first;
        pq.pop();
        if (visited[u])
        {
            continue;
        }
        visited[u] = true;

        for (auto i: graph[u])
        {
            int v = i.first;
            int w = i.second;

            if(!visited[v] && dist[v] > w)
            {
                dist[v] = w;
                pq.push({v, w});
                path[v] = u;
            }
        }
    }
}

void ResetGraph()
{
    for (int i = 0; i < MAX; i++)
    {
        graph[i].clear();
        visited[i] = false;
        dist[i] = INF;
        path[i] = -1;
    }
}

int main(void)
{
    ResetGraph();
    cin >> N >> M;
    int x, y, r;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> r;
        graph[x].push_back({y, r});
        graph[y].push_back({x, r});
    }
    int s;
    cin >> s;
    prims(s);
    printMST();

    return 0;
}
