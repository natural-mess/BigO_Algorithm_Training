#include <stdio.h>

int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);
    int sum[m], arr[m][n];

    for (int i = 0; i < m; i++)
    {
        sum[i] = 0;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
            sum[i] = sum[i] + arr[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        printf("%d: %d\n", i, sum[i]);
    }
    
    return 0;
}
