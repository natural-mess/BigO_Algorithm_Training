#include <bits/stdc++.h>
using namespace std;

bool visited[100005];

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int start = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (i>0 && arr[i] == arr[start])
        {
            start++;
        }
        if (visited[arr[i]] == false)
        {
            count++;
            visited[arr[i]] = true;
        }
        if (count == k)
        {
            while (arr[start+1]==arr[start] && start+1<=i)
            {
                start++;
            }
            cout << start+1 << " " << i+1;
            return 0;
        }
    }
     cout << -1 << " " << -1;
    return 0;
}
