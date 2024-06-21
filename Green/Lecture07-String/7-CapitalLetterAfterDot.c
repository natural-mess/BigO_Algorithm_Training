#include <stdio.h>

#define size 2000

int main()
{
    char str[size];

    (void)fgets(str, sizeof(str), stdin);

    for (size_t i = 0; str[i] != '\n'; i++)
    {
        if (str[i] == '.' && str[i+1]==' ' && str[i+2]>96 && str[i+2]<123)
        {
            str[i+2]=str[i+2]-32;
        }
    }
    
    // for (size_t i = 0; str[i] != '\n'; i++)
    // {
    printf("%s", str);
    // }
    
    return 0;
}
