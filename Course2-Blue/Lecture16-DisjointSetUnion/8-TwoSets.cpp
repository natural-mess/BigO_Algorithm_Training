#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int n, a, b, p[MAX], fa[MAX];
map<int, int> mp;

// Union Find with Compression Path
int findSet(int x)
{
    if (fa[x] != x)
        fa[x] = findSet(fa[x]);
    return fa[x];
}

// Normal Union without Weighted Path
void unionSet(int u, int v)
{
    int uu = findSet(u);
    int vv = findSet(v);
    if (uu != vv)
        fa[uu] = v;
}

int main()
{
    if (scanf("%d%d%d", &n, &a, &b) == 3)
    {
        int Max = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &p[i]);
            mp[p[i]] = i;   
            Max = max(Max, p[i]);
        }
        if (Max >= max(a, b))
            printf("NO\n");
        else
        {
            for (int i = 0; i <= n + 1; i++)
            {
                fa[i] = i;
            }
            for (int i = 1; i <= n; i++)
            {
                if (mp[a - p[i]])
                    unionSet(i, mp[a - p[i]]);
                else
                    unionSet(i, n + 1);
                if (mp[b - p[i]])
                    unionSet(i, mp[b - p[i]]);
                else
                    unionSet(i, 0);
            }
            int A = findSet(0);
            int B = findSet(n + 1);
            if (A != B)
            {
                printf("YES\n");
                for (int i = 1; i <= n; i++)
                {
                    if (i != 1)
                        printf(" ");
                    if (findSet(i) == A)
                        printf("0");
                    else
                        printf("1");
                }
                printf("\n");
            }
            else
                printf("NO\n");
        }
    }
    return 0;
}