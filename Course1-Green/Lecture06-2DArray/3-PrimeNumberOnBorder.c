#include <stdio.h>
#include <stdbool.h>

bool checkPrime(int x)
{
    bool ret;
    int count = 0;
    if (x==1)
    {
        ret = false;
    }
    else
    {
        for (int i=2; i<x; i++)
        {
            if (x%i==0)
            {
                count++;
            }
        }
        (count==0)? (ret = true) : (ret = false);
    }
    return ret;
}

int main()
{
    int m,n;
    scanf("%d %d", &m, &n);
    int arr[m][n];
    int countPrime = 0;

    for (int i=0; i<m ; i++)
    {
        for (int j=0; j<n; j++)
        {
            scanf("%d", &arr[i][j]);
            if (i==0 || i==(m-1) || ((i!=0)&&((j==0)||(j==(n-1)))))
            {
                if (checkPrime(arr[i][j]) == true)
                {
                    countPrime++;
                }
            }
        }
    }

    printf("%d", countPrime);

    return 0;
}