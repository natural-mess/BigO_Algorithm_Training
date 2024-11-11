#include <bits/stdc++.h>
using namespace std;

struct royTrending
{
    long long id, z_old, z_new, z_change, p, l, c, s;
};

struct Compare {
    bool operator()(royTrending const& p1, royTrending const& p2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        if (p1.z_change == p2.z_change)
        {
            return (p1.id < p2.id);
        }
        else
        {
            return (p1.z_change < p2.z_change);
        }
    }
};

int main()
{
    int n;
    cin >> n;
    priority_queue<royTrending, vector<royTrending>, Compare> q;
    royTrending arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].id >> arr[i].z_old >> arr[i].p >> arr[i].l >> arr[i].c >> arr[i].s;
        arr[i].z_new = arr[i].p*50 + arr[i].l*5 + arr[i].c*10 + arr[i].s*20;
        arr[i].z_change = arr[i].z_new - arr[i].z_old;
        q.push(arr[i]);
    }
    
    int counter = 0;
    while (counter < 5)
    {
        royTrending p = q.top();
        q.pop();
        cout << p.id << " " << p.z_new << "\n";
        counter ++;
    }

    return 0;
}
