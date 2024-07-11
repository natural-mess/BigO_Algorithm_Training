#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    char studentID[6];
    double grade;
} student;

void merge(student a[], int l, int r)
{
    student temp[r + 1];
}

void mergeSort(student a[], int l, int r)
{
    if (l < r)
    {
        return;
    }
    int mid = l + (r - l) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
}

int main()
{
    int n, k;
    cin >> n >> k;
    student listStudent[n];
    for (int i = 0; i < n; i++)
    {
        cin >> listStudent[i].studentID >> listStudent[i].grade;
    }
}