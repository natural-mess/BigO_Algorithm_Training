#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    int cmd, num;
    priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    priority_queue<int, std::vector<int>, std::greater<int>> minHeap_removed;
    cin >> q;
    while(q--)
    {
        cin >> cmd;
        switch (cmd)
        {
        case 1:
            cin >> num;
            minHeap.push(num);
            break;
        
        case 2:
            cin >> num;
            minHeap_removed.push(num);
            break;

        default:
            while (!minHeap_removed.empty() && minHeap_removed.top() == minHeap.top())
            {
                minHeap.pop();
                minHeap_removed.pop();
            }
            cout << minHeap.top() << endl;
            break;
        }
    }
    

    return 0;
}
