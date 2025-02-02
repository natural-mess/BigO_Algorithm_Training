#include <stdio.h>

int sum(int x)
{
    int sum = 0;
    for (int i=1; i<=x; i++)
    {
        sum = sum + (i*i);
    }
    return sum;
}

int main()
{
    int x;
    scanf("%d", &x);
    printf("%d\n", sum(x));
    return 0;
}
