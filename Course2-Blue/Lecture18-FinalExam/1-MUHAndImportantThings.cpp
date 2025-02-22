#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> m;
    vector<int> task(n);
    for (int i = 0; i < n; i++)
    {
        cin >> task[i];
    }
    
    vector<pair<int,int>> taskPos;
    for (int i = 0; i < n; i++)
    {
        taskPos.push_back({task[i], i+1});
    }
    sort(taskPos.begin(), taskPos.end());

    vector<int> duplicate;
    for (int i = 0; i < n; i++)
    {
        if (taskPos[i].first == taskPos[i+1].first)
        {
            duplicate.push_back(i);
        }
    }
    
    if (duplicate.size() < 2)
    {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << taskPos[i].second << " ";
    }
    cout << endl;

    swap(taskPos[duplicate[0]], taskPos[duplicate[0]+1]);
    for (int i = 0; i < n; i++)
    {
        cout << taskPos[i].second << " ";
    }
    cout << endl;

    swap(taskPos[duplicate[1]], taskPos[duplicate[1]+1]);
    for (int i = 0; i < n; i++)
    {
        cout << taskPos[i].second << " ";
    }
    cout << endl;
    
    return 0;
}