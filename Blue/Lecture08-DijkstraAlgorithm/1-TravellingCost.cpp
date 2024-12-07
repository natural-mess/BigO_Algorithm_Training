#include <bits/stdc++.h>
using namespace std;

#define MAX 500
const int INF = 1e9;
vector<vector<pair<int, int>>> graph;
vector<int> dist(MAX, INF);
int path[MAX];

struct option
{
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const
    {
        return a.second > b.second;
    }
};


int main()
{
    
    return 0;
}
