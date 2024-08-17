#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<long long> a(n);
    vector<long long> b(m);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int sizeC = max(m,n);
    vector<int> c(sizeC+1, 0);
    vector<int> d(sizeC+1, 0);
    // cout << c.size() << endl;

    int st = 0;
    int count = 0;
    int indexC = 0;
    for (int i = 0; i < m; i++)
    {
        while (st<n)
        {
            long long left = a[st]-x;
            long long right = a[st]+y;
            if (b[i]>=left && b[i]<=right)
            {
                c[indexC] = i+1;
                d[indexC] = st+1;
                indexC++;
                count++;
                st++;
                break;
            }
            else
            {
                st++;
            }
        }
        
        if (st >= n)
        {
            break;
        }
    }
    
    cout << count << endl;
    if (count > 0)
    {
        for (int i = 0; i < indexC; i++)
        {
            cout << d[i] << " " << c[i] << endl;
        }
    }
    

    return 0;
}