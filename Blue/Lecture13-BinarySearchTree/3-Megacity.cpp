// tinh khoang cach tu diem (0,0) toi cac diem diem con lai
// luu vao cay nhi phan
// cay nhi phan se tu sap xep tu nho den lon
// tim ban kinh toi thieu
#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x,y, population;
    double distance() const
    {
        return sqrt(x*x*1.0 + y*y*1.0);
    }
};

int main()
{
    int n, k;
    multimap<double, int> coor;
    cin >> n >> k;
    int xi, yi, ki;
    int total = k;
    for (int i = 0; i < n; i++)
    {
        cin >> xi >> yi >> ki;
        double distance = sqrt(xi*xi*1.0 + yi*yi*1.0);
        coor.insert({distance, ki});
        total = total + ki;
    }

    if (total < 1000000)
    {
        cout << -1 << endl;
        return 0;
    }

    multimap<double, int>::iterator it;
    double left = 0.0, right = 1e5;
    double epsilon = 1e-7;
    int totalPopulation;
    bool flag;
    double mid;
    while (right-left >= epsilon)
    {
        mid = (left+right)/2.0;
        totalPopulation = k;
        flag = false;
        for (auto it = coor.begin(); it != coor.end(); ++it) 
        {
            if (it->first > mid) 
                break;
            totalPopulation += it->second;
            if (totalPopulation >= 1000000) 
                flag = true;
        }
        if (flag)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }

    cout << fixed << setprecision(7) << mid << endl;

    return 0;
}
