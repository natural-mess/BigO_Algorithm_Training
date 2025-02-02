#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        queue <int> qu;
        priority_queue<int> maxHeap;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            qu.push(x);
            if (i==m)
            {
                qu.push(-1);
            }
            maxHeap.push(x);
            
        }
        
        int topHeap;
        int topQueue;
        int counter = 0;
        if (maxHeap.size() == 1)
        {
            cout << 1 << endl;
        }
        else
        {
            while (1)
            {
                topHeap = maxHeap.top();
                while (topHeap != qu.front())
                {
                    topQueue = qu.front();
                    qu.pop();
                    qu.push(topQueue);
                }
                maxHeap.pop();
                qu.pop();
                counter++;
                if (qu.front() == -1)
                {
                    cout << counter << endl;
                    break;
                }
            }
        }
    }
    return 0;
}