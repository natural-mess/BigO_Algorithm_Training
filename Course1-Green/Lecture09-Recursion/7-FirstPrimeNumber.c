#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int i = 0;
int k = 0;
int j = 0;

int primeNumber(int n)
{
    if (i==0)
    {
        if (n<=1)
        {
            return -1;
        }
        if (n<=3)
        {
            return n;
        }
        if (n%2==0 || n%3==0)
        {
            return -1;
        }
        i=n;
    }
    else
    {
        if (n<2)
        {
            k=i;
            i=0;
            return k;
        }
        if (i % n == 0)
        {
            i=0;
            return -1;
        }
    }
    n--;
    return primeNumber(n);
}

int firstPrimeNumber(int arr[], int n)
{
    if (j==n)
    {
        j=0;
        return -1;
    }
    else if (primeNumber(arr[j])!=-1)
    {
        k=j;
        j=0;
        return k;
    }
    else
    {
        j++;
        return firstPrimeNumber(arr, n);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    // printf("%d", primeNumber(n));
    printf("%d", firstPrimeNumber(arr, n));
}