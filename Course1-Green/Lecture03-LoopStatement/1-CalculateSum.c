#include <stdio.h>

int main()
{
    unsigned int n, S=0;
    scanf("%d", &n);
    for (int i=0; i<=n; i++)
    {
        S = S+i;
    }
    printf("%d\n", S);
    return 0;
}