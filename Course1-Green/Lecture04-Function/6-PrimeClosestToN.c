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

int primeClosest(int n)
{
    int primeClosest, upper, lower;
    if (checkPrime(n) == true)
    {
        primeClosest = n;
    }
    else
    {
        lower=n;
        while (checkPrime(lower) != true)
        {
            lower--;
        }
        
        upper=n;
        while (checkPrime(upper) != true)
        {
            upper++;
        }
        
        if ((n-lower) <= (upper-n))
        {
            primeClosest = lower;
        }
        else if ((n-lower) > (upper-n))
        {
            primeClosest = upper;
        }
    }
    return primeClosest;
}

int main()
{
    int x;
    scanf("%d", &x);
    printf("%d\n", primeClosest(x));
    return 0;
}
