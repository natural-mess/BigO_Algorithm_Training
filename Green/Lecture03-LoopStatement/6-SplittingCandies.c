#include <stdio.h>

int main()
{
    unsigned int n, x, check=1;
    scanf("%d", &n);

    for (int i = 0; i<n; i++)
    {
        scanf("%d", &x);
        if (x%2!=0 && check==1)
        {
            check = 0;
        }
    }
    (check==1)? printf("YES\n") : printf("NO\n");

    return 0;
}