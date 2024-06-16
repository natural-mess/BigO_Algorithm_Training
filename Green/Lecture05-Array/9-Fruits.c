#include <stdio.h>

int biggestIndex(int arr[], int n)
{
    int max = arr[0];
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            index = i;
        }
    }
    return index;
}

void fruits(int arr1[], int arr2[], int n)
{
    int indexBiggestApple = biggestIndex(arr1, n);
    int countApple = 0;
    int indexBiggestOrange = indexBiggestApple;
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] == arr1[indexBiggestApple])
        {
            countApple++;
            if (arr2[i] > arr2[indexBiggestOrange])
            {
                indexBiggestOrange = i;
            }
        }
    }
    
    if (countApple>1)
    {
        printf("%d", indexBiggestOrange+1);
    }
    else
    {
        printf("%d", indexBiggestApple+1);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d",&arr1[i], &arr2[i]);
    }
    fruits(arr1, arr2, n);
}
