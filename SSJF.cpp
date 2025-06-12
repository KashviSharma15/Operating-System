#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int n, head;

    cout << "Enter number of cylenders: ";
    cin >> n;

    int requests[100]; 
    bool visited[100] = {false};

    cout << "Enter the disk requests:\n";
    for (int i = 0; i < n; ++i) {
        cin >> requests[i];
    }

    cout << "Enter initial head position: ";
    cin >> head;

    int Count = 0;
    int sequence[100]; 
    sequence[0] = head;

    for (int i = 0; i < n; ++i) {
        int minDist = INT_MAX;
        int index = -1;

        for (int j = 0; j < n; ++j) {
            if (!visited[j]) {
                int dist = abs(head - requests[j]);
                if (dist < minDist) {
                    minDist = dist;
                    index = j;
                }
            }
        }

        visited[index] = true;
        Count += abs(head - requests[index]);
        head = requests[index];
        sequence[i + 1] = head;
    }

    cout << "\n Sequence:\n";
    for (int i = 0; i <= n; ++i) {
        cout << sequence[i];
        if (i < n) cout << " -> ";
    }

    cout << "\n\nTotal number of operations = " << Count << endl;

    return 0;
}
