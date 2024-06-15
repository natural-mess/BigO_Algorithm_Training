#include <stdio.h>

int main()
{
    unsigned int x, count=0;
    do
    {
        scanf("%d",&x);
        if (x==5)
        {
            count++;
        }
    } while (x!=0);
    printf("%d\n", count);

    return 0;
}