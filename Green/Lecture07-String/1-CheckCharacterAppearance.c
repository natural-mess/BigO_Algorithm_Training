#include <stdio.h>

int main()
{
    char str[1000];
    fgets(str, 1000, stdin); 

    char check=0;

    int i=0;
    while (str[i] != '\0') 
    {
        if ((str[i] == 'b') || (str[i] == 'B') || (str[i] == 'i') || (str[i] == 'I') || (str[i] == 'g') || (str[i] == 'G') || (str[i] == 'o') || (str[i] == 'O'))
        {
            check = 1;
            break;
        }
        i++;
    }

    (check==1) ? (printf("YES")) : (printf("NO"));

    return 0;
}
