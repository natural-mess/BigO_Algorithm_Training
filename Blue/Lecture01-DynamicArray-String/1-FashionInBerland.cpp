#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> buttons;
    int i=0;
    while (i<n)
    {
        int x;
        cin >> x;
        buttons.push_back(x);
        i++;
    }
    if (n==1)
    {
        if (buttons[0]==1)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
    else
    {
        int countOpen = 0;
        for (int j=0; j<buttons.size(); j++)
        {
            if (buttons[j]==0)
            {
                countOpen++;
                if (countOpen>1)
                {
                    break;
                }
            }
        }
        if (countOpen!=1)
        {
            cout << "NO";
        }
        else
        {
            cout << "YES";
        }
    }

    return 0;
}
