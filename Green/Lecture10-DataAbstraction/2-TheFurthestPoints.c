#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct 
{
    int x;
    int y;
} point2D;

double distance (point2D A, point2D B)
{
    return sqrt(pow(abs(A.x-B.x), 2) + pow(abs(A.y-B.y), 2));
}

int main()
{
    point2D M;
    scanf("%d %d", &M.x, &M.y);
    int n;
    scanf("%d", &n);
    point2D arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }
    point2D ans = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (distance(arr[i], M) > distance(ans, M))
        {
            ans = arr[i];
        }
    }
    
    printf("%d %d", ans.x, ans.y);
    return 0;
}