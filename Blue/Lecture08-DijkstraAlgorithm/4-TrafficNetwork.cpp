#include <bits/stdc++.h>
using namespace std;

#define MAX 100002
const int INF = 1e9;
vector<int> distS(MAX, INF);
vector<int> distT(MAX, INF);
vector<vector<pair<int,int>>> graphS;
vector<vector<pair<int,int>>> graphT;
int path[MAX];

struct option
{
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) const
    {
        return a.second > b.second;
    }
};


vector<int> dijkstra(int s, int t, vector<vector<pair<int,int>>> graph)
{
    vector<int> dist(MAX, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, option> qu;
    qu.push({s,0});
    dist[s] = 0;
    while(!qu.empty())
    {
        pair<int,int> top = qu.top();
        qu.pop();
        int u = top.first;
        int w = top.second;

        if (u == t) 
        { 
            break; 
        }

        if (w > dist[u]) 
        { 
            continue; 
        }

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
    return dist;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n, m, k, s, t;
        cin >> n >> m >> k >> s >> t;

        graphS = vector<vector<pair<int,int>>>(n+1, vector<pair<int,int>>());
        graphT = vector<vector<pair<int,int>>>(n+1, vector<pair<int,int>>());
        fill(distS.begin(), distS.end(), INF);
        fill(distT.begin(), distT.end(), INF);
        memset(path, 0, sizeof(path));

        int d, c, l;
        for (int i = 0; i < m; i++)
        {
            cin >> d >> c >> l;
            graphS[d].push_back({c, l});
            graphT[c].push_back({d, l});
        }

        int u, v, q;
        int res = 0;
        distS = dijkstra(s, t, graphS);
        distT = dijkstra(t, s, graphT);
        for (int i = 0; i < k; i++)
        {
            cin >> u >> v >> q;
            if (res == 0)
            {
                res = distS[u]+q+distT[v];
            }
            else
            {
                res = min(res, min(distS[u]+q+distT[v], distS[v]+q+distT[u]));
            }
            
        }
        if (res >= INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << res << endl;
        }
        
    }

    return 0;
}
