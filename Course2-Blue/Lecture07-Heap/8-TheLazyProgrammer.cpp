#include <bits/stdc++.h>
using namespace std;

// sort input theo d
// tao mot bien ThoiGianHienTai = 0, ví dụ công việc cần thời gian b là 30 thì ThoiGianHienTai += 30
// nếu ThoiGianHienTai khong vuot qua d thi push vao heap sort theo a
// neu ThoiGianHienTai vuot qua d thi lay ra phan tu co a lon nhat trong heap, tinh xem can bao nhieu thoi gian de hoan thanh cong viec do truoc dealine 
// bang cach lay ThoiGianHienTai - deadline
// duoc bao nhieu thi dem chia cho a cua cong vien dau tien, lay ket qua nhan voi a cua cong vien dau tien, roi lay b cong vien dau tien tru a cong vien dau tien
// ra ket qua la so thoi gian can tru di tu b cong vien dau tien, cap nhat lai b roi push vao lai heap
// lan tiep theo, phai xet xem cong vien dau tien con tra duoc bao nhieu bang cach lay b/a * a, roi lay ThoiGianHienTai - deadline - ketqua
// neu khong du thi lai lay tiep tu trong heap ra.

struct lazyProgrammer
{
    int a, b, d;
};

struct CompareDescending
{
    bool operator()(lazyProgrammer p1, lazyProgrammer p2) const
    {
        return p1.a < p2.a; // decreasing order following `first`
    }
};

struct CompareAscending
{
    bool operator()(lazyProgrammer p1, lazyProgrammer p2) const
    {
        return p1.d > p2.d; // increasing order following `first`
    }
};

int main()
{
    int t;
    cin >> t;
    priority_queue<lazyProgrammer, vector<lazyProgrammer>, CompareDescending> q_max_a;
    priority_queue<lazyProgrammer, vector<lazyProgrammer>, CompareAscending> q_min_deadline;
    while (t--)
    {
        int n;
        int time = 0;
        double money = 0.0;
        cin >> n;
        lazyProgrammer data;
        for (int i = 0; i < n; i++)
        {
            cin >> data.a >> data.b >> data.d;
            q_min_deadline.push(data);
        }

        while (!q_min_deadline.empty())
        {
            lazyProgrammer currentJob = q_min_deadline.top();
            q_min_deadline.pop();
            time = time + currentJob.b;
            q_max_a.push(currentJob);

            while (time > currentJob.d)
            {
                lazyProgrammer jobWithBig_a = q_max_a.top();
                q_max_a.pop();

                if (jobWithBig_a.b > (time - currentJob.d))
                {
                    // new time for jobWithBig_a will be jobWithBig_a.b - (time - currentJob.d)
                    // so jobWithBig_a.b - jobWithBig_a.a * money = jobWithBig_a.b - (time - currentJob.d)
                    money = money + ((time - currentJob.d) * (1.0 / jobWithBig_a.a));
                    // update new b for jobWithBig_a
                    jobWithBig_a.b = jobWithBig_a.b - (time - currentJob.d);
                    q_max_a.push(jobWithBig_a);
                    // time = time - (time - currentJob.d)
                    time = currentJob.d;
                }
                else
                {
                    money = money + (jobWithBig_a.b * (1.0 / jobWithBig_a.a));
                    time = time - jobWithBig_a.b;
                    jobWithBig_a.b = 0;
                }
            }
        }
        cout << fixed << setprecision(2) << money << endl;
        while (!q_max_a.empty())
        {
            q_max_a.pop();
        }
    }
    return 0;
}