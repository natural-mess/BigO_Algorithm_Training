#include <stdio.h>

int generateNumber (int a, int b, int p)
{
    return (a+b)%p;
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int arr[m][n];
    
    int a, b, p;
    scanf("%d %d %d", &a, &b, &p);

    char aFlag = 0;
    int prevNum = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j==0)
            {
                arr[i][j] = a;
            }
            else if (i == 0 && j==1)
            {
                arr[i][j] = b;
            }
            else if (i == 0 && j==2)
            {
                arr[i][j] = generateNumber(a, b, p);
                aFlag = 1;
                prevNum = arr[i][j];
            }
            else
            {
                if (aFlag == 1)
                {
                    a = prevNum;
                    aFlag = 0;
                }
                else
                {
                    b = prevNum;
                    aFlag = 1;
                }
                arr[i][j] = generateNumber(a, b, p);
                prevNum = arr[i][j];
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
