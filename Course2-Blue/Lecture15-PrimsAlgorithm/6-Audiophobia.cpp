#include <bits/stdc++.h>
using namespace std;

#define MAX 105
const int INF = 1e9;
vector<pair<int, int>> graph[MAX];
vector<int> dist(MAX, INF);
int path[MAX];
bool visited[MAX];
int c, s, q;

vector<pair<int, int>> mst[MAX];

void printMST()
{
    int ans = 0;
    for (int i = 0; i < c; i++)
    {
        if (ans >= INF)
        {
            cout << "Impossible" << endl;
            return;
        }
        ans += dist[i];
        // cout << path[i] << " - " << i << ": " << dist[i] << endl;
    }
    cout << ans << endl;
}

struct option
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
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
        if (visited[u])
        {
            continue;
        }
        visited[u] = true;

        for (auto i : graph[u])
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

    for (int i = 0; i < c; i++)
    {
        if (path[i] != -1)
        {
            int v = path[i];
            int w = dist[i];
            mst[i].push_back({v, w});
            mst[v].push_back({i, w});
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
        mst[i].clear();
    }
}

int bfs(int src, int dst)
{
    fill(visited, visited + c + 1, false);
    queue<pair<int,int>> q;
    q.push({src, 0});
    visited[src] = true;
    int noiseLevel = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        noiseLevel = q.front().second;
        q.pop();

        for (auto i : mst[x])
        {
            int v = i.first;
            int w = i.second;
            if (!visited[v])
            {
                int newNoise = max(noiseLevel, w);
                if (v == dst)
                {
                    return newNoise;
                }
                q.push({v, newNoise});
                visited[v] = true;
            }
        }
    }
    return INF;
}

int main()
{
    int tc = 1;
    while (1)
    {
        cin >> c >> s >> q;
        if (c == 0 && s == 0 && q == 0)
        {
            break;
        }
        ResetGraph();
        int c1, c2, d;
        for (int i = 0; i < s; i++)
        {
            cin >> c1 >> c2 >> d;
            graph[c1 - 1].push_back({c2 - 1, d});
            graph[c2 - 1].push_back({c1 - 1, d});
        }

        for (int i = 0; i < c; i++)
        {
            if (visited[i] != true)
            {
                prims(i);
            }
        }
        cout << "Case #" << tc++ << endl;
        for (int i = 0; i < q; i++)
        {
            cin >> c1 >> c2;
            int res = bfs(c1 - 1, c2 - 1);
            (res == INF) ? (cout << "no path\n") : (cout << res << endl);
        }
        cout << endl;
    }
    return 0;
}
