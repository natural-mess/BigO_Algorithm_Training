#include <stdio.h>

int main()
{
    double a, b;
    scanf("%lf %lf", &a, &b);
    if (((a>0)&&(b>0)) || ((a<0)&&(b<0)))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}