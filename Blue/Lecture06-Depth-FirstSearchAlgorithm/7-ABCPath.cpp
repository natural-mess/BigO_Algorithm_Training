#include <bits/stdc++.h>
using namespace std;

#define MAX 52
#define charA 65

int w, h;
char a[MAX][MAX];
int visited[MAX][MAX];
vector <int> stor;

bool check (int i, int j, int track)
{
    return (i>=0 && i<w && j>=0 && j<h && (a[i][j]==(charA+track)) && visited[i][j] == 0);
}

void dfs (int i, int j, int* track)
{
    visited[i][j]++;
    vector <pair<int,int>> tmp = {{i-1,j}, {i,j-1}, {i+1,j}, {i,j+1}, {i+1, j+1}, {i-1, j+1}, {i+1, j-1}, {i-1, j-1}};
    for (auto x: tmp)
    {
        int ii = x.first;
        int jj = x.second;
        if (check(ii, jj, *track))
        {
            (*track)++;
            dfs(ii, jj, track);
        }
    }
}

int main()
{
    int caseC = 1;
    while (1)
    {
        cin >> w >> h;
        if (w==0 && h==0)
        {
            break;
        }

        pair <int, int> start;
        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < h; j++)
            {
                cin >> a[i][j];
                visited[i][j] = 0;
            }
        }
        int track = 1;
        // dfs(start.first, start.second, &track);
        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < h; j++)
            {
                if (a[i][j] == 65)
                {
                    dfs(i, j, &track);
                    stor.push_back(track);
                }
                track = 1;
            }
        }
        sort (stor.begin(), stor.end(), greater<int>());
        cout << "Case " << caseC << ": " << stor[0] << endl ;
        caseC++;
        
    }
    return 0;
}
