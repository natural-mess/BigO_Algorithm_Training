#include<bits/stdc++.h>
using namespace std;

typedef struct 
{
    char name[101];
    double diemToan;
    double diemVan;
} student;

double diemTrungBinh (student A)
{
    return ((A.diemToan+A.diemVan)/2.00);
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    student arr[n];
    for (int i = 0; i < n; i++)
    {
        cin.getline(arr[i].name, 101);
        cin >> arr[i].diemToan >> arr[i].diemVan;
        cin.ignore();
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (diemTrungBinh(arr[i]) >= 9.00)
        {
            count++;
        }
    }
    cout << count;
    return 0;
}
