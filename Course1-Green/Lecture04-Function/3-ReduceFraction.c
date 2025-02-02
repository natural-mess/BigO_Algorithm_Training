#include <stdio.h>

int GCD(int a, int b)
{
    int gcd, smallerNumber;

    (a<b)? (smallerNumber=a) : (smallerNumber=b);

    for (int i=smallerNumber; i>0; i--)
    {
        if (a%i==0 && b%i==0)
        {
            gcd = i;
            break;
        }
    }

    return gcd;
}

int main()
{
    int a,b;
    scanf("%d %d", &a, &b);
    printf("%d %d\n", a/GCD(a,b), b/GCD(a,b));
    return 0;
}
