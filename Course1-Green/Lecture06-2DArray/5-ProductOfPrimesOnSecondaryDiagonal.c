#include <stdio.h>
#include <stdbool.h>

bool checkPrime(int x)
{
    bool ret;
    int count = 0;
    if (x==1)
    {
        ret = false;
    }
    else
    {
        for (int i=2; i<x; i++)
        {
            if (x%i==0)
            {
                count++;
            }
        }
        (count==0)? (ret = true) : (ret = false);
    }
    return ret;
}

int main()
{
    unsigned int n;
    scanf("%d", &n);
    unsigned int arr[n][n];
    unsigned int result = 1;

    for (int i=0; i<n ; i++)
    {
        for (int j=0; j<n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i=0; i<n ; i++)
    {
        for (int j=n-1; j>=0; j--)
        {
            if ((j==n-(i+1)) && (checkPrime(arr[i][j]) == true))
            {
                result = (result * arr[i][j]) % 1000003;
            }
        }
    }

    printf("%d", result);

    return 0;
}