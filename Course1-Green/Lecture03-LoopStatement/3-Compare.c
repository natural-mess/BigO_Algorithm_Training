#include <stdio.h>

int main()
{
    int x, min=0, max=0;
    do
    {
        scanf("%d",&x);
        if (min==0 && max==0)
        {
            min = max = x;
        }
        if (x>=0)
        {
            if (x<min)
            {
                min = x;
            }
            if (x>max)
            {
                max = x;
            }
        }
    } while (x!=-1);
    printf("%d %d\n", max, min);

    return 0;
}