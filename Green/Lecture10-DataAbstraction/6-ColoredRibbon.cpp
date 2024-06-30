#include<bits/stdc++.h>
using namespace std;

typedef struct
{
    int colorCode;
    int length;
    int quantity = 1;
} ribbon;

void insertAsc(int x, int y, int z, ribbon *a, int n)
{
    for (int j = n; j >= 0; --j)
    {
        if (a[j - 1].colorCode <= x)
        {
            a[j].colorCode = x;
            a[j].length = y;
            a[j].quantity = z;
            return;
        }
        else
            a[j].colorCode = a[j - 1].colorCode;
            a[j].length = a[j - 1].length;
            a[j].quantity = a[j - 1].quantity;
    }
}


int main()
{
    int n;
    cin >> n;
    ribbon arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].colorCode >> arr[i].length;
    }
    ribbon ans[n];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((arr[i].colorCode == arr[j].colorCode) && (i!=j) && arr[j].colorCode!=0)
            {
                arr[i].length = arr[i].length + arr[j].length;
                arr[i].quantity++;
                arr[j].colorCode = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i].colorCode!=0)
        {
            ans[count] = arr[i];
            count++;
        }
    }
    cout << count << endl;
    for (int i = 1; i < count; i++)
    {
        int color=ans[i].colorCode;
        int length = ans[i].length;
        int quantity = ans[i].quantity;
        insertAsc(color, length, quantity , ans, i);
    }
    
    for (int i = 0; i < count; i++)
    {
        if (ans[i].colorCode!=0)
        {
            cout << ans[i].colorCode << ' ' << ans[i].length << ' ' << ans[i].quantity << endl;
        }
    }

    return 0;
}
