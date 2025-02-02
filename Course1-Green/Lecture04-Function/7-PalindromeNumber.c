#include <stdio.h>
#include <stdbool.h>

int numDigit(int x)
{
    int count = 1;
    while(x/10!=0)
    {
        x=x/10;
        count++;
    }

    return count;
}

int powCal(int x,int n)
{
    int number = 1;

    for (int i = 0; i < n; i++)
    {
        number = number*x;
    }

    return number;
}

bool Palindrome(int x)
{
    bool ret;
    int left, right, tempL = x, tempR = x, count = 0;
    int digit = numDigit(x);
    for (int i=1; i<=(digit/2); i++)
    {
        left = tempL/(powCal(10,(digit-i)));
        tempL = x%(powCal(10,(digit-i)));
        right = tempR%10;
        tempR = tempR/10;
        if (left == right)
        {
            count++;
        }
    }
    (count == (digit/2)) ? (ret = true) : (ret = false);
    return ret;
}

int main()
{
    int x;
    scanf("%d", &x);
    // printf("%d\n", powCal(10,3));
    // printf("%d\n", numDigit(x));
    (Palindrome(x) == true) ? printf("YES\n") : printf("NO\n");
    return 0;
}