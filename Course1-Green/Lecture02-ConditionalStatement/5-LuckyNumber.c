#include <stdio.h>

int main()
{
    int a, b, x;
    scanf("%d %d", &a, &b);
    scanf("%d", &x);
    
    if (x%a==0)
    {
        if (x%b==0)
        {
            printf("Both\n");
        }
        else
        {
            printf("Upan\n");
        }
    }
    else if (x%a!=0)
    {
        if (x%b==0)
        {
            printf("Ipan\n");
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}