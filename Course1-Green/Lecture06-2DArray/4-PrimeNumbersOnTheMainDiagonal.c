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
    int n;
    scanf("%d", &n);
    int arr[n][n];
    int countPrime = 0;

    for (int i=0; i<n ; i++)
    {
        for (int j=0; j<n; j++)
        {
            scanf("%d", &arr[i][j]);
            if (j==i)
            {
                if (checkPrime(arr[i][j]) == true)
                {
                    countPrime++;
                }
            }
        }
    }

    printf("%d", countPrime);

    return 0;
}
