#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max = 0;

int largestDigit(int n)
{
    if (n<0)
    {
        n=n*(-1);
    }
    if (n%10>max)
    {
        max = n%10;
    }
    if (n/10==0)
    {
        return max;
    }
    else
    {
        return largestDigit(n/10);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", largestDigit(n));
}