#include <bits/stdc++.h>
using namespace std;

#define MAX 32
const int INF = 1e9;
vector<vector<double>> dist;
int n;

void floydwarshall(void)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = max(dist[i][j], dist[i][k]*dist[k][j]);
            }
            
        }
        
    }
    
}

int main(void)
{
    int tc=1;
    while (cin>>n, n!=0)
    {
        vector<string> currency(n);
        dist = vector<vector<double>>(n, vector<double>(n, 0.0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = (i == j ? 1.0 : 0.0);
            }
        }
        

        for (int i = 0; i < n; i++)
        {
            cin >> currency[i];
        }

        int m;
        cin >> m;
        
        for (int i = 0; i < m; i++)
        {
            string s,t;
            double rate;
            cin >> s >> rate >> t;
            int src = find(currency.begin(), currency.end(), s) - currency.begin();
            int target = find(currency.begin(), currency.end(), t) - currency.begin();
            dist[src][target] = rate;
        }
        
        cout << "Case " << tc++ << ": ";
        floydwarshall();
        bool res = false;
        for (int i = 0; i < n; i++)
        {
            if (dist[i][i] > 1.0)
            {
                res = true;
                break;
            }
        }
        cout << (res?"Yes":"No") << endl;
    }

    return 0;
}