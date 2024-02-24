//Saad Naseer Mahfood U20101891
#include <iostream>
using namespace std;

int main()
{
    int p[10][3], max, wait = 0, tat = 0, W[10], T[10];

    cout << "Enter total number of processes(maximum 10): ";
    cin >> max;

    if (max > 10)
    {
        cout << "\ninvalid";
        exit;
    }
    else
    {
        cout << "\nEnter Process Burst Time and priority\n";
        for (int i = 0; i < max; i++)
        {
            cout << "\nP[" << i + 1 << "]:\n";
            p[i][0] = i + 1;
            cout << "Burst Time:";
            cin >> p[i][1];
            cout << "priority:";
            cin >> p[i][2];
        }

        for (int i = 0; i < max; i++)
        {
            for (int j = 0; j < max-1; j++)
            {
                if (p[j][2] > p[j + 1][2])
                {
                    for (int k = 0; k < 3; k++)
                    {
                        int C ;
                        
                        C = p[j][k];
                        
                        p[j][k] = p[j + 1][k];
                         
                        p[j + 1][k] = C;
                       
                    }
                }
            }
        }

        cout << "\nprocess      Burst Time      Waiting time    Turn around time\n";

        for (int i = 0; i < max; i++)
        {
            cout << "P[" <<p[i][0]<< "]\n\t\t"; //process

            cout << p[i][1] << "\t\t";      //burst time

            cout << wait << "\t\t";      //waiting time
            W[i] = wait;
            wait += p[i][1];

            tat += p[i][1];
            T[i] = tat;
            cout << tat << "\t\t" << endl;

        }

        int AveWait = 0, aveTat = 0;
        for (int i = 0; i < max; i++)
        {
            AveWait += W[i];
            aveTat += T[i];
        }

        cout << "\nAverage Waiting Time:" << AveWait / max;
        cout << "\nAverage Turnaround Time:" << aveTat / max;

    }


    return 0;
}