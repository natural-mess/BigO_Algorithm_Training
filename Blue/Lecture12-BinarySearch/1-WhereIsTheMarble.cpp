#include <bits/stdc++.h>
using namespace std;

int main()
{
    int caseCount = 1;
    while(1)
    {
        int N, Q;
        cin >> N >> Q;
        if (N==0 && Q==0)
        {
            break;
        }
        cout << "CASE# " << caseCount++ << ":" << endl;
        int data;
        vector<int> inputData;

        for (int i = 0; i < N; i++)
        {
            cin >> data;
            inputData.push_back(data);
        }
        
        sort(inputData.begin(), inputData.end());

        for (int i = 0; i < Q; i++)
        {
            cin >> data;
            bool result = binary_search(inputData.begin(), inputData.end(), data);
            if (result == true)
            {
                cout << data << " found at " << lower_bound(inputData.begin(), inputData.end(), data) - inputData.begin() +1 << endl;
            }
            else
            {
                cout << data << " not found" << endl;
            }
        }
    }
    return 0;
}