#include <bits/stdc++.h>
using namespace std;

int a[1001][1001];
int b[1001];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    bool result = true;
    if (n>2)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 1)
                {
                    b[i]++;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (b[i]%2!=0)
            {
                result = false;
                break;
            }
        }
    }
    else
    {
        result = false;
    }

    (result==true)?(cout<<"YES") : (cout<<"NO");
}
