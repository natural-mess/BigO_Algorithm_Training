#include <bits/stdc++.h>
using namespace std;

#define ARRAY_SIZE 100000

int main()
{
    int n, x;
    int array[ARRAY_SIZE];
    cin >> n >> x;
    int result = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (array[i] == x)
        {
            result = i+1;
            break;
        }
    }
    
    cout << result;
    return 0;
}