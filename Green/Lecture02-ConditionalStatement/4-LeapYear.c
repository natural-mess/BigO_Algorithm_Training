#include <stdio.h>

int main()
{
    unsigned int x;
    scanf("%d", &x);
    
    if (((x%4==0)&&(x%100!=0) )|| (x%400==0))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}