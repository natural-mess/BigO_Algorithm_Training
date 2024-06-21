#include <stdio.h>

int main()
{
    int size = 1001;
    int n;
    scanf("%d", &n);
    char str[n][size];
    char spaceFlag = 0;
    
    for (int i = 0; i < n; i++)
    {
        scanf(" %[^\n]%*c",str[i]);
    }
    
    // size_t i=0;
    // while ((i<n) && (fgets(str[i], sizeof(*str), stdin)!= NULL))
    // {
    //     i++;
    // }

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; str[i][j]!='\0'; j++)
        {
            if (j==0 && (str[i][j]>91))
            {
                str[i][j] = str[i][j] - 32;
            }
            else if (j!=0)
            {
                if (str[i][j] == ' ')
                {
                    spaceFlag = 1;
                }
                else if ((str[i][j] != ' ') && (spaceFlag ==0) && (str[i][j]<91))
                {
                    str[i][j] = str[i][j] + 32;
                }
                else if ((str[i][j] != ' ') && (spaceFlag ==1) && (str[i][j]>91))
                {
                    str[i][j] = str[i][j] - 32;
                    spaceFlag = 0;
                }
                else if ((str[i][j] != ' ') && (spaceFlag ==1) && (str[i][j]<91))
                {
                    spaceFlag = 0;
                }
            }
        }
        
    }

    for (size_t j = 0; j < n; j++)
    {
        printf("%s", str[j]);
        printf("\n");
    }
    
}
