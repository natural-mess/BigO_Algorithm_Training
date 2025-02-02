#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    map<string, int> m;
    string input1, input2, input3;
    
    map<string, int>::iterator it;
    vector<int> graph[302];
    int j = 1;
    // pair<string, int> p("Isenbaev", 0);
    // m.insert(p);
    // j++;

    for (int i = 0; i < n; i++)
    {
        cin >> input1 >> input2 >> input3;
        it = m.find(input1);
        if (it == m.end())
        {
            pair<string, int> p(input1, j++);
            m.insert(p);
        }

        it = m.find(input2);
        if (it == m.end())
        {
            pair<string, int> p(input2, j++);
            m.insert(p);
        }

        it = m.find(input3);
        if (it == m.end())
        {
            pair<string, int> p(input3, j++);
            m.insert(p);
        }

        graph[m[input1]].push_back(m[input2]);
        graph[m[input2]].push_back(m[input1]);
        graph[m[input3]].push_back(m[input2]);
        graph[m[input2]].push_back(m[input3]);
        graph[m[input1]].push_back(m[input3]);
        graph[m[input3]].push_back(m[input1]);
    }

    bool visited[302];
    memset(visited, false, sizeof(visited));
    int dist[302];
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    it = m.find("Isenbaev");
    if (it != m.end())
    {
        q.push(m["Isenbaev"]);
        visited[m["Isenbaev"]] = true;
        dist[m["Isenbaev"]] = 0;
    }

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int i = 0; i < graph[x].size(); i++)
        {
            int k = graph[x][i];
            if (!visited[k])
            {
                visited[k] = true;
                dist[k] = dist[x]+1;
                q.push(k);
            }
        }
    }

    for (it = m.begin(); it != m.end(); it++)
    {
        if (dist[it->second] == -1)
        {
            cout << it->first << " " << "undefined" << endl;
        }
        else
        {
            cout << it->first << " " << dist[it->second] << endl;
        }
    }
    

    return 0;
}