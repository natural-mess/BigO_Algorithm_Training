#include <stdio.h>
#include <stdbool.h>

bool checkPrime(int x)
{
    bool ret;
    int count = 0;
    if (x<=1)
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

int CountPrimes (int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (checkPrime(arr[i]) == true)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("%d", CountPrimes(arr, n));
}

