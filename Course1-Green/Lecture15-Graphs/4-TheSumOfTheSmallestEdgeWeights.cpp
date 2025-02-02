#include <bits/stdc++.h>
using namespace std;

struct edge {
    int edgex, edgey, edgez;
};

edge a[1000001];

int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[i].edgex = x;
        a[i].edgey = y;
        a[i].edgez = z;
    }
    int min = a[0].edgez;
    for (int i = 1; i < m; i++)
    {
        if (a[i].edgez < min)
        {
            min = a[i].edgez;
        }
    }
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        if (a[i].edgez == min)
        {
            sum = sum + a[i].edgez;
        }
    }
    cout << sum;
}
