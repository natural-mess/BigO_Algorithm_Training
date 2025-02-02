#include <stdio.h>
#include <math.h>

int main()
{
    double luongcoban, heso, phucap;
    scanf("%lf", &luongcoban);
    scanf("%lf", &heso);
    scanf("%lf", &phucap);
    printf("%.2lf\n", luongcoban*heso+phucap);
    return 0;
}