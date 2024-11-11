#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    
    while (1)
    {
        cin >> n;
        if (n==0)
        {
            break;
        }
        long long arr[n];
        long long num;
        long long sum=0,ret = 0;
        long long first, second;
        priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        while(n--)
        {
            cin >> num;
            minHeap.push(num);
        }
        // sum = arr[0];
        // for (int i=1; i<n; i++)
        // {
        //     sum = sum + arr[i];
        //     minHeap.push(sum);
        // }
         
        while(minHeap.size() > 1)
        {
            first = minHeap.top();
            minHeap.pop();
            second = minHeap.top();
            minHeap.pop();
            ret = ret + first + second;
            minHeap.push(first+second);
        }
        

        cout << ret << endl;
    }

    return 0;
}
