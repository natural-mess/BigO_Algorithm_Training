#include <bits/stdc++.h>
using namespace std;

#define MAX 48
const int INF = 1e9;
int dist[MAX+1][MAX+1];

void floydwarshall(void)
{
    for (int k = 0; k <= MAX; k++)
    {
        for (int i = 0; i <= MAX; i++)
        {
            for (int j = 0; j <= MAX; j++)
            {
                if (i<=k && k<=j)
                {
                    dist[i][j] = max(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
            
        }
        
    }
    
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int s, e, c;

        for (int i = 0; i <= MAX; i++)
        {
            for (int j = 0; j <= MAX; j++)
            {
                dist[i][j] = 0;
            }
            
        }
        

        for (int i = 0; i < n; i++)
        {
            cin >> s >> e >> c;
            dist[s][e] = max(dist[s][e], c);
        }
        floydwarshall();
        cout << dist[0][MAX] << endl;

    }
    return 0;
}