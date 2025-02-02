#include <bits/stdc++.h>
using namespace std;

#define MAX 10001
const int INF = 1e9;
vector<pair<int,int>> graph[MAX];
vector<long long> dist(MAX, INF);
int path[MAX];
bool visited[MAX];
int N, M;

void printMST()
{
    long long ans = 0;
    for (int i = 0; i < N; i++)
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
    priority_queue<pair<int, int>, vector<pair<int, int>>, option> pq;
    pq.push(make_pair(src, 0));
    dist[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().first;
        pq.pop();
        visited[u] = true;

        for (auto i: graph[u])
        {
            int v = i.first;
            int w = i.second;

            if (!visited[v] && dist[v] > w)
            {
                dist[v] = w;
                pq.push({v, w});
                path[v] = u;
            }
        }
    }
}

int main()
{
    int u, v;
    long long w;
    cin >> N >> M;
    memset(path, -1, sizeof(path));
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        graph[u-1].push_back({v-1, w});
        graph[v-1].push_back({u-1, w});
    }
    int s = 0;
    prims(s);
    printMST();
    return 0;
}
