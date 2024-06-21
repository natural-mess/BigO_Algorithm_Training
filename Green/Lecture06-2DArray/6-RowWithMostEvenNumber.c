#include <stdio.h>
#include <stdbool.h>

bool isEven(int x)
{
    bool ret;
    (x%2 == 0) ? (ret = true) : (ret = false);
    return ret;
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int arr[m][n];
    int result[m];
    for (int i=0; i<m ; i++)
    {
        result[i] = 0;
    }

    for (int i=0; i<m ; i++)
    {
        for (int j=0; j<n; j++)
        {
            scanf("%d", &arr[i][j]);
            if (isEven(arr[i][j]))
            {
                result[i]++;
            }
        }
    }

    int evenIndex = 0;
    int evenNumber = result[0];

    for (int i=0; i<m ; i++)
    {
        if((result[i]!=0) && (result[i]>evenNumber))
        {
            evenNumber = result[i];
            evenIndex = i;
        }
    }

    printf("%d", evenIndex);

    return 0;
}
