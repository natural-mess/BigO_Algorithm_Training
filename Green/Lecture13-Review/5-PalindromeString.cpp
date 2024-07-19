#include <bits/stdc++.h>
using namespace std;

string temp;
int indexTemp=0;

bool palindromeString (string input, int n)
{
    temp[indexTemp] = input[n];
    if (temp[indexTemp] != input[indexTemp])
    {
        return 0;
    }
    if (n==0)
    {
        return 1;
    }
    indexTemp++;
    return palindromeString(input, n-1);
}

int main()
{
    int n;
    cin >> n;
    string input;
    cin >> input;
    (palindromeString(input, n-1)==1) ? printf("YES") : printf("NO");
    return 0;
}