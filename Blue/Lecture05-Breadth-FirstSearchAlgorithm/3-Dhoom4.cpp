#include<bits/stdc++.h>
using namespace std;

int main()
{
    unsigned int key, lock;
    cin >> key >> lock;
    unsigned int n;
    cin >> n;
    unsigned int arr[n];
    int visited[100001];
    // queue <int> sohang;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    memset(visited, -1, sizeof(visited));
    
    int index=1;
    queue <int> qu;
    
    qu.push(key);
    unsigned mul = 1;
    visited[key] = 0;
    unsigned int count = 0;
    unsigned int x, y, z;

    while (!qu.empty())
    {
        x = qu.front();
        qu.pop();
        for (int i = 0; i < n; i++)
        {
            y = (x*arr[i])%100000;
            if (visited[y] == -1)
            {
                visited[y] = visited[x] + 1;
                qu.push(y);
            }
            if (y == lock)
            {
                cout << visited[y] << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;


    return 0;    
}