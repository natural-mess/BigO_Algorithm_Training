#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int counter = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]<97)
        {
            counter ++;
        }
    }
    cout << counter;

    return 0;
}