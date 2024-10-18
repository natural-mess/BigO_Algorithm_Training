#include <bits/stdc++.h>
using namespace std;

int main()
{
    // p : population
    // c : number of commands
    int p, c;
    int x; // prio
    int p_count = 1; // counter for P
    int case_count = 1;
    char inputPatient;
    queue<int> patient;
    int temp;
    int queueSize;

    while(1)
    {
        cin >> p >> c;
        if (p==0 && c==0)
        {
            break;
        }
        cout << "Case "<< case_count << ": " << endl;
        for (int i = 1; i <= min(p,c); i++)
        {
            patient.push(i);
        }
        queueSize = patient.size();
        
        for (int i = 0; i < c; i++)
        {
            cin >> inputPatient;
            if (inputPatient == 'N')
            {
                cout << patient.front() << endl;
                temp = patient.front();
                patient.pop();
                patient.push(temp);
            }
            else
            {
                cin >> x;
                patient.push(x);
                queueSize = patient.size();
                for (int i = 0; i < queueSize-1; i++)
                {
                    temp = patient.front();
                    patient.pop();
                    if (temp != x)
                    { 
                        patient.push(temp);
                    }
                }
            }
            
        }
        case_count++;
        while (patient.empty() == false)
        {
            patient.pop();
        }
    }
    return 0;
}
