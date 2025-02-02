#include <bits/stdc++.h>
using namespace std;

// tao 1 pair
// voi moi hoa don, push vao queue so tien va so thu tu nhap cua so tien do, vi du {1, 1}, {2, 2}, {3, 3}, {1, 4}
// pop 1 phan tu tu queue ra thi danh dau so thu tu nhap cua phan tu do la true
// truoc khi pop, kiem tra xem marker cua so thu tu nhap do co la false khong, neu la false thi lay duoc, neu khong thi bo qua

struct CompareDescending {
    bool operator()(const pair<long, long>& p1, const pair<long, long>& p2) const 
    {
        return p1.first < p2.first;  // decreasing order following `first`
        
    }
};

struct CompareAscending {
    bool operator()(const pair<long,long>& p1, const pair<long,long>& p2) const
    {
        return p1.first > p2.first; // increasing order following `first`
        
    }
};

int main()
{
    long long n;
    cin >> n;

    long long k;
    long long sum = 0;
    long long x;
    pair<long, long> big, small;

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, CompareDescending> q_max;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, CompareAscending> q_min;

    long long count = 0;
    pair <long long, long long> customer;

    long long counter=0;
    bool marker[1000002] = {false};
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        
        for (int j = 0; j < k; j++)
        {
            cin >> x;
            counter++;
            q_max.push({x, counter});
            q_min.push({x, counter});
        }
        while (marker[q_max.top().second] == true)
        {
            q_max.pop();
        }
        while (marker[q_min.top().second] == true)
        {
            q_min.pop();
        }
        big = q_max.top();
        q_max.pop();
        small = q_min.top();
        q_min.pop();
        sum += (big.first - small.first);
        marker[big.second] = true;
        marker[small.second] = true;
    }
    cout << sum << endl;
    return 0;
}