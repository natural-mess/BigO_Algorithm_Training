#include<bits/stdc++.h>
using namespace std;

int main()
{
    while(1)
    {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0) 
        {
            break;
        }

        int a[n][m];
        bool visited[n][m];
        memset(visited, false, sizeof(visited));
        int counter [n*m+1];
        memset(counter, 0, sizeof(counter));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }

        queue <pair<int,int>> qu;
        int res = 0;
        int countTotal = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j]==1 && visited[i][j] == false)
                {
                    countTotal++;
                    qu.push({i,j});
                    
                    while (!qu.empty())
                    {
                        auto x = qu.front();
                        qu.pop();
                        int ii = x.first;
                        int jj = x.second;

                        vector <pair <int, int >> tmp;
                        tmp = {{ii,jj}, {ii,jj-1}, {ii,jj+1}, {ii-1,jj}, {ii+1,jj}};
                        for (auto k: tmp)
                        {
                            int iii = k.first;
                            int jjj = k.second;
                            if (iii>=0 && iii<n && jjj>=0 && jjj<m && a[iii][jjj] == 1 && visited[iii][jjj]==false)
                            {
                                visited[iii][jjj] = true;
                                qu.push({iii,jjj});
                                res++;
                            }
                        }
                    }
                    counter[res]++;
                    res=0;
                }
            }
        }
        cout << countTotal << endl;
        for (int i = 1; i <= n*m; i++)
        {
            if (counter[i]>0)
            {
                cout << i << " " <<counter[i] << endl;
            }
            
        }
    }

    return 0;
}