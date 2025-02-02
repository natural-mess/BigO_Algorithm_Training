#include <stdio.h>
#include <stdbool.h>

bool searchElement(int arr[], int n, int element)
{
    bool ret = false;
    int i = 0;
    while (i<n)
    {
        if (arr[i] == element)
        {
            ret = true;
            break;
        }
        i++;
    }
    return ret;
}

void employeeID(int arr[], int n)
{
    int min = 0;
    min++;
    while (searchElement(arr,n,min) == true)
    {
        min++;
    }
    printf("%d", min);
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
    employeeID(arr, n);
}
