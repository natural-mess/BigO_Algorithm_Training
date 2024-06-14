#include <stdio.h>

int main()
{
    unsigned int a, b, tiendien;
    scanf("%d %d", &a, &b);
    unsigned int dienSuDung = b-a;
    
    if (dienSuDung<=50) 
    {
        tiendien=dienSuDung*1484;
    } 
    else if (dienSuDung>50 && dienSuDung<=100) 
    {
        tiendien=(50*1484+(dienSuDung-50)*1533);
    } 
    else if (dienSuDung>100 && dienSuDung<=200) 
    {
        tiendien=(50*1484+50*1533+(dienSuDung-100)*1786);
    } 
    else if (dienSuDung>200 && dienSuDung<=300) 
    {
        tiendien=(50*1484+50*1533+100 * 1786 + (dienSuDung-200)*2242);
    } 
    else if (dienSuDung>300 && dienSuDung<=400) 
    {
        tiendien=(50*1484+50*1533+100*1786+100*2242+(dienSuDung-300)*2503);
    } 
    else 
    {
        tiendien=(50*1484+50*1533+100*1786+100*2242+100*2503+(dienSuDung-400)*2587);
    }

    tiendien = tiendien*1.1;
    printf("%d\n", tiendien);

    return 0;
}