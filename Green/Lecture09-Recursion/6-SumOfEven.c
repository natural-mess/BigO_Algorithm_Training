#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sum = 0;

int sumOfEven(int arr[], int n)
{
    if (arr[n]%2==0)
    {
        sum = sum+arr[n];
    }
    if (n==0)
    {
        return sum;
    }
    else
    {
        n=n-1;
        return sumOfEven(arr,n);
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
    
    printf("%d", sumOfEven(arr, n-1));
}