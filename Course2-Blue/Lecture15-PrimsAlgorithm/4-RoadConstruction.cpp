#include <bits/stdc++.h>
using namespace std;

#define MAX 105
const int INF = 1e9;
map<string, int> myMap;
vector<pair<int,int>> graph[MAX];
vector<int> dist(MAX, INF);
int path[MAX];
bool visited[MAX];
int N, M;

void printMST()
{
    int ans = 0;
    for (int i = 0; i < N; i++)
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
        if (visited[u])
        {
            continue;
        }
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
    myMap.clear();
	for (int i = 0; i < MAX; i++)
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
    int tc = 1;
    while (t--)
    {
        N = 0;
        ResetGraph();
        cin >> M;
        string s1, s2;
        int w;
        for (int i = 0; i < M; i++)
        {
            cin >> s1 >> s2 >> w;
            if (myMap.find(s1) == myMap.end())
            {
                myMap[s1] = N++;
            }
            if (myMap.find(s2) == myMap.end())
            {
                myMap[s2] = N++;
            }

            int u = myMap[s1];
            int v = myMap[s2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        prims(0);
        cout << "Case " << tc++ << ": ";
        printMST();
    }
    return 0;
}
