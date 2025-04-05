#include <iostream>
using namespace std;

const int P = 5;  
const int R = 3;  

bool checkSafe(int processes[], int available[], int max[][R], int allocated[][R]) {
    int need[P][R], work[R], safeSeq[P];
    bool finish[P] = {false};

    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - allocated[i][j];

    for (int i = 0; i < R; i++)
        work[i] = available[i];

    int count = 0;
    while (count < P) {
        bool found = false;
        for (int i = 0; i < P; i++) {
            if (!finish[i]) {  
                int j;
                for (j = 0; j < R; j++)
                    if (need[i][j] > work[j]) break;

                if (j == R) {  
                    for (int k = 0; k < R; k++)
                        work[k] += allocated[i][k];  

                    safeSeq[count++] = processes[i];
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {  
            cout << "System is NOT in a safe state.\n";
            return false;
        }
    }

    cout << "System is in a safe state.\nSafe sequence: ";
    for (int i = 0; i < P; i++)
        cout << safeSeq[i] << " ";
    cout << endl;
    return true;
}


int main() {
    int P;
    int R;
    cout << "No. of processes : ";
    cin >> P;
    cout << "No. of Resources : ";
    cin >> R;

    int processes[P];
    for(int i =0; i <P ; i++){
        cin >> processes[i];
    }
    cout << "available : " ;
    int available[R] ; 
    for(int i =0; i <R ; i++){
        cin >> available[i];
    } 
    int max[P][R] ;
    for(int i =0; i <P ; i++){
        for(int j =0; i <R ; j++){
        cin >> max[i][j];
        }
    }
    int allocated[P][R] ;

    int max[P][R] ;
    for(int i =0; i <P ; i++){
        for(int j =0; i <R ; j++){
        cin >> allocated[i][j];
        }
    }
    checkSafe(processes, available, max, allocated);
    return 0;
}
