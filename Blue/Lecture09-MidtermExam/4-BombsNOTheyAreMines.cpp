#include<bits/stdc++.h>
using namespace std;

#define MAX_R 1002
#define MAX_C 1002

int a[MAX_R][MAX_C];
bool visited[MAX_R][MAX_C];
pair<int, int> path[MAX_R][MAX_C];

int main()
{
    while(1)
    {
        int r, c;
        cin >> r >> c;

        if (r == 0 && c == 0) 
        {
            break;
        }

        memset(visited, false, sizeof(visited));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                path[i][j].first = -1;
                path[i][j].second = -1;
            }
        }

        pair<int, int> start;
        pair<int, int> end;

        int rows, columns, bomb;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                a[i][j] = 0;
            }
        }
        int index_rows;
        cin >> index_rows;
        while (index_rows--)
        {
            cin >> rows;
            cin >> bomb;
            while (bomb--)
            {
                cin >> columns;
                a[rows][columns] = 1;
            }
        }
        
        // for (int i = 0; i < r; i++)
        // {
        //     for (int j = 0; j < c; j++)
        //     {
        //         cout << a[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        cin >> start.first >> start.second;
        cin >> end.first >> end.second;

        if (start.first==end.first && start.second==end.second)
        {
            cout << 1 << endl;
            continue;
        }

        queue<pair<int, int>> qu;
        int res = 0;
        qu.push({start.first, start.second});
        visited[start.first][start.second] = true;

        while (!qu.empty())
        {
            auto x = qu.front();
            qu.pop();
            int ii = x.first;
            int jj = x.second;
            if (ii==end.first && jj==end.second)
            {
                break;
            }
            vector<pair<int, int>> tmp;
            tmp = {{ii, jj - 1}, {ii, jj + 1}, {ii - 1, jj}, {ii + 1, jj}};
            for (auto k : tmp)
            {
                int iii = k.first;
                int jjj = k.second;
                if (iii >= 0 && iii < r && jjj >= 0 && jjj < c && a[iii][jjj] == 0 && visited[iii][jjj] == false)
                {
                    visited[iii][jjj] = true;
                    qu.push({iii, jjj});
                    path[iii][jjj].first = ii;
                    path[iii][jjj].second = jj;
                }
            }
        }
        vector<pair<int, int>> b;

        // cout << endl;
        int x = end.first, y = end.second;
        int first=path[x][y].first, second=path[x][y].second;
        while (x != -1 && y != -1)
        {
            b.push_back({x, y});
            first = path[x][y].first;
            second = path[x][y].second;
            x = first;
            y = second;
            // cout << x << " " << y << endl;
        }
        // cout << endl;
        // b.push_back({start.first, start.second});
        cout << b.size()-1 << endl;

        // for (int i = 0; i < b.size(); i++)
        // {
        //     cout << b[i].first << " " << b[i].second << endl;
        // }
    }
    return 0;
}