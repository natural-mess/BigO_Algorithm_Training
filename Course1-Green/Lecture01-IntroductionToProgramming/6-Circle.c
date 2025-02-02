#include <stdio.h>
#define PI 3.14

int main()
{
    double r;
    scanf("%lf", &r);
    printf("%.2lf\n", 2.00*r*PI);
    printf("%.2lf\n", r*r*PI);
    return 0;
}