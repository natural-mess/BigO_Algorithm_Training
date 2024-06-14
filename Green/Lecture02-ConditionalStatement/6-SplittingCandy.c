#include <stdio.h>

int main()
{
    unsigned int x;
    scanf("%d", &x);
    ((x%2==0) && (x>=4))?printf("YES"): printf("NO");
    return 0;
}