#include<bits/stdc++.h>
using namespace std;

char a[251][251];
bool visited[251][251];
int n, m;
int sheep, wolf;
vector<int> nbSheep, nbWolf;

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

    queue <pair<int,int>> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i==1 || i==n || j==1 || j==m)
            {
                if (a[i][j]!='#')
                {
                    q.push({i,j});
                    while (!q.empty())
                    {
                        auto x = q.front();
                        q.pop();
                        int ii = x.first;
                        int jj = x.second;

                        vector<pair<int, int>> tmp;
                        tmp = {{ii, jj}, {ii, jj - 1}, {ii, jj + 1}, {ii - 1, jj}, {ii + 1, jj}};
                        for (auto k : tmp)
                        {
                            int iii = k.first;
                            int jjj = k.second;
                            if (iii >= 1 && iii <= n && jjj >= 1 && jjj <= m && visited[iii][jjj] == false && a[iii][jjj]!='#')
                            {
                                visited[iii][jjj] = true;
                                q.push({iii, jjj});
                                if (a[iii][jjj] == 'k')
                                {
                                    sheep++;
                                }
                                else if (a[iii][jjj] == 'v')
                                {
                                    wolf++;
                                }
                            }
                        }
                    }
                }
            }
            nbSheep.push_back(sheep);
            nbWolf.push_back(wolf);
            sheep = 0;
            wolf = 0;
        }
        
    }

    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (visited[i][j] == false)
            {
                q.push({i,j});
                while (!q.empty())
                {
                    auto x = q.front();
                    q.pop();
                    int ii = x.first;
                    int jj = x.second;

                    vector<pair<int, int>> tmp;
                    tmp = {{ii, jj}, {ii, jj - 1}, {ii, jj + 1}, {ii - 1, jj}, {ii + 1, jj}};
                    for (auto k : tmp)
                    {
                        int iii = k.first;
                        int jjj = k.second;
                        if (iii >= 1 && iii <= n && jjj >= 1 && jjj <= m && visited[iii][jjj] == false)
                        {
                            visited[iii][jjj] = true;
                            if (a[iii][jjj] == '.')
                            {
                                q.push({iii, jjj});
                            }
                            else if (a[iii][jjj] == 'k')
                            {
                                q.push({iii, jjj});
                                sheep++;
                            }
                            else if (a[iii][jjj] == 'v')
                            {
                                q.push({iii, jjj});
                                wolf++;
                            }
                        }
                    }
                }
            }
            if (sheep > wolf)
            {
                wolf = 0;
            }
            else
            {
                sheep = 0;
            }
            nbSheep.push_back(sheep);
            nbWolf.push_back(wolf);
            sheep = 0;
            wolf = 0;
        }
    }
    sheep = 0;
    wolf = 0;
    for (int i = 0; i < nbSheep.size(); i++)
    {
        if (nbSheep[i]>0)
            sheep += nbSheep[i];
    }
    for (int i = 0; i < nbWolf.size(); i++)
    {
        if (nbWolf[i]>0)
            wolf += nbWolf[i];
    }
    
    cout << sheep << " " << wolf;

    return 0;
}