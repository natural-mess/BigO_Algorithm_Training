#include <stdio.h>

int largestDigit(int n)
{
    int largest = 0;
    while(n!=0)
    {
        if (n%10 > largest)
        {
            largest = n%10;
        }
        n = n/10;
    }
    return largest;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", largestDigit(n));
    return 0;
}
