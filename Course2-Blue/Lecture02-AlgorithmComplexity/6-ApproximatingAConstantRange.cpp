/*
Approximating a Constant Range - L2

#include<bits/stdc++.h>
using namespace std;
multiset<int> s;
int a[100005];
int main()
{
  int n;
  cin >> n;
  int st = 0;
  auto mn = 0, mx = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 0; i < n; ++i)
  {
    s.insert(a[i]);
    mn = (*s.begin());
    mx = (*s.rbegin());
    
    int diff = mx - mn;
    
    while (diff > 1)
    {
      s.erase(s.find(a[st]));
      st++;
      mn = (*s.begin());
      mx = (*s.rbegin());
      diff = mx - mn;
    }
    ans = max(i - st + 1, ans);
  }
  cout << ans;
}
*/
#include <bits/stdc++.h>
using namespace std;

multiset<int> s;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int st = 0;
    auto l = 0, r = 0;
    auto diff = 0;
    int ans = 0;
    s.insert(a[st]);
    for (int i = 1; i < n; i++)
    {
        s.insert(a[i]);
        l = *s.begin();
        r = *s.rbegin();

        diff = r-l;
        while (diff > 1)
        {
            s.erase(s.find(a[st]));
            st++;
            l = *s.begin();
            r = *s.rbegin();
            diff = r - l;
        }
        ans = max(i-st+1, ans);
    }
    cout << ans;
    return 0;
}