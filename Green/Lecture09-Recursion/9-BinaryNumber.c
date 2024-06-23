#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char binary[2000];
char result[2000];
int count=0;

void binaryNumber(int num)
{
    if ((num&1)==1)
    {
        strcat(binary, "1");
    }
    else
    {
        strcat(binary, "0");
    }
    count++;
    num=num>>1;
    if (num==0)
    {
        for (int i=count-1; i>=0; i--)
        {
            result[num] = binary[i];
            num++;
        }
        //result[num] = '0';
        return;
    }
    return binaryNumber(num);
}

int main()
{
    int n;
    (void)scanf("%d", &n);
    
    binaryNumber(n);
    printf("%s", result);
}