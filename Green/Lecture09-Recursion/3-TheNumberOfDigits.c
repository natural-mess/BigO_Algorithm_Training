#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int count=0;

int theNumberOfDigits(int n)
{
    count++;
    if (n/10==0)
    {
        return count;
    }
    else
    {
        return theNumberOfDigits(n/10);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", theNumberOfDigits(n));
}