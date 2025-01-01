#include <bits/stdc++.h>
using namespace std;

vector<string> graph[202];
int visited[202];

int bfs (pair<string,string> inputString)
{

}

int main()
{
    int n;
    cin >> n;
    cout << endl;

    while (n--)
    {
        vector<string> data;
        string dataInput;

        do
        {
            cin >> dataInput;
            data.push_back(dataInput);
        } while (dataInput != "*\0");
        // for (int i = 0; i < data.size(); i++)
        // {
        //     cout << data[i] << endl;
        // }

        for (int i = 0; i < 202; i++)
        {
            graph[i].clear();
        }
        
        string pairs, begin, end;
        vector<pair<string, string>> expectedResult;
        pair<string, string> extractedWord;
        char* p;
        cin.ignore();
        do
        {
            getline(cin, pairs);  // Read the entire line
            if (pairs.empty()) 
            {  // Check for an empty string
                break;
            }
            stringstream ss(pairs);  
            ss >> begin >> end;
            extractedWord.first = begin;
            extractedWord.second = end;
            expectedResult.push_back(extractedWord);
        } while (true);

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
                        graph[i].push_back(data[j]);
                        graph[j].push_back(data[i]);
                    }
                }
            }
        }

        queue<string> qu;
        for (int i = 0; i < expectedResult.size(); i++)
        {
            qu.push(expectedResult[i].first);
            while (qu.empty()!= true)
            {
                 
            }
        }
        
    }

    return 0;
}