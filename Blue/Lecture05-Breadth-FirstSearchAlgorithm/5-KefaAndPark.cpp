#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n, m;
    cin >> n >> m;

    int cat[n+1];
    char visited[n+1];
    
    int countCat = 0;
    vector <int> graph[n+1];

    for (int i = 1; i <= n; i++)
    {
        cin >> cat[i];
        visited[i] = -1;
    }

    int x, y;
    for (int i = 1; i <= n-1; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    queue <int> qu;
    qu.push(1);
    if (cat[1] == 1)
    {
        visited[1] = 1;
    }
    else
    {
        visited[1] = 0;
    }
    
    int quElement;
    int index = 1;
    while(!qu.empty())
    {
        quElement = qu.front();
        qu.pop();

        for (auto i: graph[quElement])
        {
            if (visited[i] < 0)
            {   
                if (cat[i]==1)
                {
                    visited[i] = visited[quElement] + 1;
                }
                else
                {
                    visited[i] = 0;
                }
                if (visited[i]<=m)
                {
                    qu.push(i);
                }
                
            }
        }
    }
    int res = 0;
    for (int i = 2; i <= n; i++)
    {
        if (graph[i].size() == 1)
        {
            if (visited[i] <= m && visited[i]>-1)
            {
                res++;
            }
        }
    }
    cout<< res;

    return 0;
}