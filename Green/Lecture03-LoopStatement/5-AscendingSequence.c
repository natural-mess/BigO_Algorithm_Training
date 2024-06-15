#include <stdio.h>

int main()
{
    unsigned int x, temp=0;
    unsigned char check = 1;
    do
    {
        scanf("%d",&x);
        if (x!=0 && check==1)
        {
            if (x>=temp)
            {
                check = 1;
            }
            else
            {
                check = 0;
            }
            temp = x;
        }
    } while (x!=0);
    (check==1)? printf("YES\n") : printf("NO\n");

    return 0;
}