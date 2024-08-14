/*
- cnts: lưu số lần xuất hiện của các kí tự trong s
vd: 
cnts['a'] = 2
cnts['u'] = 1
cnts['t'] = 2
cnts['o'] = 2
cnts['m'] = 1
cnts['n'] = 1

cntt['a'] = 1
cntt['o'] = 1
cntt['m'] = 1
cntt['t'] = 2
- need tree: ko thể biển chuỗi s thành chuỗi t
for i : 0 -> 25
	if (cnts[i] < cntt[i])


- len(s) == len(t) => array
		
- automaton:
st = 0
for i: 0 -> len(t) - 1:
	while (s[st] != t[i] && st < len(s) - 1) ++st;
	if (st >= len(s)) => both, return
	++st
	
cout << "automaton"
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    int cnts[26] = {0};
    int cntt[26] = {0};
    // int indexCnts = 0;

    for (int i = 0; i < s.size(); i++)
    {
        cnts[s[i]-97]++;
    }

    // int indexCntt = 0;
    for (int i = 0; i < t.size(); i++)
    {
        cntt[t[i]-97]++;
    }
    
    for (int i = 0; i < 26; i++)
    {
        if (cntt[i] > cnts[i])
        {
            cout << "need tree";
            return 0;
        }
    }

    if (s.size() == t.size())
    {
        cout << "array";
        return 0;
    }

    int st=0;
    for (int i = 0; i < t.size(); i++)
    {
        while (s[st] != t[i] && st<s.size())
        {
            st++;
        }
        if (st >= s.size())
        {
            cout << "both";
            return 0;
        }
        st++;
    }
    
    
    cout << "automaton";

    return 0;    
}