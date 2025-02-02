#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main()
{
    int n;
    scanf("%d",&n);
    char magnetFlag = 0;
    int count=0;

    char arr[n][2];
    for (int i = 0; i < n; i++)
    {
        scanf(" %[^\n]%*c", arr[i]);
    }
    // printf("%s", arr[0]);
    
    for (int i = 0; arr[i][0]!='\0'; i++)
    {
        if (arr[i][1] == arr[i+1][0])
        {
            count++;
        }
    }
    printf("%d", count+1);
}