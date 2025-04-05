#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id, arrival, burst, remaining, turnaround, waiting;
};

void roundRobin(Process p[], int n, int tq) {
    int timer = 0, completed = 0, totalTAT = 0, totalWT = 0;
    vector<int> ganttChart;
    int lastProcess = -1; // Track the last executed process

    for (int i = 0; i < n; i++)
        p[i].remaining = p[i].burst;

    while (completed < n) {
        bool progress = false;
        for (int i = 0; i < n; i++) {
            if (p[i].remaining > 0 && p[i].arrival <= timer) {
                progress = true;
                int execTime = min(p[i].remaining, tq);
                timer += execTime;
                p[i].remaining -= execTime;

                // Update Gantt chart only if the process is different from the last one
                if (lastProcess != p[i].id) {
                    ganttChart.push_back(p[i].id);
                    lastProcess = p[i].id;
                }

                if (p[i].remaining == 0) {
                    p[i].turnaround = timer - p[i].arrival;
                    p[i].waiting = p[i].turnaround - p[i].burst;
                    totalTAT += p[i].turnaround;
                    totalWT += p[i].waiting;
                    completed++;
                }
            }
        }
        if (!progress)
            timer++;
    }

    cout << "\nAverage Waiting Time = " << (float)totalWT / n << endl;
    cout << "Average TurnAround Time = " << (float)totalTAT / n << endl;
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
}

int main() {
    int n, tq;
    cout << "Enter time quantum: ";
    cin >> tq;
    cout << "Enter number of processes: ";
    cin >> n;
    Process p[n];

    cout << "Enter Arrival time and Burst time: \n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << " (AT BT): ";
        cin >> p[i].arrival >> p[i].burst;
        p[i].id = i + 1;
    }

    roundRobin(p, n, tq);
    return 0;
}
