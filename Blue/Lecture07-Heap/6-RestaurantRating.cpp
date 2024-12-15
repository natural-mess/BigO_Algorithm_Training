#include <bits/stdc++.h>
using namespace std;

// dung 2 queue, 1 min heap 1 max heap, min heap chua 1/3 rating dau, max heap chua 2/3 rating con lai

#define ONE_THIRD 3

int main()
{
    int n, cmd, x, minRating=0, numMinRating, binSize;
    priority_queue<int> maxHeap;
    queue<int> maxHeap_bin;

    cin >> n;
    while (n--)
    {
        cin >> cmd;
        if (cmd == 1)
        {
            cin >> x;
            maxHeap.push(x);
        }
        else
        {
            if (maxHeap.size() < 3)
            {
                cout << "No reviews yet" << endl;
            }
            else
            {
                numMinRating = maxHeap.size() / ((int)ONE_THIRD);
                while (numMinRating--)
                {
                    minRating = maxHeap.top();
                    maxHeap_bin.push(minRating);
                    maxHeap.pop();
                }
                cout << minRating << endl;
                binSize = maxHeap_bin.size();
                while (binSize--)
                {
                    maxHeap.push(maxHeap_bin.front());
                    maxHeap_bin.pop();
                }
            }
        }
    }

    return 0;
}