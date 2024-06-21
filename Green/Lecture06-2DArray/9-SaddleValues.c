#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int arr[m][n];
    int temp[m][n];
    int countSaddle=0;
    int max=0;
    int min=0;
    int p=0, q=0;

    for (int i=0; i<m ; i++)
    {
        for (int j=0; j<n; j++)
        {
            scanf("%d", &arr[i][j]);
            temp[i][j] = arr[i][j];
        }
    }

    // find biggest number in each row
    for (int i=0; i<m ; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (arr[i][j]>max)
            {
                max = arr[i][j];
            }
        }
        for (int k=0; k<n; k++)
        {
            if (temp[i][k]<max)
            {
                temp[i][k] = -1;
            }
        }
        max=0;
    }

    // printf("test1\n");
    // for (int i=0; i<m ; i++)
    // {
    //     for (int j=0; j<n; j++)
    //     {
    //         printf("%d ", temp[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    for (int i=0; i<m ; i++)
    {
        for (int j=0; j<n; j++)
        {
            // check if that number is also the smallest in its column
            if (temp[i][j] != -1)
            {
                for (int k=0; k<m; k++)
                {
                    if (arr[k][j] < temp[i][j])
                    {
                        temp[i][j] = -1;
                        break;
                    }
                }
            }
            // printf("test2\n");
            // for (int i=0; i<m ; i++)
            // {
            //     for (int j=0; j<n; j++)
            //     {
            //         printf("%d ", temp[i][j]);
            //     }
            //     printf("\n");
            // }
            // printf("\n");
        }
    }


    for (int i=0; i<m ; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (temp[i][j] != -1)
            {
                countSaddle++;
            }
        }
    }
    printf("%d\n", countSaddle);

    return 0;
}
