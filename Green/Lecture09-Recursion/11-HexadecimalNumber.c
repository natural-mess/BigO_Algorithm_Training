#include <stdio.h>

int zero=0;

void hexadecimal(int n)
{
    if (n==0 && zero==1)
    {
        return;
    }
    zero=1;
    hexadecimal(n/16);
    switch (n%16)
    {
    case 10:
        printf("A");
        break;
    
    case 11:
        printf("B");
        break;

    case 12:
        printf("C");
        break;

    case 13:
        printf("D");
        break;

    case 14:
        printf("E");
        break;

    case 15:
        printf("F");
        break;

    default:
        printf("%d",n%16);
        break;
    }
}
 

int main()
{
    int n;
    scanf("%d", &n);
    hexadecimal(n);
    return 0;
}