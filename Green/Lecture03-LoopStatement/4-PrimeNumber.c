#include <stdio.h>

int main()
{
    unsigned int x, count = 0;
    scanf("%d", &x);
    if (x==1)
    {
        printf("NO\n");
    }
    else
    {
        for (int i=2; i<x; i++)
        {
            if (x%i==0)
            {
                count++;
            }
        }
        (count==0)? printf("YES\n") : printf("NO\n");
    }

    return 0;
}