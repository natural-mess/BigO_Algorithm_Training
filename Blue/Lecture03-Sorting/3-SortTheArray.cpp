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
    vector<int> arrSorted(n);
    arrSorted = arr;
    sort(arrSorted.begin(), arrSorted.end());
    int begin = -1, end;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arrSorted[i])
        {
            begin = i;
            break;
        }
    }
    if (begin == -1)
    {
        cout << "yes" << endl << 1 << " " << 1;
        return 0;
    }
    int st = n-1;
    // while (st>=0)
    // {
    //     if (arr[begin] == arrSorted[st])
    //     {
    //         end = st;
    //         break;
    //     }
    //     st--;
    // }
    while (st>=0)
    {
        if (arr[st] != arrSorted[st])
        {
            end = st;
            break;
        }
        st--;
    }

    int indexBegin = begin;
    int indexEnd = end;
    while (indexBegin <= end || indexEnd >= begin)
    {
        if (arr[indexBegin] != arrSorted[indexEnd])
        {
            cout << "no";
            return 0;
            // break;
        }
        indexBegin++;
        indexEnd--;
    }

    cout << "yes" << endl << begin+1 << " " << end+1;

    return 0;
}