#include<bits/stdc++.h>
using namespace std;

typedef struct 
{
    char maso[7];
    char ten[11];
    int namsinh;
} employee;

int main()
{
    int n;
    cin >> n;
    employee listEmployee[n];
    employee ans;
    for (int i = 0; i < n; i++)
    {
        cin >> listEmployee[i].maso >> listEmployee[i].ten >> listEmployee[i].namsinh;
    }

    ans = listEmployee[0];

    for (int i = 1; i < n; i++)
    {
        if (listEmployee[i].namsinh < ans.namsinh)
        {
            ans = listEmployee[i];
        }
        else if (listEmployee[i].namsinh == ans.namsinh)
        {
            if (strcmp(ans.maso, listEmployee[i].maso) > 0)
            {
                ans = listEmployee[i];
            }
        }
    }
    cout << ans.maso << ' ' << ans.ten << ' ' << ans.namsinh;
    
    return 0;
}
