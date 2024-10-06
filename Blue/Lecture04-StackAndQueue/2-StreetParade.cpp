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
        stack<int> container;
        vector<int> truck(n);
        for (int i = 0; i < n; i++)
        {
            cin >> truck[i];
        }
        vector<int> truckSorted = truck;
        sort(truckSorted.begin(), truckSorted.end());
        vector<int> truckOrder;
        // int min = truck[0];
        truckOrder.push_back(truck[0]);
        for (int i = 1; i < n; i++)
        {
            // if (!container.empty() && container.top() == truck[i]+1)
            // {
            //     truckOrder.push_back(container.top());
            //     container.pop();
            // }
            // if (i!=0 && truck[i] < (truck[i-1]+1))
            // {
            //     container.push(truck[i-1]);
            //     truckOrder.push_back(truck[i]);
            // }
            // else if (i!=0 && truck[i] > (truck[i-1]+1))
            // {
            //     container.push(truck[i]);
            // }
            // else if (i!=0 && truck[i] == (truck[i-1]+1))
            // {
            //     truckOrder.push_back(truck[i]);
            // }
            if (truckOrder.back()+1 > truck[i])
            {
                container.push(truckOrder.back());
                truckOrder.pop_back();
                truckOrder.push_back(truck[i]);
            }
            else if (truckOrder.back()+1 < truck[i])
            {
                while (!container.empty() && container.top() == truckOrder.back()+1)
                {
                    truckOrder.push_back(container.top());
                    container.pop();
                }
                container.push(truck[i]);
            }
            else if (truckOrder.back()+1 == truck[i])
            {
                truckOrder.push_back(truck[i]);
            }

        }
        while (!container.empty())
        {
            truckOrder.push_back(container.top());
            container.pop();
        }   
        (truckOrder == truckSorted) ? (cout << "yes") : (cout << "no");
        cout << endl;
    }
    

    return 0;
}