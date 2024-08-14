#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nA, nB, k, m;
    cin >> nA >> nB;
    cin >> k  >> m;
    vector<int> A(nA);
    vector<int> B(nB);
    for (int i = 0; i < nA; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < nB; i++)
    {
        cin >> B[i];
    }

    bool check = false;
    int indexA = 0, countA = 0;
    int indexB = 0, countB = 0;
    bool flagB = false;
    while (indexA<nA)
    {
        if (countA < k)
        {
            if (B[indexB] > A[indexA])
            {
                if (countA < k)
                {
                    countA++;
                    indexA++;
                }
                if (countB < m && flagB == false)
                {
                    countB++;
                    flagB = true;
                }
            }
            else //if (B[indexB]<=A[indexA])
            {
                indexB++;
                flagB = false;
                countB=0;
            }
        }
        else
        {
            indexB++;
            if (countB<m && indexB<nB)
            {
                countB++;
            }
        }
        if (countA >= k && countB >= m)
        {
            check = true;
            break;
        }
        if (indexB>=nB)
        {
            break;
        }
    }
    
    // cout << i << endl << indexA << endl;
    (check==true) ? (cout<<"YES") : (cout<<"NO");
    // if (countB >= m && nA >= k)
    // {
    //     cout << "YES";
    // }
    // else
    // {
    //     cout << "NO";
    // }

    return 0;
}