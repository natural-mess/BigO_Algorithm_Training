#include <bits/stdc++.h>
using namespace std;

#define FULL_ROUND 26
#define HALF_ROUND 13

int main()
{
    string s;
    cin >> s;
    int sum = 0;
    char firstChar = 'a';
    for (int i=0; i<s.length(); i++)
    {
        if (abs(s[i]-firstChar)>HALF_ROUND)
        {
            sum = sum + (FULL_ROUND - abs(s[i]-firstChar));
        }
        else
        {
            sum = sum + abs(s[i]-firstChar);
        }
        firstChar = s[i];
    }
    cout << sum;
    return 0;
}