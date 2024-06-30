#include<bits/stdc++.h>
using namespace std;

typedef struct 
{
    int x;
    int y;
} point2D;

typedef struct 
{
    point2D a,b,c;
} triangles;

double distance (point2D A, point2D B)
{
    return sqrt(pow(abs(A.x-B.x), 2.00) + pow(abs(A.y-B.y), 2.00));
}

double halfP (triangles A)
{
    return ((distance(A.a,A.b) + distance(A.b, A.c) + distance(A.c, A.a))/2.00);
}

double area (triangles A)
{
    return sqrt(halfP(A) * (halfP(A) - distance(A.a,A.b)) * (halfP(A) - distance(A.b, A.c)) * (halfP(A) - distance(A.c, A.a)));
}

int main()
{
    int n;
    double sum = 0;
    cin >> n;
    triangles arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].a.x >> arr[i].a.y;
        cin >> arr[i].b.x >> arr[i].b.y;
        cin >> arr[i].c.x >> arr[i].c.y;
        sum = sum + area(arr[i]);
    }
    cout << fixed << setprecision(2) << sum;
    

    return 0;
}
