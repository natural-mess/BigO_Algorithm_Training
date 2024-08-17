#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;

    vector<int> arr(12);

    for (int i = 0; i < 12; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<int>());

    int sum = 0;
    int count = 0;
    for (int i = 0; i < 12; i++)
    {
        if (sum>=k)
        {
            break;
        }
        else
        {
            sum += arr[i];
            count++;
        }
    }
    if (sum<k)
    {
        cout << -1;
    }
    else
    {
        cout << count;
    }

    return 0;
}