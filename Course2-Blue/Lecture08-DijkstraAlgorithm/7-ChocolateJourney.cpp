// tim duong di ngan nhat nhu binh thuong tu diem A den diem B, neu dist[B] < x thi ok, neu khong in ra -1
// neu khong co duong di thi dist[B] la vo cung
// chay dijkstra tu B den k thanh pho co sô cô la, dam bao no ngan nhat, nho hon x va co duong di, sau do cong cho tu tp co socola do toi A

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000002
const int INF = 1e9;
/**
 * vector<vector<pair<int,int>>> graph;
Định nghĩa graph là một biến:
vector<vector<pair<int,int>>>:
vector<> là một container động trong C++ (tương tự như mảng động).
vector<vector<pair<int,int>>> nghĩa là một vector mà mỗi phần tử của nó lại là một vector.
pair<int,int>: Là một cặp giá trị kiểu int. Thường được sử dụng để lưu thông tin dạng (đỉnh, trọng số) trong biểu diễn đồ thị có trọng số.
Tóm lại:
graph là một vector hai chiều.
graph[i] là một vector các pair<int,int>, đại diện cho danh sách các đỉnh kề với đỉnh i.
Mỗi phần tử trong graph[i] là một cặp (v, w), trong đó:
v là đỉnh kề với đỉnh i.
w là trọng số của cạnh nối từ i đến v.
 */
vector<vector<pair<int,int>>> graph;
int path[MAX];

struct option
{
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) const
    {
        return a.second > b.second;
    }
};

vector<int> dijkstra(int s/*, int d*/)
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

        // if (u == d) 
        // { 
        //     break; 
        // }

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
    int N, M, k, x;
    cin >> N >> M >> k >> x;
    vector<int> distA(MAX, INF);
    vector<int> distB(MAX, INF);
    int chocolateCity[k];

    for (int i = 0; i < k; i++)
    {
        cin >> chocolateCity[i];
    }

    graph = vector<vector<pair<int,int>>>(N+1, vector<pair<int,int>>());

    int u, v, d;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> d;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }
    int start, dest;
    cin >> start >> dest;
    
    distA = dijkstra(start);
    distB = dijkstra(dest);

    int retVal = INF;

    for (int i = 0; i < k; i++)
    {
        if (distB[chocolateCity[i]] <= x)
        {
            retVal = min(retVal, distA[chocolateCity[i]] + distB[chocolateCity[i]]);
        }
    }
    (retVal >= INF) ? (cout << -1) : (cout << retVal);
    
    return 0;
}
