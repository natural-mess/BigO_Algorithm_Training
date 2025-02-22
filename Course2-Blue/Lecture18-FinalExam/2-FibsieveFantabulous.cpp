#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, tc=1;
    long long s;
    cin >> t;
    long long row, col;
    for (int i = 0; i < t; i++)
    {
        cin >> s;
        long long squaredRoot = ceil(sqrt(s*1.0));
        long long lackings = squaredRoot*squaredRoot - s;

        if (lackings < squaredRoot)
        {
            col = squaredRoot;
            row = lackings + 1;
        }
        else
        {
            row = squaredRoot;
            col = s - (squaredRoot - 1) * (squaredRoot - 1);
        }
        if (squaredRoot % 2 == 0)
        {
            swap(row, col);
        }
        cout << "Case " << tc++ << ": " << row << " " << col << endl;
    }
    
    

    return 0;
}