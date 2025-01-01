// distS[u] + w + distD[v] == distS[D]
// distS[v] + w + distD[u] == distS[D]
// neu no thoa man 2 dieu kien tren thi no nam tren duong di ngan nhat

#include <bits/stdc++.h>
using namespace std;

#define MAX 10002
const int INF = 1e9;
vector<vector<pair<int,int>>> graphS;
vector<vector<pair<int,int>>> graphD;
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
    while(1)
    {
        int N, M;
        cin >> N >> M;

        if (N==0 && M==0)
        {
            break;
        }
        
        int S, D;
        vector<int> distS(MAX, INF);
        vector<int> distD(MAX, INF);
        cin >> S >> D;

        int U, V, P;
        graphS = vector<vector<pair<int,int>>>(N, vector<pair<int,int>>());
        graphD = vector<vector<pair<int,int>>>(N, vector<pair<int,int>>());
        for (int i = 0; i < M; i++)
        {
            cin >> U >> V >> P;
            graphS[U].push_back({V, P});
            graphD[V].push_back({U, P});
        }

        distS = dijkstra(S, D, graphS);
        distD = dijkstra(D, S, graphD);

        vector<vector<pair<int,int>>> graphS_new = vector<vector<pair<int,int>>>(N, vector<pair<int,int>>());

        for (int i = 0; i < N; i++)
        {
            for (auto j : graphS[i])
            {
                if ((distS[i] + j.second + distD[j.first]) != distS[D])
                {
                    graphS_new[i].push_back(j);
                }
            }
        }
        vector<int> distS_new(MAX, INF);
        distS_new = dijkstra(S, D, graphS_new);

        cout << ((distS_new[D]==INF) ? (-1) : (distS_new[D])) << endl;
    }

    return 0;
}