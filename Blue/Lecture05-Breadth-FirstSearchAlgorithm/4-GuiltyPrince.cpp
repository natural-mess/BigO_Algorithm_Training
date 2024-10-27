#include<bits/stdc++.h>
using namespace std;

int w, h;
bool visited[21][21];
char a[21][21];

bool check(int x, int y)
{
    return (a[x][y]=='.' && visited[x][y]==false);
}

int main()
{
    int t;
    cin >> t;
    int caseCount = 1;

    while (t--)
    {
        cin >> w >> h;

        pair <int, int> start;

        for (int i = 0; i < 21; i++)
        {
            for (int j = 0; j < 21; j++)
            {
                a[i][j] = 0;
                visited[i][j] = false;
            }
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> a[i][j];
                visited[i][j] = false;
                if (a[i][j] == '@')
                {
                    start.first = i;
                    start.second = j;
                }
            }
        }

        queue <pair <int, int>> q;
        q.push(start);
        int count = 0;
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
                    count++;
                    visited[ii][jj] = true;
                    q.push({ii,jj});
                }
            }
        }
        cout << "Case " << caseCount++ << ": " << count+1 << endl;
    }

    return 0;
}
