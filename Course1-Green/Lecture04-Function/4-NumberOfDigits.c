#include <stdio.h>

int numberOfDigit(int n)
{
    int count = 1;
    while(n/10!=0)
    {
        n=n/10;
        count++;
    }
    return count;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", numberOfDigit(n));
    return 0;
}
