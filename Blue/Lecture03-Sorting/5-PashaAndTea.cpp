#include <bits/stdc++.h>
using namespace std;

bool option (int a, int b)
{
    return a>b;
}

int main()
{
    int n, w;
    cin >> n >> w;

    vector<int> arr(n*2);

    for (int i = 0; i < n*2; i++)
    {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());

    // example 1: x + x + y + y <= 4 and y = 2x
    // example 2: 4y + 4y + 4y + 2x + 2x +2x <= 18 and 4y = 2(2x)
    // example 3: 3y + 2x <= 5 and 3y = 2*(2x)
    // double x, y;
    // double sum = 0;
    // double ratio = (double)arr[n-1]/((double)arr[n*2-1]*2.0); // x/y
    // for (int i = 0; i < 2*n; i++)
    // {
    //     if (i<n)
    //     {
    //         sum += (double)arr[i];
    //     }
    //     else
    //     {
    //         sum += (double)arr[i]*ratio;
    //     }
    // }
    // // sum = min (sum, (double)w);
    // // cout << sum;
    // y = (double)w / sum;
    // y = min(1.0, y);
    // x = y*ratio;
    // x = min(1.0, x);
    // // cout << x << " " << y << endl; 
    // double answer = 0.0;
    // for (int i = 0; i < 2*n; i++)
    // {
    //     if (i<n)
    //     {
    //         answer += (double)arr[i]*y;
    //     }
    //     else
    //     {
    //         answer += (double)arr[i]*x;
    //     }
    // }
    // 2 3
    double answer;
    answer = min((double)arr[0], (double)(arr[n])/2.0);
    answer = min(answer*3.0*(double)n, (double)w);
    cout << fixed << setprecision(6) << answer;

    return 0;
}