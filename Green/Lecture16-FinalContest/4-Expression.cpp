#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    int result[6];
    result[0] = a + b + c;
    result[1] = a * b * c;
    result[2] = a + b * c;
    result[3] = a * b + c;
    result[4] = (a + b) * c;
    result[5] = a * (b + c);
    int max = result[0];
    for (int i = 1; i < 6; i++)
    {
        if (result[i]>max)
        {
            max = result[i];
        }
    }
    cout << max;

    return 0;
}