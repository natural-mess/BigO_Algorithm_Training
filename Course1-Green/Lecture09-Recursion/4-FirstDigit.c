#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int firstDigit(int n)
{
    if (n<0)
    {
        n=n*(-1);
    }
    if (n/10==0)
    {
        return n%10;
    }
    else
    {
        return firstDigit(n/10);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", firstDigit(n));
}