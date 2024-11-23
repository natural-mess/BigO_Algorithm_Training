#include <bits/stdc++.h>
using namespace std;

struct dataStructure
{
    int isStack = -1;
    int isQueue = -1;
    int isHeap = -1;
};


int main()
{
    int n;
    stack<int> st;
    queue<int> q;
    priority_queue<int> maxHeap;
    while (cin >> n)
    {
        int cmd, x, y;
        dataStructure ret;

        while (n--)
        {
            cin >> cmd;
            if (cmd == 1)
            {
                cin >> x;
                st.push(x);
                q.push(x);
                maxHeap.push(x);
            }
            else
            {
                cin >> y;

                if (ret.isStack!=2)
                {
                    if (st.empty())
                    {
                        ret.isStack = 2;
                    }
                    else if (st.empty()!=true && y==st.top())
                    {
                        ret.isStack = 1;
                        st.pop();
                    }
                    else if (st.empty()!=true && y!=st.top())
                    {
                        ret.isStack = 2;
                    }
                }
                
                if (ret.isQueue!=2)
                {
                    if (q.empty())
                    {
                        ret.isQueue = 2;
                    }
                    else if (q.empty()!=true && y==q.front())
                    {
                        ret.isQueue = 1;
                        q.pop();
                    }
                    else if (q.empty()!=true && y!=q.front())
                    {
                        ret.isQueue = 2;
                    }
                }
                
                if (ret.isHeap!=2)
                {
                    if (maxHeap.empty())
                    {
                        ret.isHeap = 2;
                    }
                    else if (maxHeap.empty()!=true && y==maxHeap.top())
                    {
                        ret.isHeap = 1;
                        maxHeap.pop();
                    }
                    else if (maxHeap.empty()!=true && y!=maxHeap.top())
                    {
                        ret.isHeap = 2;
                    }
                }
            }

            if (n==0)
            {
                if (ret.isHeap!=1 && ret.isQueue!=1 && ret.isStack!=1)
                {
                    cout << "impossible\n";
                }
                else if ((ret.isStack==1 && ret.isQueue==1) || (ret.isStack==1 && ret.isHeap==1) || (ret.isHeap==1 && ret.isQueue==1) || (ret.isStack==1 && ret.isQueue==1 && ret.isHeap==1))
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
        }
    }


    return 0;
}
