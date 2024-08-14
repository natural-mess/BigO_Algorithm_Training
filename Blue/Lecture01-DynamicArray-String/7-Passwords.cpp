#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string passAttempt[n];
    string password;

    for (int i = 0; i < n; i++)
    {
        cin >> passAttempt[i];
    }
    cin >> password;

    int countBestCase = 0;
    int countWorstCase = 0;

    for (int i = 0; i < n; i++)
    {
        if (passAttempt[i].length() < password.length())
        {
            countBestCase++;
        }
        if (passAttempt[i].length() <= password.length())
        {
            countWorstCase++;
        }
    }
    int bestCase = countBestCase+1+(countBestCase/k)*5;
    int worstCase;
    if (n==k)
    {
        worstCase = countWorstCase;
    }
    else
    {
        worstCase = countWorstCase+((countWorstCase-1)/k)*5;
    }
    
    cout << bestCase << " " << worstCase;
    
    return 0;
}