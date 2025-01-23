#include <bits/stdc++.h>
using namespace std;

#define MAX 52
const int INF = 1e9;
string graph[MAX];
int dist[MAX][MAX];

void floydWarshall(int M)
{
    for (int k = 0; k < M; k++)
    {
        for (int i = 0; i < M; i++)
        {
            if (dist[i][k]==INF)
            {
                continue;
            }
            for (int j = 0; j < M; j++)
            {
                if (dist[k][j]!=INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int M;
        
        string input;
        cin >> input;
        M = input.length();
        for (int i=0; i<M; i++)
        {
            if (i==0)
            {
                graph[i] = input;
            }
            else
            {
                cin >> input;
                graph[i] = input;
            }

            for (int j = 0; j < M; j++)
            {
                if (i!=j)
                {
                    if (graph[i][j] == 'Y')
                    {
                        dist[i][j] = 1;
                    }
                    else
                    {
                        dist[i][j] = INF;
                    }
                }
                else
                {
                    dist[i][j] = 0;
                }
            }
        }
        floydWarshall(M);

        int index=0, possibleFr=0, friendCount=0;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (dist[i][j] == 2)
                {
                    friendCount++;
                }
            }
            if (friendCount > possibleFr)
            {
                possibleFr = friendCount;
                index = i;
            }
            friendCount=0;
        }
        cout << index << " " << possibleFr << endl;
        for (int i = 0; i < M; i++)
        {
            graph[i].clear();
            for (int j = 0; j < M; j++)
            {
                dist[i][j] = INF;
            }
            
        }
        
    }

    return 0;
}

