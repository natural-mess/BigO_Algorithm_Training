#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (i!=0)
        {
            printf("\n");
        }
        for (int j = 0; j < (n-i-1); j++)
        {
            printf(" ");
        }
        for (int k = 0; k < (i+count); k++)
        {
            printf("*");
        }
        count++;
    }
}