#include <bits/stdc++.h>
using namespace std;

int binarySearch(const vector<int> &a, int left, int right, int m)
{
    long long sum;
    int result;
    while (left <= right)
    {
        sum = 0;
        int mid = (left + right)/2;

        for (auto i: a)
        {
            sum = sum + max(0, i-mid);
        }

        if (sum >= m)
        {
            result = mid;
            left = mid + 1;
        }
        else if (sum < m)
        {
            right = mid - 1;
        }
    }
    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> tree(n);
    int right;

    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
        right = max(right, tree[i]);
    }

    int res = 0;
    int left = 0;
    int h = binarySearch(tree, left, right, m);
    cout << h << endl;

    return 0;
}