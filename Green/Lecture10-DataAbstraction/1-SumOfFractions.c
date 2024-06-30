#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int num;
    int denom;
} Fraction;

int gcd (int a, int b)
{
    int r=0;
    while (b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

void reductFraction(Fraction *p)
{
    if ((*p).num == 0)
    {
        (*p).denom = 1;
        return;
    }
    int x = gcd(abs((*p).num), abs((*p).denom));
    (*p).num = (*p).num / x;
    (*p).denom = (*p).denom / x;
}

Fraction sumFraction (Fraction p1, Fraction p2)
{
    Fraction p3;
    p3.num = p1.num * p2.denom + p1.denom * p2.num;
    p3.denom = p1.denom * p2.denom;
    reductFraction(&p3);
    return p3;
}

int main()
{
    Fraction p1, p2, p3;
    scanf("%d %d", &p1.num, &p1.denom);
    scanf("%d %d", &p2.num, &p2.denom);
    p3 = sumFraction(p1, p2);
    printf("%d %d", p3.num, p3.denom);
}
