#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int biggestOddDivisor(int n)
{
    if (n%2!=0)
    {
        return n;
    }
    else
    {
        return biggestOddDivisor(n/2);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", biggestOddDivisor(n));
}