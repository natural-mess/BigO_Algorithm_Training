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
    vector<int> arr1 = arr;
    sort(arr.begin(), arr.end(), greater<int>());
    vector<int> rank(arr[0]);

    int count = 1;
    rank[arr[0]] = count;
    for (int i = 1; i < n; i++)
    {
        count++;
        if (arr[i-1]>arr[i])
        {
            rank[arr[i]] = count;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << rank[arr1[i]] << " ";
    }
    

    return 0;
}