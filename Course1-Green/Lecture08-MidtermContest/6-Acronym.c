#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define size 1001

int main()
{
    char str[size];
    char result[size];
    scanf(" %[^\n]%*c", str);
    int resultIndex = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (i == 0)
        {
            if (str[i] > 90)
            {
                result[resultIndex] = str[i] - 32;
            }
            else
            {
                result[resultIndex] = str[i];
            }
            resultIndex++;
        }
        else
        {
            if (str[i] == ' ')
            {
                if (str[i + 1] > 90)
                {
                    result[resultIndex] = str[i + 1] - 32;
                }
                else
                {
                    result[resultIndex] = str[i + 1];
                }

                resultIndex++;
            }
        }
    }
    result[resultIndex] = '\0';
    printf("%s", result);
}