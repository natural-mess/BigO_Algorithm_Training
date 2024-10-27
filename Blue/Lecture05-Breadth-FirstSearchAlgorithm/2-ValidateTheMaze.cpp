#include<bits/stdc++.h>
using namespace std;

int n, m;
bool visited[21][21];
char a[21][21];

bool check(int x, int y)
{
    return (x>=1 && x<=m && y>=1 && y<=n && a[x][y]=='.' && visited[x][y]==false);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> m >> n;

        pair <int, int> start;
        int cham = 0;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
                visited[i][j] = false;
                if (i==1 || i==m || j==1 || j==n)
                {
                    if (a[i][j] == '.')
                    {
                        cham++;
                        start = {i, j};
                    }
                }
            }
        }
        if (cham!=2)
        {
            cout << "invalid" << endl;
            continue;
        }
        queue <pair <int, int>> q;
        q.push(start);
        int res = 0;
        visited[start.first][start.second] = true;

        while (!q.empty())
        {
            auto x = q.front();
            q.pop();
            int i = x.first;
            int j = x.second;

            vector <pair <int, int >> tmp;
            tmp = {{i,j-1}, {i,j+1}, {i-1,j}, {i+1,j}};
            for (auto i: tmp)
            {
                int ii = i.first;
                int jj = i.second;
                if (check(ii, jj))
                {
                    if (ii==1 || ii==n || jj==1 || jj==n)
                    {
                        res = 1;
                    }
                    visited[ii][jj] = true;
                    q.push({ii,jj});
                }
            }
        }
        if (res == 0)
        {
            cout << "invalid\n";
        }
        else
        {
            cout << "valid\n";
        }
    }

    return 0;
}
