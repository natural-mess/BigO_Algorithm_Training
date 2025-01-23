#include <bits/stdc++.h>
using namespace std;

#define MAX 101
const double INF = 1e9;
double dist[MAX][MAX];
int n;

void floydwarshall(void)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != INF && dist[k][j]!=INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
            
        }
        
    }
    
}

int main()
{
    int tc=1;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;

        int x[MAX], y[MAX];

        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                dist[i][j] = (i==j)?0:INF;
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i];
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                double distance = sqrt(pow(x[j]-x[i],2) + pow(y[j]-y[i], 2));
                if (abs(distance) <= 10)
                {
                    dist[i][j] = distance;
                }
            }
        }
        
        cout << "Case #" << tc++ << ":" << endl;
        floydwarshall();

        double retVal=0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                retVal = max(retVal, dist[i][j]);
            }
            
        }
        

        if (retVal==INF)
        {
            cout << "Send Kurdy" << endl;
        }
        else
        {
            cout << fixed << setprecision(4) << retVal << endl;
        }
        cout << endl;

    }
    return 0;
}