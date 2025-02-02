#include <bits/stdc++.h>
using namespace std;

#define MAX 80
const int INF = 1e9;
int dist[MAX+1][MAX+1];
int party[MAX+1][MAX+1];
int c;

void floydwarshall(void)
{
    for (int k = 1; k <= c; k++)
    {
        for (int i = 1; i <= c; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                if (dist[i][j] + party[i][j] > dist[i][k] + dist[k][j] + max(party[i][k], party[k][j]))
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    party[i][j] = max(party[i][k], party[k][j]);
                }
            }
            
        }
        
    }
    
}

int main(void)
{
    int tc = 1;
    while (1)
    {
        int r, q;
        cin >> c >> r >> q;
        if (c==0 && r==0 && q==0)
        {
            break;
        }

        int partyCost[c+1];
        for (int i = 1; i <= c; i++)
        {
            cin >> partyCost[i];
        }

        for (int i = 1; i <= c; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                dist[i][j] = (i==j?0:INF);
                party[i][j] = max(partyCost[i], partyCost[j]);
            }
        }
        
        int u, v, w;
        for (int i = 0; i < r; i++)
        {
            cin >> u >> v >> w;
            dist[u][v] = dist[v][u] = w;
            party[u][v] = party[v][u] = max(partyCost[u], partyCost[v]);
        }
        
        floydwarshall();
        floydwarshall();
        cout << "Case #" << tc++ << endl;
        int c1, c2;
        for (int i = 0; i < q; i++)
        {
            cin >> c1 >> c2;
            if (dist[c1][c2] == INF)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << dist[c1][c2] + party[c1][c2] << endl;
            }
        }
        cout << endl;

    }

    return 0;
}