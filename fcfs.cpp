#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> ganttChart;

    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int A[n][6];

    cout << "Enter Arrival Time and Burst Time:\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << " (AT BT): ";
        cin >> A[i][1] >> A[i][2];
        A[i][0] = i + 1;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i][1] > A[j][1]) {
                swap(A[i], A[j]);
            }
        }
    }

    int currentTime = 0, totalTAT = 0, totalWT = 0;

    cout << "\nP\tAT\tBT\tCT\tTAT\tWT\n";

    for (int i = 0; i < n; i++) {
        if (currentTime < A[i][1]) {
            currentTime = A[i][1];
        }

        currentTime += A[i][2];
        A[i][3] = currentTime; 
        A[i][4] = A[i][3] - A[i][1]; 
        A[i][5] = A[i][4] - A[i][2]; 

        totalTAT += A[i][4];
        totalWT += A[i][5];

        cout << "P" << A[i][0] << "\t" << A[i][1] << "\t" << A[i][2] << "\t" << A[i][3] << "\t" << A[i][4] << "\t" << A[i][5] << endl;
        ganttChart.push_back(A[i][0]);

    }

    cout << "Average Turnaround Time = " << (float)totalTAT / n << endl;
    cout << "Average Waiting Time = " << (float)totalWT / n << endl;

    cout << "\nGantt Chart:\n";
    for ( int i = 0 ; i < n ; i++){
    cout << " ----";
    }cout << endl;
    for (int id : ganttChart) cout << "| P" << id << " ";
    cout << "|" << endl;
    
    for ( int i = 0 ; i < n ; i++){
    cout << " ----";
    }cout << endl;

    return 0;
}