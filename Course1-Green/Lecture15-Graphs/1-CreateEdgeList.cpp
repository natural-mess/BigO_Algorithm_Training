#include <bits/stdc++.h>
using namespace std;

int a[1001][1001];
struct edge {
    int edgex, edgey;
};
edge arrayEdge[1000001]; // moi dinh co the co toi da n*(n-1)/2 canh

int main()
{
    int n;
    cin >> n;
    int indexEdge = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j=0; j<n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j=0; j<n; j++)
        {
            if (a[i][j]==1 && j>i)
            {
                arrayEdge[indexEdge].edgex = i;
                arrayEdge[indexEdge].edgey = j;
                indexEdge++;
            }
        }
    }
    cout << indexEdge << endl;
    for (int i = 0; i < indexEdge; i++)
    {
        cout << arrayEdge[i].edgex << " " << arrayEdge[i].edgey << endl;
    }
    
}
