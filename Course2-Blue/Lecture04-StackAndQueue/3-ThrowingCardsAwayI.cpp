#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    queue<int> inputQueue;
    while (1)
    {
        cin >> n;
        if (n==0)
        {
            break;
        }
        for (int i = 1; i <= n; i++)
        {
            inputQueue.push(i);
        }
        cout << "Discarded cards:";
        bool first = true;
        while (inputQueue.size() != 1)
        {
            if (first == true)
            {
                cout << " ";
                first = false;
            }
            // print number
            cout << inputQueue.front();
            // remove that number
            inputQueue.pop();
            // move the next number to the back
            inputQueue.push(inputQueue.front());
            // remove that number
            inputQueue.pop();
            if (inputQueue.size() != 1)
            {
                cout << ", ";
            }
        }
        cout << endl << "Remaining card: " << inputQueue.front() << endl;
        inputQueue.pop();
    }
    return 0;
}