#include <bits/stdc++.h>
using namespace std;

#define BORING_LENGTH 15
#define FULL_MATCH 90

int main()
{
    int n;
    cin >> n;
    vector<int> interesting;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        interesting.push_back(x);
    }

    int index=0;
    int count15=0;
    int i;
    for (i = 0; i < FULL_MATCH; i++)
    {
        if (i == interesting[index])
        {
            count15=0;
            index++;
        }
        count15++;
        if (count15 > BORING_LENGTH)
        {
            break;
        }
    }
    
    cout << i;

    return 0;
}