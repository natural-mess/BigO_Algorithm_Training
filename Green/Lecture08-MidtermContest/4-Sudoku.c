#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define m 9
#define n 9

bool isAllElementDifferent(int arr[], int size)
{
    bool ret = true;
    for (int i = 0; i < size; i++)
    {
        for (int j=0; j<size; j++)
        {
            if (i!=j && arr[i]==arr[j])
            {
                ret = false;
                i=size;
                break;
            }
        }
    }
    return ret;
}

int main()
{
    int arr[m][n];
    int testArr[m];
    char result = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // test row
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            testArr[j] = arr[i][j];
        }
        if (isAllElementDifferent(testArr, m)==false)
        {
            result = 0;
            break;
        }
    }

    // test column
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            testArr[j] = arr[j][i];
        }
        if (isAllElementDifferent(testArr, m)==false)
        {
            result = 0;
            break;
        }
    }

    // test 3x3 matrix
    int testArrIndex = 0;
    if (result==1)
    {
        for (int i = 0; i < 7; i=i+3)
        {
            for (int j = 0; j < 7; j=j+3)
            {
                for (int p=i; p<=(i+2); p++)
                {
                    for (int q=j; q<=(j+2); q++)
                    {
                        testArr[testArrIndex] = arr[p][q];
                        testArrIndex++;
                    }
                }
                if (isAllElementDifferent(testArr, m)==false)
                {
                    result = 0;
                    break;
                }
                testArrIndex=0;
            }
            if (result == 0)
            {
                break;
            }
        }
    }
    

    (result==1)? (printf("YES")) : (printf("NO"));
}