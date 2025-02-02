#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<int> a(n);
    vector<int> b(m);

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
    // cout << c.size() << endl;

    int st = 0;
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        while (st<n)
        {
            if (b[i]>=(a[st]-x) && b[i]<=(a[st]+y))
            {
                c[i+1] = st+1;
                count++;
                st++;
                break;
            }
            else 
            {
                if (a[st]+y>b[i])
                {
                    break;
                }
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
        for (int i = 0; i < c.size(); i++)
        {
            if (c[i]!=0)
            {
                cout << c[i] << " " << i << endl;
            }
        }
    }
    

    return 0;
}