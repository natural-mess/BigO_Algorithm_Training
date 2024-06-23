#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int r=-1;

int GCD(int x, int y)
{
    if (x<y && r==-1)
    {
        x = x+y;
        y = x-y;
        x = x-y;
    }
    else
    {
        if (r==0)
        {
            return x;
        }
        r = x%y;
        x=y;
        y=r;
    }
    return GCD(x, y);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    
    printf("%d", GCD(a, b));
}