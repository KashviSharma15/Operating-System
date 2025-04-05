#include <iostream>
#include <vector>
#include <algorithm>  
#include <climits>

using namespace std;

struct Process {
    int id, arrival, burst, completion ;
};

void nonPreemptiveSJF(vector<Process>& p) {
    int n = p.size(), completed = 0, totalWT = 0, totalTAT = 0;

    vector<int> ganttChart; 

    sort(p.begin(), p.end(), [](Process a, Process b) {
    if (a.arrival == b.arrival) 
        return a.burst < b.burst; 
    return a.arrival < b.arrival;
    });

    int currentTime = 0;
    
    cout << "\nP\tTAT\tWT\n";

    while (completed < n) {
        int minIdx = -1;
        int minBurst = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= currentTime && p[i].completion == 0 && p[i].burst < minBurst) {
                minBurst = p[i].burst;
                minIdx = i;
            }
        }

        if (minIdx == -1) {
            currentTime++; 
            continue;
        }

        currentTime += p[minIdx].burst;
        p[minIdx].completion = currentTime;
        int tat = p[minIdx].completion - p[minIdx].arrival;
        int wt = tat - p[minIdx].burst;
        totalWT += wt;
        totalTAT += tat;
        ganttChart.push_back(p[minIdx].id); 

        completed++;
        cout << "P" << minIdx +1 << "\t" << tat << "\t" << wt << "\n";
    }
    
    cout << "\nAverage Waiting Time: " << (float)totalWT / n << endl;
    cout << "Average Turnaround Time: " << (float)totalTAT / n << endl;

    cout << "\nGantt Chart:\n";
    for ( int i = 1 ; i <= n ; i++){
    cout << " ----";
    }cout << endl;
    for (int id : ganttChart) cout << "| P" << id << " ";
    cout << "|" << endl;
    
    for ( int i = 0 ; i < n ; i++){
    cout << " ----";
    }cout << endl;
    
}

int main() {
    vector<Process> p;
    int n, at, bt;

    cout << "Enter the number of processes:";
    cin >> n;
    cout << "Enter Arrival Time and Burst Time for Processes\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1  << "(AT , BT )"<< ": ";
        cin >> at >> bt;
        p.push_back({ i+1 ,at, bt, 0});
    }

    nonPreemptiveSJF(p);
    return 0;
}