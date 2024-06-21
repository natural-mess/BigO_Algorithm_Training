#include <stdio.h>
#include <stdbool.h>

bool isMaxInArray(int arr[], int size, int num)
{
    int max = num;
    bool ret;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    (num == max) ? (ret = true) : (ret = false);
    return ret;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n][n];
    int temp[n][n];
    int countQueen=0;
    int max=0;
    int p=0, q=0;

    for (int i=0; i<n ; i++)
    {
        for (int j=0; j<n; j++)
        {
            scanf("%d", &arr[i][j]);
            temp[i][j] = arr[i][j];
        }
    }

    // find biggest number in each row
    for (int i=0; i<n ; i++)
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
    // for (int i=0; i<n ; i++)
    // {
    //     for (int j=0; j<n; j++)
    //     {
    //         printf("%d ", temp[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    for (int i=0; i<n ; i++)
    {
        for (int j=0; j<n; j++)
        {
            // check if that number is also the biggest in its column
            if (temp[i][j] != -1)
            {
                for (int k=0; k<n; k++)
                {
                    if (arr[k][j] > temp[i][j])
                    {
                        temp[i][j] = -1;
                        break;
                    }
                }
            }

            // printf("test2\n");
            // for (int i=0; i<n ; i++)
            // {
            //     for (int j=0; j<n; j++)
            //     {
            //         printf("%d ", temp[i][j]);
            //     }
            //     printf("\n");
            // }
            // printf("\n");

            // check if that number is also the biggest in its main diagonal
            if (temp[i][j] != -1)
            {
                p=i-1, q=j-1;
                while (p>=0 && q>=0)
                {
                    if (arr[p][q] > temp[i][j])
                    {
                        temp[i][j] = -1;
                        break;
                    }
                    p--;
                    q--;
                }
            }
            // printf("test3.5\n");
            // for (int i=0; i<n ; i++)
            // {
            //     for (int j=0; j<n; j++)
            //     {
            //         printf("%d ", temp[i][j]);
            //     }
            //     printf("\n");
            // }
            // printf("\n");
            if (temp[i][j] != -1)
            {
                p=i+1, q=j+1;
                while (p<n && q<n)
                {
                    if (arr[p][q] > temp[i][j])
                    {
                        temp[i][j] = -1;
                        break;
                    }
                    p++;
                    q++;
                }
            }

            // printf("test3\n");
            // for (int i=0; i<n ; i++)
            // {
            //     for (int j=0; j<n; j++)
            //     {
            //         printf("%d ", temp[i][j]);
            //     }
            //     printf("\n");
            // }
            // printf("\n");

            // check if that number is also the biggest in its secondary diagonal
            if (temp[i][j] != -1)
            {
                p=i-1, q=j+1;
                while (p>=0 && q<n)
                {
                    if (arr[p][q] > temp[i][j])
                    {
                        temp[i][j] = -1;
                        break;
                    }
                    p--;
                    q++;
                }
            }
            if (temp[i][j] != -1)
            {
                p=i+1, q=j-1;
                while (p<n && q>=0)
                {
                    if (arr[p][q] > temp[i][j])
                    {
                        temp[i][j] = -1;
                        break;
                    }
                    p++;
                    q--;
                }
            }
        }
    }

    // for (int i=0; i<n ; i++)
    // {
    //     for (int j=0; j<n; j++)
    //     {
    //         printf("%d ", temp[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    for (int i=0; i<n ; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (temp[i][j] != -1)
            {
                countQueen++;
            }
        }
    }
    printf("%d\n", countQueen);

    return 0;
}
