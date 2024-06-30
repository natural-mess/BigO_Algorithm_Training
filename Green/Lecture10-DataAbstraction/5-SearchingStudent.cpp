#include<bits/stdc++.h>
using namespace std;

typedef struct 
{
    int maso;
    double diemToan;
    double diemVan;
} student;

int main()
{
    int n, q;
    cin >> n >> q;

    student arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].maso >> arr[i].diemToan >> arr[i].diemVan;
    }

    int truyvan[q];
    for (int i = 0; i < q; i++)
    {
        cin >> truyvan[i];
    }

    for (int i=0; i<q; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j].maso == truyvan[i])
            {
                cout << fixed << setprecision(2) << arr[j].diemToan << ' ' << arr[j].diemVan << endl;
                break;
            }
        }
    }
    return 0;
}
