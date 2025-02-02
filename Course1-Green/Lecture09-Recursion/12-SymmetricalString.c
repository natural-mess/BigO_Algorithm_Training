#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char temp[100001];
int indexTemp=0;

int symmetricalString(char arr[], int n)
{
    temp[indexTemp] = arr[n];
    if (temp[indexTemp] != arr[indexTemp])
    {
        return 0;
    }
    if (n==0)
    {
        return 1;
    }
    indexTemp++;
    return symmetricalString(arr, n-1);
}

int main()
{
    int n;
    (void)scanf("%d", &n);
    char str[n];

    scanf(" %[^\n]%*c", str);
    
    (symmetricalString(str, n-1)==1) ? printf("YES") : printf("NO");
}