#include <bits/stdc++.h>
using namespace std;

struct dataStructure
{
    int isStack = 1;
    int isQueue = 1;
    int isHeap = 1;
};


int main()
{
    int n;
    stack<int> st;
    queue<int> q;
    priority_queue<int> maxHeap;
    dataStructure ret;
    bool flag;
    while (cin >> n)
    {
        int cmd, x, y;
        ret.isHeap = 1;
        ret.isQueue = 1;
        ret.isStack = 1;
        flag = false;
        while (n--)
        {
            cin >> cmd;
            if (cmd == 1)
            {
                cin >> x;
                st.push(x);
                q.push(x);
                maxHeap.push(x);
                flag = true;
            }
            else
            {
                cin >> y;

                if (flag == false)
                {
                    break;
                }
                else
                {
                    if (y!=st.top())
                    {
                        ret.isStack = 0;
                    }
                    st.pop();
            
                    if (y!=q.front())
                    {
                        ret.isQueue = 0;
                    }
                    q.pop();
                
                    if (y!=maxHeap.top())
                    {
                        ret.isHeap = 0;
                    }
                    maxHeap.pop();
                }
            }      
        }
        if (ret.isHeap + ret.isQueue + ret.isStack == 0)
        {
            cout << "impossible\n";
        }
        else if (ret.isHeap + ret.isQueue + ret.isStack >= 2)
        {
            cout << "not sure\n";
        }
        else if (ret.isStack == 1)
        {
            cout << "stack\n";
        }
        else if (ret.isQueue == 1)
        {
            cout << "queue\n";
        }
        else if (ret.isHeap == 1)
        {
            cout << "priority queue\n";
        }

        while (st.empty()!=true)
        {
            st.pop();
        }
        while (q.empty()!=true)
        {
            q.pop();
        }
        while (maxHeap.empty()!=true)
        {
            maxHeap.pop();
        } 
    }


    return 0;
}
