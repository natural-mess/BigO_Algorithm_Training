#include <bits/stdc++.h>
using namespace std;

#define MAX 502
const int INF=1e9;
int dist[MAX][MAX];
int n;
int retVal[MAX];

void floydwarshall(int k)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][k] != INF && dist[k][j]!=INF)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
        
    }
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> dist[i][j];
        }
    }

    vector<int> deleteNode(n);
    for (int i = 0; i < n; i++)
    {
        cin >> deleteNode[i];
    }
    
    
    for (int i = n-1; i>=0; i--)
    {
        int k = deleteNode[i];

        floydwarshall(k);

        for (int x = i; x < n; x++)
        {
            for (int y = i; y < n; y++)
            {
                int u = deleteNode[x];
                int v = deleteNode[y];
                retVal[i] = dist[u][v] + retVal[i];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << retVal[i] << " ";
    }
    

    return 0;
}