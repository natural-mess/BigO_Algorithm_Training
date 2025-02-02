#include <bits/stdc++.h>
using namespace std;

#define MAX 1001
const int INF = 1e9;
vector<pair<int,int>> graph[MAX];
vector<int> dist(MAX, INF);
int path[MAX];
bool visited[MAX];
int N, M;

void printMST(int p)
{
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (path[i] == -1)
        {
            continue;
        }
        ans += dist[i];
        // cout << path[i] << " - " << i << ": " << dist[i] << endl;
    }
    cout << ans * p << endl;
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

void ResetGraph()
{
	for (int i = 0; i < N; i++)
	{
		graph[i].clear();
		visited[i] = false;
		dist[i] = INF;
		path[i] = -1;
	}
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(path, -1, sizeof(path));
        for (int i = 0; i < MAX; i++)
        {
            graph[i].clear();
            dist[i] = INF;
            visited[i] = false;
        }
        int p;
        cin >> p;
        cin >> N >> M;
        int a, b, c;
        for (int i = 0; i < M; i++)
        {
            cin >> a >> b >> c;
            graph[a-1].push_back({b-1, c});
            graph[b-1].push_back({a-1, c});
        }
        prims(0);
        printMST(p);
    }
    return 0;
}
