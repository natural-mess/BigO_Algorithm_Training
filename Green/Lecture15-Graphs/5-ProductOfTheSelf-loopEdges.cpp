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
    int product = 1;
    int count =0 ;
    for (int i = 0; i < m; i++)
    {
        if (a[i].edgex == a[i].edgey)
        {
            count++;
        }
    }
    if (count == 0)
    {
        cout << -1;
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            if (a[i].edgex == a[i].edgey)
            {
                product = (product * a[i].edgez)%(int)(pow(10,6)+7);
            }
        }
        cout << count << " " << product;
    }

    return 0;
}
