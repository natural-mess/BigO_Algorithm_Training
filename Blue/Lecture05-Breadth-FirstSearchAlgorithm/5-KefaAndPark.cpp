#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100001];

queue <int> qu;
bool visited[100001];
int d[100001];
vector<int> cat[100001];

int main()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    int indexA = 1;
    int a[n];

    int countCat = 0;

    for (int i = 1; i <= n; ++i)
    {
        visited[i] = false;
        d[i] = -1;
        graph[i].clear();
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i==1 && a[i]==1)
        {
            countCat++;
            indexA++;
        }
    }

    for (int i = 0; i < (n-1); i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    // dinh 1 la goc
    // d[1] = 0;
    qu.push(1);
    visited[1] = true;
    bool signal = false;

    while (!qu.empty())
    {

        int j = qu.front();
        qu.pop();
        for (auto i: graph[j])
        {
            if (visited[i] == false)
            {
                visited[i] = true;
                if (i==indexA && a[indexA]==1)
                {
                    countCat++;
                }
                if (countCat<=m)
                {
                    qu.push(i);
                }
                
            }
            indexA++;
        }
        countCat = 0;
    }

    return 0;
}