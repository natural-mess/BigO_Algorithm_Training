#include <bits/stdc++.h>
using namespace std;

int main()
{
    string molecule;
    stack<int> exp;
    int multiplier;
    int tempSum = 0;
    cin >> molecule;

    for (int i = 0; i<molecule.length(); i++)
    {
        if (molecule[i] == 'C')
        {
            exp.push(12);
        }
        else if (molecule[i] == 'H')
        {
            exp.push(1);
        }
        else if (molecule[i] == 'O')
        {
            exp.push(16);
        }
        else if (isalnum(molecule[i]))
        {
            multiplier = exp.top() * int(molecule[i]-48);
            exp.pop();
            exp.push(multiplier);
        }
        else if (molecule[i] == '(')
        {
            exp.push(-1);
        }
        else if (molecule[i] == ')')
        {
            while (exp.top()!=-1)
            {
                tempSum = tempSum + exp.top();
                exp.pop();
            }
            exp.pop(); // delete -1
            exp.push(tempSum); // push result to stack
            tempSum = 0;
        }
    }
    int sum=0;
    while (exp.size()!=0)
    {
        sum = sum + exp.top();
        exp.pop();
    }
    cout << sum;

    return 0;
}
