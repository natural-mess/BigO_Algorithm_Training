#include <bits/stdc++.h>
using namespace std;

#define ONE_THIRD 3

int main()
{
    int n, cmd, x, numFirstRating, countRating=0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    cin >> n;
    while (n--)
    {
        cin >> cmd;
        if (cmd == 1)
        {
            countRating++;
            cin >> x;
            if (countRating <= 3)
            {
                maxHeap.push(x);
            }
            else
            {
                numFirstRating = countRating / ONE_THIRD;
                if (x > maxHeap.top())
                {
                    minHeap.push(x);
                    while(minHeap.size() > numFirstRating)
                    {
                        int temp = minHeap.top();
                        minHeap.pop();
                        maxHeap.push(temp);
                    }
                }
                else
                {
                    maxHeap.push(x);
                    while(minHeap.size() < numFirstRating)
                    {
                        int temp = maxHeap.top();
                        maxHeap.pop();
                        minHeap.push(temp);
                    }
                }
            }
        }
        else
        {
            if (countRating < 3)
            {
                cout << "No reviews yet" << endl;
            }
            else if (countRating == 3)
            {
                cout << maxHeap.top() << endl;
            }
            else
            {
                cout << minHeap.top() << endl;
            }
        }
    }

    return 0;
}