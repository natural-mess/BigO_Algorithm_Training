#include <bits/stdc++.h>
using namespace std;

#define MAX 102

int t, r ,c;
char a[MAX][MAX];
bool visited[MAX][MAX];
const char sample[] = "ALLIZZWELL";
int indexSample = 0;

bool check (int i, int j, int inds)
{
    return (i>=0 && i<r && j>=0 && j<c && (a[i][j]==sample[inds]) && visited[i][j] == false);
}

bool dfs (int i, int j, int indexS)
{
    if (sample[indexS] != a[i][j])
        return false;
    if (indexS == 9 && sample[indexS] == a[i][j])
        return true;
    vector <pair<int,int>> tmp = {{i,j+1}, {i,j-1}, {i+1,j}, {i+1, j+1}, {i+1, j-1}, {i-1,j}, {i-1, j+1}, {i-1, j-1}};
    for (auto x: tmp)
    {
        int ii = x.first;
        int jj = x.second;
        int ret = 0;
        if (check(ii, jj, indexS + 1))
        {
            visited[ii][jj] = true;
            ret = dfs(ii, jj, indexS + 1);
            visited[ii][jj] = false;

            if (ret == true)
                return true;
        }
    }
    return false;
}

int main()
{
//    freopen("a.inp", "r", stdin);
    cin >> t;
    while (t--)
    {

        cin >> r >> c;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> a[i][j];
                visited[i][j] = false;
            }
        }
        indexSample = 0;
        int ret = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {

                if (a[i][j] == sample[0] && !ret)
                {
                    ret = dfs(i, j, indexSample);
                  	if (ret == 1)
                    	break;
                  	for (int h = 0; h < r;h++)
                        for (int k = 0; k < c; k++)
                            visited[h][k] = false;
                }
            }
        }

        (ret == 1) ? (cout << "YES\n") : (cout << "NO\n");
        ret = 0;
    }

    return 0;
}
