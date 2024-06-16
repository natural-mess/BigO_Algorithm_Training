#include <stdio.h>
#include <stdbool.h>

void manageLALA(int arr[], int n)
{
    bool check = true;
    int count0=0;
    if (arr[n-1] == 0)
    {
        check = false;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i]==1)
            {
                count0=0;
            }
            else
            {
                count0++;
            }
            if (count0 > 3)
            {
                check = false;
                break;
            }
        }
    }
    
    (check==true) ? (printf("YES")) : (printf("NO"));
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
    manageLALA(arr, n);
}
