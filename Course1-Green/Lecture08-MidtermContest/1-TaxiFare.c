#include <stdio.h>
#include <stdlib.h>

int main()
{
    int km, fare;
    scanf("%d", &km);

    if (km == 1)
    {
        fare = 15000;
    }
    else if (km>1 && km <6)
    {
        fare = 15000 + (km-1)*13500;
    }
    else if (km>5 && km<12)
    {
        fare = 15000 + 13500*4 + (km-5)*11000;
    }
    else if (km>=12)
    {
        fare = (15000 + 13500*4 + (km-5)*11000) * 0.9;
    }
    printf("%d", fare);
}