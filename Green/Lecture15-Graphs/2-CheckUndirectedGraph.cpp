#include <bits/stdc++.h>
using namespace std;

int a[1001][1001];

int main()
{
    int n;
    cin >> n;
    int indexEdge = 0;
    bool flag = true;
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
            if (a[i][j]!=a[j][i])
            {
                flag = false;
                break;
            }
        }
        if (flag == false)
        {
            break;
        }
    }
    (flag == true) ? (cout << "YES") : (cout << "NO");
    return 0;
}
