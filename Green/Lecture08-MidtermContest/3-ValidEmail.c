#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define size 1001

int main()
{
    char str[size];
    scanf(" %[^\n]%*c", str);
    char at = 64;
    int posAt = 0;
    char dot = 46;
    char dotFlag = 0;
    char underscore = 95;
    char valid[] = "VALID";
    char invalid[] = "INVALID";
    char *result = valid;

    bool localGood=true;

    for (int i = 0; str[i]!='\0'; i++)
    {
        if (str[i] == 64)
        {
            posAt = i;
            break;
        }
    }

    if (posAt == 0)
    {
        result = invalid;
    }
    else
    {
        for (int i = 0; i < posAt; i++)
        {
            if (str[i]<46 || str[i]==47 || (str[i]>57 && str[i]<65) || (str[i]>91 && str[i]<94) || (str[i]==96) || str[i]>122 || str[i]==' ')
            {
                result = invalid;
                localGood = false;
                break;
            }
        }
        if (localGood==true)
        {
            for (int i = posAt+1; str[i]!='\0'; i++)
            {
                if ((str[i]<46 || (str[i]>46 && str[i]<65) || (str[i]>90 && str[i]<97) || str[i]>122))
                {
                    result = invalid;
                    localGood = false;
                    break;
                }
                if (str[i]==46 && str[i+1]==46)
                {
                    result = invalid;
                    break;
                }
                if (str[i]==46 && dotFlag==0)
                {
                    dotFlag = 1;
                }
            }
            if (dotFlag==0)
            {
                result = invalid;
            }
        }
        
    }

    printf("%s", result);

}