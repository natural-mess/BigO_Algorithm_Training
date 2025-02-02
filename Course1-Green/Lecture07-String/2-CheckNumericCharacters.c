#include <stdio.h>

int main()
{
    char str[1001];
    int countNum=0;
    int i=0;
    fgets(str, 1001, stdin); 
    //gets(str);
    //scanf("%[^\n]%*c", str);
    str[1000] = '\0';

    while(str[i]!='\0')
    {
        if ((str[i]>='0') && (str[i]<='9'))
        {
            countNum++;
        }
        i++;
    }

    printf("%d", countNum);

    return 0;
}
