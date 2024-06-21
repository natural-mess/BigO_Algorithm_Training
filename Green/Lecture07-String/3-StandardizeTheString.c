#include <stdio.h>

int main()
{
    int size = 1001;
    char str[size];
    char temp[size];
    int countNum=0;
    int i=0;
    int k=0;
    char spaceFlag = 1;
    fgets(str, size, stdin); 
    //gets(str);
    //scanf("%[^\n]%*c", str);
    str[size-1] = '\0';

    // for (int j = 0; str[j]!='\0'; j++)
    // {
    //     printf("%c", str[j]);
    //     printf("%d",j);
    // }

    while(str[i]!='\0')
    {
        if(i==0 && str[i]==' ')
        {
            for (int j = 0; str[j]!='\0'; j++)
            {
                if (str[j]!=' ')
                {
                    i++;
                    break;
                }
            }
        }
        else
        {
            if (str[i]!=' ' && str[i]!='\n')
            {
                if (spaceFlag==1)
                {
                    spaceFlag = 0;
                }
                temp[k] = str[i];
                k++;
            }
            else if (str[i]==' ' && spaceFlag!=1)
            {
                spaceFlag = 1;
                temp[k] = str[i];
                //temp[k] = '*';
                k++;
            }
            i++;
        }
        
    }
    if (spaceFlag == 1)
    {
        k=k-1;
        temp[k] = '\0';
    }
    else
    {
        temp[k] = '\0';
    }
    
    //printf("%d\n",k);

    // for (int j = (k-1); temp[j]==' '; j--)
    // {
    //     if (temp[j]!=' ')
    //     {
    //         temp[j+1]='\0';
    //         break;
    //     }
    // }
    
    for (int j = 0; temp[j]!='\0'; j++)
    {
        printf("%c", temp[j]);
        //printf("%d",j);
    }

    return 0;
}
