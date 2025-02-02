#include <bits/stdc++.h>
using namespace std;

#define MAX 102

char a[MAX];

bool compare(char a, char b)
{
    return a<b;
}

int main()
{
    int n;
    cin >> n;
    cin >> a;

    int sizeA = 0;

    for (int i = 0; a[i]!='\0'; i++)
    {
        sizeA++;
        if (a[i] < 97)
        {
            a[i] = a[i] + 32;
        }
    }
    if (sizeA < 26)
    {
        cout << "NO";
        return 0;
    }

    sort(a, a+n, compare);
    // for (int i = 0; i < a[i]!='\0'; i++)
    // {
    //     cout << a[i];
    // }
    // cout << endl;
    
    int start = 97;
    int end = 122;
    int index = 0;
    while (start <= end || a[index]!='\0')
    {
        if (start == a[index] && a[index+1]!=start)
        {
            start++; 
        }
        index++;
    }

    (start==123)? cout << "YES" : cout << "NO";
    
    return 0;
}