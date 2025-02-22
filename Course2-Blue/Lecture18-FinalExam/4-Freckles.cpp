#include <bits/stdc++.h>
using namespace std;

#define MAX 102
const double INF = 1e9;
vector<pair<int,double>> graph[MAX];
vector<double> dist(MAX, INF);
int path[MAX];
bool visited[MAX];
int N, M;

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
    pq.push(make_pair(src, 0.0));
    dist[src] = 0.0;
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

void ResetGraph()
{
	for (int i = 0; i < MAX; i++)
	{
		graph[i].clear();
		visited[i] = false;
		dist[i] = INF;
		path[i] = -1;
	}
}

double calDistance(double x1, double y1, double x2, double y2)
{
    return sqrt(1.00*(x2-x1)*(x2-x1) + 1.00*(y2-y1)*(y2-y1));
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ResetGraph();
        cin >> N;
        double x, y;
        vector <pair<double, double>> getCoor;
        for (int i = 0; i < N; i++)
        {
            cin >> x >> y;
            getCoor.push_back({x, y});
        }
        for (int i = 0; i < N-1; i++)
        {
            for (int j = i+1; j < N; j++)
            {
                graph[i].push_back({j, calDistance(getCoor[i].first, getCoor[i].second, getCoor[j].first, getCoor[j].second)});
                graph[j].push_back({i, calDistance(getCoor[i].first, getCoor[i].second, getCoor[j].first, getCoor[j].second)});
            }
        }
        prims(0);
        printMST();
        cout << endl;
    }

    return 0;
}
