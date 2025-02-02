#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    // Read and ignore the empty line after t
    string emptyLine;
    getline(cin, emptyLine);
    while (t--)
    {
        map<string, double> m;
        double total = 0.0;
        
        string hardwood;
        map<string, double>::iterator it;
        while (getline(cin, hardwood) && hardwood!="")
        {
            it = m.find(hardwood);
            if (it != m.end())
            {
                m[hardwood]++;
            }
            else
            {
                m[hardwood] = 1;
            }
            total = total + 1.0;
        }
        for (it = m.begin(); it != m.end(); it++)
        {
            cout << it->first << " " << fixed << setprecision(4) << ((it->second) / total)*100.0 << endl;
        }
        // Print a newline between test cases, except after the last one
        if (t > 0)
        {
            cout << endl;
        }
    }
    return 0;
}