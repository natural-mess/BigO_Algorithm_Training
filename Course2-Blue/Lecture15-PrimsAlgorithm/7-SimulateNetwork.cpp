#include <bits/stdc++.h>
using namespace std;

#define MAX 100005
const int INF = 1e9;
vector<pair<int, int>> graph[MAX];
vector<int> dist(MAX, INF);
int path[MAX];
bool visited[MAX];
int N, M;

vector<pair<int, int>> mst[MAX];

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
        mst[i].clear();
    }
}

bool comp(int a, int b) 
{
    return a > b;
}

int main(void)
{
    cin >> N >> M;
    int a, b, l;

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> l;
        graph[a].push_back({b, l});
        graph[b].push_back({a, l});
    }
    int q;
    cin >> q;
    int c;
    priority_queue<int, vector<int>, greater<int>> newCables;
    for (int i = 0; i < q; i++)
    {
        cin >> c;
        newCables.push(c);
    }

    prims(1);

    priority_queue<int> mst;
    for (int i = 2; i <= N; i++)
    {
        mst.push(dist[i]);
    }
    
    
    long long res = 0;
    int tempCable;
    while(!mst.empty())
    {
        tempCable = mst.top();
        mst.pop();
        if (!newCables.empty() && newCables.top() < tempCable)
        {
            tempCable = newCables.top();
            newCables.pop();
        }
        res += tempCable;
    }
    cout << res;

    return 0;
}
