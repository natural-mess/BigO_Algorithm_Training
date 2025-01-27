#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        set<long long> s;
        long long candy;
        for (long long i = 0; i < n; i++)
        {
            cin >> candy;
            s.insert(candy);
        }
        for (long long i = 0; i < m; i++)
        {
            cin >> candy;
            if (s.find(candy)!=s.end())
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
                s.insert(candy);
            }
        }
        
    }
    return 0;
}