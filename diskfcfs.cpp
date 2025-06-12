#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void FCFS(const vector<int>& requests, int head) {
    int count = 0;

    cout << "\n Sequence:\n";
    cout << head;

    for (int i = 0; i < requests.size(); i++) {
        int track = requests[i];
        cout << " -> " << track;
        count += abs(track - head);
        head = track;
    }

    cout << "\n\nTotal number of operations = " << count << endl;
}

int main() {
    int n, head;

    cout << "Enter number of cylender: ";
    cin >> n;

    vector<int> requests(n);
    cout << "Enter the disk requests:\n";
    for (int i = 0; i < n; i++) {
        cin >> requests[i];
    }

    cout << "Enter initial head position: ";
    cin >> head;

    FCFS(requests, head);

    return 0;
}
