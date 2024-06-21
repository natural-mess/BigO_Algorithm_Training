#include <stdio.h>

void initArray(int *arr, int n, int initvalue)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = initvalue;
    }
}

int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);
    int result[n], arr[m][n];
    int countNegative;
    initArray(result, n, -1);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        countNegative=0;
        for (int j = 0; j < m; j++)
        {
            if (arr[j][i] < 0)
            {
                countNegative++;
            }
        }
        if (countNegative == m)
        {
            result[i] = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (result[i] != -1)
        {
            printf("%d ",result[i]);
        }
    }
    

    return 0;
}
