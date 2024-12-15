#include <bits/stdc++.h>
using namespace std;

#define MAX 502
const int INF = 1e9;

vector<vector<pair<int,int>>> graph;
vector<int> dist(MAX, INF); //creates a vector of size MAX where every element is set to the value INF
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
    priority_queue<pair<int,int>,vector<pair<int,int>>, option> pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;
    while(!pq.empty())
    {
        pair<int,int> top = pq.top();
        pq.pop();
        int u = top.first;
        int w = top.second;

        for (int i = 0; i < graph[u].size(); i++)
        {
            pair<int,int> neighbor = graph[u][i];
            if (w + neighbor.second < dist[neighbor.first])
            {
                dist[neighbor.first] = w+neighbor.second;
                pq.push(pair<int,int>(neighbor.first, dist[neighbor.first]));
                path[neighbor.first]=u;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int a,b,w;
    graph = vector<vector<pair<int,int>>>(MAX, vector<pair<int,int>>());
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
    int start;
    cin >> start;
    dijkstra(start);
    int q;
    cin >> q;
    int arr[q];
    int ans;
    for (int i = 0; i < q; i++)
    {
        cin >> arr[i];
    }
    
    for (int i = 0; i < q; i++)
    {
        ans = dist[arr[i]];
        if (ans!=INF)
        {
            cout << ans << endl;
        }
        else
        {
            cout << "NO PATH" << endl;
        }
    }
    return 0;
}
