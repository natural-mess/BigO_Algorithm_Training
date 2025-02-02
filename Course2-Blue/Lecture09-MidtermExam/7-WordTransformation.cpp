#include <bits/stdc++.h>
using namespace std;

vector<int> graph[202];
int visited[202];

int main()
{
    int n;
    cin >> n;
    //cout << endl;

    while (n--)
    {
        vector<string> data;
        string dataInput;

        while (1)
        {
            cin >> dataInput;
            if (dataInput == "*")
            {
                break;
            }
            data.push_back(dataInput);
        } //while (dataInput != "*\0");
        // for (int i = 0; i < data.size(); i++)
        // {
        //     cout << data[i] << endl;
        // }

        for (int i = 0; i < 202; i++)
        {
            graph[i].clear();
        }
        
        char flag;
        for (int i = 0; i < data.size()-1; i++)
        {
            for (int j = i+1; j < data.size(); j++)
            {
                if(data[i].length() == data[j].length())
                {
                    flag = 0;

                    for (int k = 0; k < data[i].length(); k++)
                    {
                        if (data[i][k] != data[j][k])
                        {
                            flag++;
                        }
                    }
                    if (flag == 1)
                    {
                        graph[i].push_back(j);
                        graph[j].push_back(i);
                    }                    
                }
            }
        }

        string pairs, begin, end;
        queue<int> qu;
        cin.ignore();
        while (getline(cin, pairs) && pairs!="")
        {
            //getline(cin, pairs);  // Read the entire line
            //if (pairs.empty()) 
            //{  // Check for an empty string
            //    break;
            //}
            stringstream ss(pairs);  
            ss >> begin >> end;
            memset(visited, -1, sizeof(visited));
            int s = find(data.begin(), data.end(), begin) - data.begin();
            int t = find(data.begin(), data.end(), end) - data.begin();
            // cout << "s= " << s << endl;
            // cout << "t= " << t << endl;
            qu.push(s);
            visited[s]++;
            while (!qu.empty())
            {
                auto x = qu.front();
                qu.pop();
                if (x == t)
                {
                    break;
                }

                for (int u = 0; u < graph[x].size(); u++)
                {
                    int v = graph[x][u];
                    if (visited[v] < 0)
                    {
                        visited[v]= visited[x] + 1;
                        qu.push(v);
                    }
                }
            }
            while(!qu.empty())
            {
                qu.pop();
            }
            cout << begin << " " << end << " " << visited[t] << endl;
        }
        if (n>0) cout<<endl;
    }

    return 0;
}
