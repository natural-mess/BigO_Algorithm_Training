#include <bits/stdc++.h>
using namespace std;

#define MAX 10002
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
    int s;
    cin >> s;
    while(s--)
    {
        int n;
        cin >> n;
        string cityName;
        int p;
        int nr, cost;
        int r;
        string name1, name2;
        vector<pair<string, int>> city;
        vector<pair<string, string>> expectedRet;
        graph = vector<vector<pair<int,int>>>(n+1, vector<pair<int,int>>());
        for (int i = 0; i < n; i++)
        {
            cin >> cityName;
            city.push_back({cityName, i+1});
            cin >> p;
            while(p--)
            {
                cin >> nr >> cost;
                graph[i+1].push_back({nr, cost});
            }
        }
        cin >> nr;
        for (int i = 0; i < nr; i++)
        {
            cin >> name1 >> name2;
            expectedRet.push_back({name1, name2});
        }
        
        
        for (int i = 0; i < nr; i++)
        {
            fill(dist.begin(), dist.end(), INF);
            for (int j = 0; j < n; j++)
            {
                if (expectedRet[i].first == city[j].first)
                {
                    dijkstra(city[j].second);
                    break;
                }
            }
            for (int j = 0; j < n; j++)
            {
                if (expectedRet[i].second == city[j].first)
                {
                    cout << dist[city[j].second] << endl;
                    break;
                }
            }
        }        
    }

    return 0;
}