#include<bits/stdc++.h>
using namespace std;
char a[52][52];
int visited[52][52], flag[52 * 52];
int n, m, k;
bool check(int i, int j)
{
    return (i >= 1 && i <= n && j >= 1 && j <= m && a[i][j] == '.' && visited[i][j] == -1);
}
void dfs(int i, int j, int cum)
{
    visited[i][j] = cum;
    vector < pair <int, int> > tmp = {{i - 1, j}, {i, j - 1}, {i + 1, j}, {i, j + 1}};
    for (auto x: tmp)
    {
        int ii = x.first;
        int jj = x.second;
        if (check(ii, jj))
            dfs(ii, jj, cum);
    }
}
int main()
{
//    freopen("a.inp", "r", stdin);
    cin >> n >> m >> k;
 
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            visited[i][j] = -1;
        }
    for (int i = 1; i <= n; ++i)
    {
        if (check(i, 1))
            dfs(i, 1, 0);
        if (check(i, m))
            dfs(i, m, 0);
    }
    for (int i = 1; i <= m; ++i)
    {
        if (check(1, i))
            dfs(1, i, 0);
        if (check(n, i))
            dfs(n, i, 0);
    }
    int n_cum = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            if (check(i, j))
            {
                ++n_cum;
                dfs(i, j, n_cum);
            }
    }
    vector <pair <int, int> > number_water; // so o cua ho, id ho
    for (int i = 1; i <= n_cum; ++i)
    {
        int cnt = 0; // số ô của hồ i
        for (int j = 1; j <= n; ++j)
            for (int h = 1; h <= m; ++h)
                if (visited[j][h] == i)
                    ++cnt;
        number_water.push_back({cnt, i});
 
    }
    sort(number_water.begin(), number_water.end());
    if ((number_water.size()) <= k)
    {
        cout << 0 << '\n';
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
                cout << a[i][j];
            cout << '\n';
        }
    }
    else
    {
        int ans = 0;
        for (int i = 0; i < (number_water.size()) - k; ++i)
        {
            ans += number_water[i].first;
            flag[number_water[i].second] = true;
        }
        cout << ans << '\n';
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
                if (flag[visited[i][j]] == true)
                    cout << "*";
                else cout << a[i][j];
            cout << '\n';
        }
    }
}
 