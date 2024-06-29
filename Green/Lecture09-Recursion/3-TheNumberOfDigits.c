#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int count=1;

int theNumberOfDigits(int n)
{
    if (n/10==0)
    {
        return count;
    }
    else
    {
        return count+theNumberOfDigits(n/10);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", theNumberOfDigits(n));
}