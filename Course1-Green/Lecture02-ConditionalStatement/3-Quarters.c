#include <stdio.h>

int main()
{
    unsigned int x;
    scanf("%d", &x);
    switch (x)
    {
    case 1:
    case 2:
    case 3:
        printf("1\n");
        break;
    
    case 4:
    case 5:
    case 6:
        printf("2\n");
        break;
    
    case 7:
    case 8:
    case 9:
        printf("3\n");
        break;

    case 10:
    case 11:
    case 12:
        printf("4\n");
        break;

    default:
        break;
    }

    return 0;
}