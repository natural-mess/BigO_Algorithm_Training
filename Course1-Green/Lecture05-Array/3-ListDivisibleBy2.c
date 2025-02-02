#include <stdio.h>

void ListDevisibleBy2 (int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] %2 == 0)
        {
            printf("%d\n", arr[i]);
        }
    }
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
    ListDevisibleBy2(arr, n);
}
