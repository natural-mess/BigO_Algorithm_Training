#include <stdio.h>

void schoolTrip (int arr[], int n)
{
    int count0=0, count1=0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count0++;
        }
        else if (arr[i] == 1)
        {
            count1++;
        }
    }
    (count0==count1) ? (printf("YES")) : (printf("NO"));
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
    schoolTrip(arr, n);
}

