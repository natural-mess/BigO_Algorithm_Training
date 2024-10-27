#include<bits/stdc++.h>
using namespace std;

char a[501][501];
bool visited[501][501];
int n, m;
pair <int, int> start, finish;

bool check(int x, int y)
{
    return (x>=1 && x<=n && y>=1 && y<=m && a[x][y]=='.' && visited[x][y]==false);
}

int main()
{
    memset(visited, false, sizeof(visited));
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    cin >> start.first >> start.second;
    cin >> finish.first >> finish.second;

    queue <pair<int,int>> qu;
    qu.push(start);
    // cout << "---" << endl;

    while(!qu.empty())
    {
        auto x = qu.front();
        qu.pop();
        int i = x.first;
        int j = x.second;
    
        // cout << i << " " << j << endl;
        vector <pair <int, int >> tmp;
        tmp = {{i,j-1}, {i,j+1}, {i-1,j}, {i+1,j}};

        for (auto k: tmp)
        {
            int ii = k.first;
            int jj = k.second;
            if (ii==finish.first && jj==finish.second)
            {
                if (a[ii][jj]=='X')
                {
                    cout << "YES";
                    return 0;
                }
                else if (a[ii][jj]=='.' && visited[ii][jj]==true)
                {
                    cout << "YES";
                    return 0;
                }
            }
            
            if (check(ii, jj))
            {
                visited[ii][jj] = true;
                // cout << "aaa: " << ii << " " << jj << endl;
                qu.push({ii,jj});
            }
        
        }
    }

    cout << "NO";

    return 0;
}