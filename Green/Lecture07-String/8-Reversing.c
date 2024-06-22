#include <stdio.h>

#define size 2000

void initArray (char* arr, int n)
{
    for (int k = 0; k < n; k++)
    {
        arr[k] = 0;
    }
}

int main()
{
    char str[size];
    char result[size];
    char storage[50];
    int countletter = 0;
    int countword = 0;
    int indexResult=0;

    // (void)fgets(str, sizeof(str), stdin);
    scanf(" %[^\n]%*c", str);

    for (int i = 0; str[i]!='\0'; i++)
    {
        countletter++;
    }

    // printf("%d", countletter);
    
    for (int i = (countletter-1); i>=0; i--)
    {
        if (i==0 && indexResult==0)
        {
            for (int p = 0; (str[p] != '\0'); p++)
            {
                result[indexResult] = str[p];
                indexResult++;
            }
        }
        else if (i==0 && indexResult!=0)
        {
            for (int p = 0; (str[p] != ' '); p++)
            {
                result[indexResult] = str[p];
                indexResult++;
            }
        }
        else if (str[i]!=' ')
        {
            storage[countword] = str[i];
            countword++;
        }
        else
        {
            for (int j=(countword-1); j>=0; j--)
            {
                result[indexResult] = storage[j];
                indexResult++;
            }
            result[indexResult] = ' ';
            indexResult++;
            initArray(storage, countword);
            countword=0;
        }
        
    }
    //result[indexResult] = '\0';
    for (int i = 0; i < indexResult; i++)
    {
        printf("%c", result[i]);
    }
    
    //puts(result);
    //printf("%s", result);
    // storage[countword] = '\0';
    // printf("%s", storage);
    // printf("\n");

    return 0;
}
