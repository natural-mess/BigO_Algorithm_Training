#include <stdio.h>

int smallestNumber (int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int PruningFlower (int arr[], int n)
{
    int min = smallestNumber(arr, n);
    int energy = 0;
    for (int i = 0; i < n; i++)
    {
        energy = energy + (arr[i] - min);
    }
    return energy;
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("%d", PruningFlower(arr, n));
}
