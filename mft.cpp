#include <iostream>

using namespace std;

int main() {
    int ms, i, ps[20], n, size, p[20], s, intr = 0;

    cout << "Enter size of memory: ";
    cin >> ms;

    cout << "Enter memory for OS: ";
    cin >> s;

    ms -= s;

    cout << "Enter number of partitions to be divided: ";
    cin >> n;

    size = ms / n;

    for (i = 0; i < n; i++) {
        cout << "\nEnter process ID and process size: ";
        cin >> p[i] >> ps[i];

        if (ps[i] <= size) {
            intr += (size - ps[i]); 
            cout << "Process " << p[i] << " is allocated.\n";
        } else {
            cout << "Process " << p[i] << " is blocked.\n";
        }
    }

    cout << "\nInternal fragmentation is " << intr << endl;

    return 0;
}
