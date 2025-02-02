#include <stdio.h>

int main()
{
    unsigned int x;
    scanf("%d", &x);

    for(int i=1; i<=x; i++)
    {
        if (i==1 || i==x)
        {
            for (int j=1; j<=x; j++)
            {
                if (j==x)
                {
                    printf("*\n");
                }
                else
                {
                    printf("*");
                }
            }
        }
        else
        {
            for (int j=1; j<=x; j++)
            {
                if (j==x)
                {
                    printf("*\n");
                }
                else if (j==1)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
        }
    }

    return 0;
}