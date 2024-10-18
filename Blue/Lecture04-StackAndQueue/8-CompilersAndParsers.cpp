#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> expression;
    int t;
    cin >> t;
    string inputString;
    int counter = 0;

    for (int i = 0; i < t; i++)
    {
        counter = 0;
        cin >> inputString;
        for (int i = 0; i < inputString.length(); i++)
        {
            if (inputString[i] == '<')
            {
                expression.push(1);
            }
            else
            {
                if (expression.empty() == false)
                {
                    expression.pop();
                    if (expression.empty() == true)
                        counter = i+1;
                }
                else
                {
                    break;
                }
            }   
        }
        cout << counter << endl;

        while (expression.empty() == false)
        {
            expression.pop();
        }
    }
    

    return 0;
}
