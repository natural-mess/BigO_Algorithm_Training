#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string penguin;
    int countE=0, countM=0, countL=0;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        getline(cin, penguin);
        if (penguin == "Emperor Penguin")
        {
            countE++;
        }
        else if (penguin == "Macaroni Penguin")
        {
            countM++;
        }
        else
        {
            countL++;
        }
    }
    if (countE >= countM && countE >= countL) 
    {
        cout << "Emperor Penguin" << endl;
    } 
    else if (countM >= countE && countM >= countL) 
    {
        cout << "Macaroni Penguin" << endl;
    } 
    else {
        cout << "Little Penguin" << endl;
    }
    
    return 0;
}