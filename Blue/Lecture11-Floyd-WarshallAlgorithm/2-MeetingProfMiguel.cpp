#include <bits/stdc++.h>
using namespace std;

#define MAX 28
const int INF = 1e9;
int distY[MAX][MAX];
int distM[MAX][MAX];

void floydWarshall(int dist[MAX][MAX])
{
    for (int k = 0; k < MAX; k++)
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                if (dist[i][k] < INF && dist[k][j] < INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
            
        }
        
    }
    
}

int main(void)
{
    int n;
    while (cin>>n, n!=0)
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                distY[i][j] = (i == j ? 0 : INF);
                distM[i][j] = (i == j ? 0 : INF);
            }
        }

        char age, way, s, t;
        int w;
        for (int i = 0; i < n; i++)
        {
            cin >> age >> way >> s >> t >> w;
            if (age == 'Y')
            {
                distY[s-'A'][t-'A'] = min(distY[s-'A'][t-'A'], w);
                if (way == 'B')
                {
                    distY[t-'A'][s-'A'] = min(distY[t-'A'][s-'A'], w);
                }
            }
            else
            {
                distM[s-'A'][t-'A'] = min(distM[s-'A'][t-'A'], w);
                if (way == 'B')
                {
                    distM[t-'A'][s-'A'] = min(distM[t-'A'][s-'A'], w);
                }
            }
        }
        char young, old;
        cin >> young >> old;
        floydWarshall(distY);
        floydWarshall(distM);

        int minDist = INF;
        vector<char> res;

        for (int i = 0; i < MAX; i++)
        {
            int total = distY[young-'A'][i] + distM[old-'A'][i];

            if (total < minDist)
            {
                minDist = total;
                res.clear();
                res.push_back(i+'A');
            }
            else if (total == minDist)
            {
                res.push_back(i+'A');
            }
        }

        if (minDist == INF) 
        {
            cout << "You will never meet.";
        }
        else
        {
            cout << minDist;
            for (char point:res)
            {
                cout << " " << point;
            }
            
        }
        cout << endl;
    }

    return 0;
}