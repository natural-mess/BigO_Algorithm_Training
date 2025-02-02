#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int car_id;
    int time;
}car;

car inputCar;

int main()
{
    int c, n, t, m;
    cin >> c;

    while (c>0)
    {
        c--;
        cin >> n >> t >> m;
        queue <car> left, right;
        string in;
        int res[m];
        int time;
        int cur = -1;
        int side = 0;
        int n_car = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> time >> in;
            inputCar.car_id = i;
            inputCar.time = time;
            if (in[0] == 'l')
            {
                left.push(inputCar);
            }
            else
            {
                right.push(inputCar);
            }
        }
        int nx;
        while (left.size() > 0 || right.size() > 0)
        {
            if (left.empty())
            {
                nx = right.front().time;
            }
            else if (right.empty())
            {
                nx = left.front().time;
            }
            else
            {
                nx = min(left.front().time, right.front().time);
            }
            if (cur < nx)
            {
                cur = nx;
            }
            car tempCar;
        
            if (n_car>0)
            {
                n_car = 0;
            }
            if (side == 0)
            {
                while (left.size() > 0 && n_car<n)
                {
                    tempCar = left.front();
                    if (tempCar.time <= cur)
                    {
                        left.pop();
                        res[tempCar.car_id] = cur + t;
                        n_car++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                while (right.size() > 0 && n_car<n)
                {
                    tempCar = right.front();
                    if (tempCar.time <= cur)
                    {
                        right.pop();
                        res[tempCar.car_id] = cur + t;
                        n_car++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            cur += t;
            side = 1-side;
        }
        
        while (!left.empty())
        {
            left.pop();
        }
        while (!right.empty())
        {
            right.pop();
        }
        for (int i = 0; i < m; i++)
        {
            cout << res[i] << endl;
        }
        if (c!=0)
        {
            cout << endl;
        }
    }


    return 0;
}