#include <bits/stdc++.h>
using namespace std;

#define MAX 751
const double INF = 1e9;
vector<pair<int,double>> graph[MAX];
vector<double> dist(MAX, INF);
int path[MAX];
bool visited[MAX];
int N, M;
int x[MAX], y[MAX];

double calDistance(int x1, int y1, int x2, int y2)
{
    return sqrt(1.00*(double)(x2-x1)*(double)(x2-x1) + 1.00*(double)(y2-y1)*(double)(y2-y1));
}

void printMST()
{
    double ans = 0.0;
    for (int i = 0; i < N; i++)
    {
        if (path[i] == -1)
        {
            continue;
        }
        ans += dist[i];
        // cout << path[i] << " - " << i << ": " << dist[i] << endl;
    }
    cout << fixed << setprecision(2) << ans << endl;
}

struct option
{
    bool operator() (const pair<int, double> &a, const pair<int, double> &b) const
    {
        return a.second > b.second;
    }
};

void prims(int src)
{
    priority_queue<pair<int, double>, vector<pair<int, double>>, option> pq;
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
            double w = i.second;

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
    while (cin >> N)
    {
        memset(path, -1, sizeof(path));
        for (int i = 0; i < MAX; i++)
        {
            graph[i].clear();
            dist[i] = INF;
            visited[i] = false;
        }

        
        for (int i = 0; i < N; i++)
        {
            cin >> x[i] >> y[i];
        }

        cin >> M;
        vector<vector<bool> > edges(MAX, vector<bool>(MAX, false));
        int a, b;

        for (int i = 0; i < M; i++)
        {
            cin >> a >> b;
            edges[a-1][b-1] = true;
            edges[b-1][a-1] = true;
        }
        
        for (int i = 0; i < N; i++)
        {
            for (int j = i+1; j < N; j++)
            {
                if (edges[i][j] == true)
                {
                    graph[i].push_back({j, 0.0});
                    graph[j].push_back({i, 0.0});
                }
                else
                {
                    graph[i].push_back({j, calDistance(x[i],y[i],x[j],y[j])});
                    graph[j].push_back({i, calDistance(x[j],y[j],x[i],y[i])});
                }
            }
        }
        prims(0);
        printMST();
        
    }
    return 0;
}
