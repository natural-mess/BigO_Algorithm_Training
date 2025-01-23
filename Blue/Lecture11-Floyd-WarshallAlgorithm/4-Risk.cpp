#include <bits/stdc++.h>
using namespace std;

#define MAX 20
const int INF = 1e9;
int dist[MAX+1][MAX+1];

void floydwarshall()
{
    for (int k = 1; k <= 20; k++)
    {
        for (int i = 1; i <= 20; i++)
        {
            for (int j = 1; j <= 20; j++)
            {
                if (dist[i][k] != INF && dist[j][k] != INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }
}

int main(void)
{
    int t=1;
    while(1)
    {
        for (int i = 1; i <= MAX; i++)
        {
            for (int j = 1; j <= MAX; j++)
            {
                dist[i][j] = (i==j?0:INF);
            }
            
        }
        int nbNeighbor, country;
        for (int i = 1; i <= 19; i++)
        {
            if (!(cin>>nbNeighbor))
            {
                return 0;
            }
            while (nbNeighbor--)
            {
                cin >> country;
                dist[i][country] = dist[country][i] = 1;
            }
        }
        int n;
        cin >> n;
        int begin, end;
        floydwarshall();
        cout << "Test Set #" << t++ << endl;
        while(n--)
        {
            cin >> begin >> end;
            if (begin < 10 )
            {
                cout << " " << begin << " to ";
            }
            else
            {
                cout << begin << " to ";
            }
            if (end < 10)
            {
                cout << " " << end << ": ";
            }
            else
            {
                cout << end << ": ";
            }

            cout << dist[begin][end] << endl;
        }
        cout << endl;
    }

    return 0;
}