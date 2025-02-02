#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long x, mot, hai, ba, result;
    cin >> n;
    priority_queue<int> q;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        q.push(x);

        if (i < 2)
        {
            cout << -1 << endl;
        }
        else
        {
            mot = q.top();
            q.pop();
            hai = q.top();
            q.pop();
            ba = q.top();
            q.pop();

            result = mot * hai * ba;
            cout << result << endl;
            q.push(mot);
            q.push(hai);
            q.push(ba);

        }
    }
    return 0;
}
