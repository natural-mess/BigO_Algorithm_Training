#include <bits/stdc++.h>
using namespace std;

char originString[101];
char evenString[51];

int main()
{
    cin.getline(originString, 101);
    int index = 0;
    for (int i = strlen(originString)-1; i >=0 ; i--)
    {
        if (i%2!=0)
        {
            evenString[index] = originString[i];
            index++ ;
        }
    }
    // cout << evenString << endl;
    
    index = 0;
    for (int i = 0; i < strlen(originString); i++)
    {
        if (i%2 != 0)
        {
            cout << evenString[index];
            index++;
        }
        else
        {
            cout << originString[i];
        }
    }
    return 0;
}