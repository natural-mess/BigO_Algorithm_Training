#include <stdio.h>
#include <stdbool.h>

#define size 2000

bool findElement(char arr[], int n, int element)
{
    bool ret = false;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i]==element)
        {
            ret = true;
            break;
        }
    }
    return ret;
}

int main()
{
    char storage[size];
    char str[size];
    int indexStorage = 0;

    (void)fgets(str, sizeof(str), stdin);

    for (size_t i = 0; str[i] != '\n'; i++)
    {
        if (findElement(storage, indexStorage, str[i]) == false)
        {
            storage[indexStorage] = str[i];
            indexStorage++;
        }
    }
    storage[indexStorage] = '\0';
    printf("%d", indexStorage);
    return 0;
}
