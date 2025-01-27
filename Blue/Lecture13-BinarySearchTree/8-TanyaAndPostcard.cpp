#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    int yay=0, whoops=0;
    map<char, int> t_string;
    map<char, int> s_string;

    for (char c: s)
    {
        s_string[c]++;
    }

    for (char c: t)
    {
        t_string[c]++;
    }
    
    // Count the number of 'yay' matches
    for (char c = 'a'; c <= 'z'; c++) 
    {
        int match = min(s_string[c], t_string[c]);
        yay += match;
        s_string[c] -= match;
        t_string[c] -= match;
    }
    for (char c = 'A'; c <= 'Z'; c++) 
    {
        int match = min(s_string[c], t_string[c]);
        yay += match;
        s_string[c] -= match;
        t_string[c] -= match;
    }

    // Count the number of 'whoops' matches
    for (char c = 'a'; c <= 'z'; c++) 
    {
        int match = min(s_string[c], t_string[toupper(c)]);
        whoops += match;
        s_string[c] -= match;
        t_string[toupper(c)] -= match;
    }
    for (char c = 'A'; c <= 'Z'; c++) 
    {
        int match = min(s_string[c], t_string[tolower(c)]);
        whoops += match;
        s_string[c] -= match;
        t_string[tolower(c)] -= match;
    }

    cout << yay << " " << whoops;
    return 0;
}