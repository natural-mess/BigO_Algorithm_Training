#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,b;
    cin >> n >> b;

    queue<int> q;
    vector<int> t;
    vector<int> d;
    int ti, di;
    for (int i = 0; i < n; i++)
    {
        cin >> ti >> di;
        t.push_back(ti);
        d.push_back(di);
    }
    q.push(0);
    int i, id_q = 1;
    long long current = t[0];
    long long result[n];
    queue<int> bigger;

    while(q.size() > 0)
    {
        i = q.front();
        q.pop();
        
        result[i] = current + (long long)d[i];
        current = result[i];
        if (!(bigger.empty()) &&  q.front() == bigger.front())
        {
            i = q.front();
            q.pop();
            current = (long long)t[i];
            bigger.pop();
            result[i] = current + (long long)d[i];
            current = result[i];
        }
        while (t[id_q] < current && id_q < n)
        {
            if (q.size() < b)
            {
                q.push(id_q);
            }
            else
            {
                result[id_q] = -1;
            }
            id_q++;
        }
        if (t[id_q] == current)
        {
            q.push(id_q);
            id_q++;
        }
        if ((long long)t[id_q] > current && q.size() < b)
        {
            q.push(id_q);
            bigger.push(id_q);
            id_q++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
