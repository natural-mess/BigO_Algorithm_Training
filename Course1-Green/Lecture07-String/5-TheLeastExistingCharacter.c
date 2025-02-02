#include <stdio.h>
#include <stdbool.h>

#define size 1002

typedef struct
{
    char letter;
    int count;
} leastExistCharStruct_t;

leastExistCharStruct_t storage[size];

void initStorage(void)
{
    for (size_t i = 0; i < size; i++)
    {
        storage[i].count = 0;
        storage[i].letter = 0;
    }
}

bool findElement(leastExistCharStruct_t arr[], int n, int element)
{
    int count = 0;
    bool ret;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i].letter==element)
        {
            count++;
        }
    }
    (count==0)? (ret=false) : (ret = true);
    return ret;
}

int main()
{
    int n;
    scanf("%d\n", &n);

    char str[n][size];
    char acceptFlg = 0;
    int indexStorage = 0;
    char result[n];
    int indexResult = 0;
    int minCount, minLetter;

    // for (int i = 0; i < n; i++)
    // {
    //     scanf(" %[^\n]%*c",str[i]);
    // }
    
    size_t indexStr = 0;

    while( indexStr < n && fgets( str[indexStr], sizeof( *str ), stdin ) != NULL ) ++indexStr;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; str[i][j]!='\n'; j++)
        {
            if (findElement(storage, size, str[i][j]) == false)
            {
                if (str[i][j] > 91)
                {
                    storage[indexStorage].letter = str[i][j] - 32;
                }
                else
                {
                    storage[indexStorage].letter = str[i][j];
                }
                for (size_t p = 0; str[i][p]!='\n'; p++)
                {
                    if((storage[indexStorage].letter == (str[i][p]-32)) || (storage[indexStorage].letter == str[i][p]))
                    {
                        storage[indexStorage].count++;
                    }
                }
                indexStorage++;
            }
        }
        minCount = storage[0].count;
        minLetter = storage[0].letter;
        for (size_t q = 1; q < indexStorage; q++)
        {
            if ((minCount>=storage[q].count) && (minLetter>storage[q].letter))
            {
                minCount = storage[q].count;
                minLetter = storage[q].letter;
            }
            else if ((minLetter<storage[q].letter) && (minCount>storage[q].count))
            {
                minCount = storage[q].count;
                minLetter = storage[q].letter;
            }
        }
        result[indexResult] = minLetter;
        indexResult++;
        initStorage();
        indexStorage=0;
    } 

    //printf("%d\n", indexResult);

    for (size_t j = 0; j < indexResult; j++)
    {
        printf("%c\n", result[j]);
    }
    
}
