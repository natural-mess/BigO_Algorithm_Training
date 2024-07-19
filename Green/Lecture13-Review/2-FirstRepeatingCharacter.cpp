#include <bits/stdc++.h>
using namespace std;

void FirstRepeatingChar(string input)
{
    int result = -1;
    for (int i = 0; input[i]!='\0'; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i!=j && input[i]==input[j])
            {
                result = i;
                break;
            }
        }
        if (result != -1)
        {
            break;
        }
    }
    if (result == -1)
    {
        cout << "null";
    }
    else
    {
        cout << input[result];
    }
}

int main()
{
    string inputString;
    cin >> inputString;
    FirstRepeatingChar(inputString);
    return 0;
}