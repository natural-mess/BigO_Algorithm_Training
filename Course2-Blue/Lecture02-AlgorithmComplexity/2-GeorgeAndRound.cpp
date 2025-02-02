/*
George and Round - L2
sort(a)
sort(b)

st = 0

for i : 0 -> n - 1
	while (true)
	{
		if (b[st] >= a[i])
			break;
		else st++;
	}
	st++;
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
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

    int flag = 0;
    int st = 0;
    // for (int i = 0; i < m; i++)
    // {
    //     while (b[i] > a[st] && st < n)
    //     {
    //         st++;
    //     }
    //     if (b[i] == a[st] && flag == 0)
    //     {
    //         flag = 1;
    //     }
    // }

    int i;
    for (i = 0; i < n; i++)
    {
        while (b[st] < a[i] && st < m)
        {
            st++;
        }
        if (st>=m)
        {
            flag = 1;
            break;
        }
        else
        {
            st++;
        }
    }
    
    (flag == 1) ? (cout << n-i) : (cout << 0);

    return 0;
    
}