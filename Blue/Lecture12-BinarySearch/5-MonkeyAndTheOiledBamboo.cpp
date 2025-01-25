#include <bits/stdc++.h>
using namespace std;

int binarySearch(const vector<int> &a, int left, int right)
{
    int mid, res, k;
    bool flag;
    while (left <= right)
    {
        mid = (left+right)/2;
        k = mid;
        flag = true;
        for (auto i: a)
        {
            if (i > k)
            {
                flag = false;
                break;
            }
            else if (i == k)
            {
                k--;
            }
        }

        if (flag)
        {
            res = mid;
            right = mid-1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return res;
}


int main()
{
    int t;
    cin >> t;
    int tc = 1;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> r(n);
        int inputH, prevInputH, maxGap = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> inputH;
            if (i == 0)
            {
                r[i] = inputH;
            }
            else
            {
                r[i] = inputH-prevInputH;
            }
            prevInputH = inputH;
            if (r[i] > maxGap)
            {
                maxGap = r[i];
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << r[i] << " ";
        // }
        cout << "Case "<< tc++ << ": ";
        int left = maxGap;
        int right = 10e7+1;
        cout << binarySearch(r, left, right) << endl;
    }
    return 0;
}