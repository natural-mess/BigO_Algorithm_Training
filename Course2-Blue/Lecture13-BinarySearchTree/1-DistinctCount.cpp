#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        set<int> s;
        cin >> n >> x;
        int k;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            s.insert(k);
        }
        if (s.size() > x)
        {
            cout << "Average" << endl;
        }
        else if (s.size() == x)
        {
            cout << "Good" << endl;
        }
        else
        {
            cout << "Bad" << endl;
        }
    }
}