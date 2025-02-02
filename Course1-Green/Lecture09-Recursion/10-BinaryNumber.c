#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int zero=0;

void binaryNumber(int num)
{
    if (num==0 && zero==1)
    {
        return;
    }
    zero=1;
    binaryNumber(num/2);
    printf("%d",num%2);
}

int main()
{
    int n;
    (void)scanf("%d", &n);
    
    binaryNumber(n);
}

// #include<bits/stdc++.h>
// using namespace std;
// int n;

// string binary(int n)
// {
//     if (n == 0)
//         return "0";
//     if (n == 1)
//         return "1";
//     return binary(n/2) + ((n % 2) == 1 ? "1" : "0");
// }

// int main()
// {
//     cin >> n;
//     cout << binary(n);
// }