#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    int numOfTower = 0;
    int countSameHeight = 1;
    int highest = 1;

    for (int i = 0; i < n; i++)
    {
        if (i!=0 && arr[i]==arr[i-1])
        {
            countSameHeight++;
        }
        else
        {
            countSameHeight = 1;
            numOfTower++;
        }
        highest = max(highest, countSameHeight);
    }

    cout << highest << " " << numOfTower;

    return 0;
}