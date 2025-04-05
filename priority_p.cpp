#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> ganttChart;
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int A[n][6]; 
    cout << "Enter Arrival Time, Burst Time, and Priority:\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << " (AT BT P): ";
        cin >> A[i][1] >> A[i][2] >> A[i][3];
        A[i][0] = i + 1;
        A[i][4] = A[i][2]; 
    }

    int currentTime = 0, completed = 0, totalTAT = 0, totalWT = 0;
    int lastProcess = -1; 
    cout << "\nP\tAT\tTAT\tWT\n";

    while (completed < n) {
        int minIdx = -1, minPriority = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (A[i][1] <= currentTime && A[i][4] > 0) {
                if (A[i][3] < minPriority) {
                    minPriority = A[i][3];
                    minIdx = i;
                }
            }
        }

        if (minIdx == -1) {
            currentTime++;
            continue;
        }

        if (lastProcess != A[minIdx][0]) {
            ganttChart.push_back(A[minIdx][0]);
            lastProcess = A[minIdx][0];
        }

        A[minIdx][4]--;
        currentTime++;

        if (A[minIdx][4] == 0) {
            A[minIdx][5] = currentTime - A[minIdx][1]; // Turnaround time
            totalTAT += A[minIdx][5];
            int waitTime = A[minIdx][5] - A[minIdx][2];
            totalWT += waitTime;
            cout << "P" << A[minIdx][0] << "\t" << A[minIdx][1] << "\t" << A[minIdx][5] << "\t" << waitTime << endl;
            completed++;
        }
    }

    cout << "\nAverage Turnaround Time = " << (float)totalTAT / n << endl;
    cout << "Average Waiting Time = " << (float)totalWT / n << endl;

    cout << "\nGantt Chart:\n";
    for (size_t i = 0; i < ganttChart.size(); i++) {
        cout << " ----";
    }
    cout << endl;
    for (size_t i = 0; i < ganttChart.size(); i++) {
        cout << "| P" << ganttChart[i] << " ";
    }
    cout << "|" << endl;
    for (size_t i = 0; i < ganttChart.size(); i++) {
        cout << " ----";
    }
    cout << endl;

    return 0;
}