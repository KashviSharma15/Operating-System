#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> processIDs;
    vector<int> processSize;
    int internalFragmentation = 0;
    int n;

    cout << "Enter the number of processes : ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int ID, Size;
        cout << "Enter Process ID and size for process " << i + 1 << ": ";
        cin >> ID >> Size;
        processIDs.push_back(ID);
        processSize.push_back(Size);
    }

    int partitionSize = 0;
    for (int i = 0; i < n; i++) {
        if (processSize[i] > partitionSize)
            partitionSize = processSize[i];
    }

    cout << "\nAllocation for Cycle 1 \n";
    for (int i = 0; i < n; i++) {
        if (processSize[i] <= partitionSize) {
            cout << "Process " << processIDs[i] << " is allocated\n";
            internalFragmentation += (partitionSize - processSize[i]);
        } else {
            cout << "Process " << processIDs[i] << " is not allocated\n";
        }
    }
    cout << "\nTotal internal Fragmentation is: " << internalFragmentation << endl;
    
    char choice;
    cout << "\nDo you want to enter a second cycle of processes (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int m;
        cout << "\nEnter the number of processes (Cycle 2): ";
        cin >> m;

        for (int i = 0; i < m; i++) {
            int ID, Size;
            cout << "Enter Process ID and size for process " << i + 1 << ": ";
            cin >> ID >> Size;

            if (Size <= partitionSize) {
                cout << "Process " << ID << " is allocated\n";
                internalFragmentation = 0;
                internalFragmentation += (partitionSize - Size);
            } else {
                cout << "Process " << ID << " is not allocated\n";
            }
        }
    }

    cout << "\nTotal internal Fragmentation is: " << internalFragmentation << endl;
    return 0;
}
