#include <bits/stdc++.h>
using namespace std;

void transform(string expression)
{
    stack<char> exp;
    for (char i : expression)
    {
        if (isalpha(i))
        {
            cout << i;
        }
        else if (i == ')')
        {
            cout << exp.top();
            exp.pop();
        }
        else if (i != '(')
        {
            exp.push(i);
        }
    }
    cout << endl;
}

int main()
{
    int t;
    vector<string> expression;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string a;
        cin >> a;
        expression.push_back(a);
    }
    for (int i = 0; i < t; i++)
    {
        transform(expression[i]);
    }
    
    return 0;
}