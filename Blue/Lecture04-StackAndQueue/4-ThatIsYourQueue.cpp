#include <bits/stdc++.h>
using namespace std;

int main()
{
    // p : population
    // c : number of commands
    int p, c;
    int x; // prio
    int case_count = 1;
    char inputPatient;
    int prioPatient = 0;
    queue<int> patient;
    queue<int> temp;

    while(1)
    {
        cin >> p >> c;
        if (p==0 && c==0)
        {
            break;
        }
        cout << "Case "<< case_count << ": " << endl;
        for (int i = 1; i <= min(p, c); i++)
        {
            patient.push(i);
        }

        for (int i = 0; i < c; i++)
        {
            cin >> inputPatient;
            if (inputPatient == 'N')
            {
                if (temp.empty()==false)
                {
                    cout << temp.front() << endl;
                    patient.push(temp.front());
                    temp.pop();
                }
                else
                {
                    cout << patient.front() << endl;
                    patient.push(patient.front());
                    patient.pop();
                }
            }
            else if (inputPatient == 'E')
            {
                cin >> x;
                while (x!=patient.front())
                {
                    temp.push(patient.front());
                    patient.pop();
                }
            }
        }
        
        case_count++;
        while (patient.empty() == false)
        {
            patient.pop();
        }
        while (temp.empty() == false)
        {
            temp.pop();
        }
    }
    return 0;
}
