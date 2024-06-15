#include <stdio.h>
#include <stdbool.h>

bool checkPrime(int x)
{
    bool ret;
    int count = 0;
    if (x==1)
    {
        ret = false;
    }
    else
    {
        for (int i=2; i<x; i++)
        {
            if (x%i==0)
            {
                count++;
            }
        }
        (count==0)? (ret = true) : (ret = false);
    }
    return ret;
}

int sumOfPrime(int x)
{
    int sum = 0;
    for (int i=0; i<x; i++)
    {
        if (checkPrime(i) == true)
        {
            sum = sum+i;
        }
    }
    return sum;
}

int main()
{
    int x;
    scanf("%d", &x);
    printf("%d\n", sumOfPrime(x));
    return 0;
}
