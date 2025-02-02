#include <bits/stdc++.h>
using namespace std;

int main()
{
    // cout << 'k' + 'l' + 'm' + 'n' + 'o' + 'p' + 'q' << endl;
    // cout << 'k' + 'l' + 'm' + 'p' + 'o' + 'p' + 'q' << endl;
    // cout << 'k' + 'l' + 'm' + 'n' + 'o' + 'p' + 'r' << endl;
    // cout << 'k' + 'l' + 'm' + 'o' + 'o' + 'p' + 'q' << endl;

    // cout << 'a' + 'b' + 'a' + 'a' << endl;
    // cout << 'a' + 'c' + 'a' + 'a' << endl;

    // cout << 'a' + 'b' + 'a' + 'b' << endl;
    
    string s, t;
    cin >> s >> t;
    
    int lastS = s.size() - 1;
    int lastT = t.size() - 1;

    int diffIndex;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]!=t[i])
        {
            diffIndex = i;
            break;
        }
    }

    string result = s;
    
    for (int i = lastS; i >= diffIndex; i--)
    {
        if (result[i]=='z')
        {
            result[i]='a';
        }
        else
        {
            result[i]++;
        }
        if (result.compare(s)>0 && result.compare(t)<0)
        {
            cout << result;
            return 0;
        }
    }
    cout << "No such string";
    

    return 0;
}