#include <bits/stdc++.h>
using namespace std;

int binarySearch (vector<int> &a, int left, int right, int x)
{
    int mid, result=-1;
    while(left <= right)
    {
        mid = (left+right)/2;
        if (x <= a[mid])
        {
            right = mid - 1;
        }
        else
        {
            result = a[mid];
            left = mid + 1;
        }
    }
    return result;
}

int main()
{
    int n, q;
    cin >> n;
    vector<int> girls(n);
    for (int i = 0; i < n; i++)
    {
        cin >> girls[i];
    }
    cin >> q;
    int luchu, index;
    vector<int>::iterator low_value;
    for (int i = 0; i < q; i++)
    {
        cin >> luchu;
        if (binarySearch(girls, 0, n-1, luchu) != -1)
        {
            cout << binarySearch(girls, 0, n-1, luchu) << " ";
        }
        else
        {
            cout << "X" << " ";
        }
        low_value = upper_bound(girls.begin(), girls.end(), luchu);
        if (low_value != girls.end())
        {
            cout << girls[low_value - girls.begin()] << endl;
        }
        else
        {
            cout << "X" << endl;
        }
        
    }
    return 0;

}