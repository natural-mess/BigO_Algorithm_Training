#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> singHamGrp;
        int visited[n];
        int count = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++)
        {
            int money;
            cin >> money;
            singHamGrp.push_back(money);
        }
        sort(singHamGrp.begin(), singHamGrp.end());
        for (int i = 0; i < singHamGrp.size(); i++)
        {
            int secondPerson = m - singHamGrp[i];
            visited[i] = 1;
            if (binary_search(singHamGrp.begin(), singHamGrp.end(), secondPerson)
            && visited[lower_bound(singHamGrp.begin(), singHamGrp.end(), secondPerson) - singHamGrp.begin()] == 0
            )
            {
                visited[lower_bound(singHamGrp.begin(), singHamGrp.end(), secondPerson) - singHamGrp.begin()] = 1;
                count++;
            }
            else
            {
                visited[i] = 0;
            }
        }
        cout << count << endl;
    }
    return 0;
}