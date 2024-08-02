#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> a[i][j];
        }
    }
    bool result = true;
    for (int i = 0; i < 4; i++)
    {
        if (a[i][3] == 1)
        {
            int sum = 0;
            for (int j=0; j<3; j++)
            {
                sum = sum + a[i][j];
            }
            if (sum>=1)
            {
                result = false;
                break;
            }
            else
            {
                if (a[(i+1)%4][0] == 1 || a[(i+2)%4][1] == 1 || a[(i+3)%4][2] == 1)
                {
                    result = false;
                    break;
                }
            }
        }
    }
    (result==true) ? (cout << "NO") : (cout<< "YES");

    return 0;
}