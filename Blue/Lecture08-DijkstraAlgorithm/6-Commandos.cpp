#include <bits/stdc++.h>
using namespace std;

#define MAX 1002
const int INF = 1e9;
vector<vector<pair<int,int>>> graph;
int path[MAX];

struct option
{
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) const
    {
        return a.second > b.second;
    }
};


int dijkstra(int s, int d)
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

        if (u == d) 
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
    return dist[d];
}

int main()
{
    int T;
    cin >> T;

    int caseCount = 1;
    while(T--)
    {
        vector<int> distS(MAX, INF);
        vector<int> distD(MAX, INF);
        int N, R;
        cin >> N;
        cin >> R;

        graph = vector<vector<pair<int,int>>>(N, vector<pair<int,int>>());
        fill(distS.begin(), distS.end(), INF);
        fill(distD.begin(), distD.end(), INF);
        memset(path, 0, sizeof(path));

        int u, v, s, d;
        for (int i = 0; i < R; i++)
        {
            cin >> u >> v;
            graph[u].push_back({v, 1});
            graph[v].push_back({u, 1});
        }
        cin >> s >> d;
        int result = 0;
        
        for (int i = 0; i < N; i++)
        {
            distS[i] = dijkstra(s, i);
        }

        for (int i = 0; i < N; i++)
        {
            distD[i] = dijkstra(d, i);
        }

        for (int i = 0; i < N; i++)
        {
            result = max(result, distS[i]+distD[i]); 
        }
        
        cout << "Case " << caseCount++ << ": " << result << endl;

    }

    return 0;
}
