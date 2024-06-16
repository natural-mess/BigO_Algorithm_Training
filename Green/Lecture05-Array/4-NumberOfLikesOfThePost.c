#include <stdio.h>
#include <stdbool.h>

bool NumberOfLikesOfThePost (int arr[], int n)
{
    bool ret = true;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            ret = false;
            break;
        }
    }
    return ret;
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
    (NumberOfLikesOfThePost(arr, n) == true) ? (printf("YES")) : (printf("NO"));
}
