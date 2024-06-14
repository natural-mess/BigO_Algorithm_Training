#include <stdio.h>

int main()
{
    unsigned int number;
    unsigned char sum = 0;
    scanf("%d", &number);

    while (number!=0)
    {
        sum = sum + (number%10);
        number = number / 10;
    }
    printf("%d\n", sum%10);
    return 0;
}