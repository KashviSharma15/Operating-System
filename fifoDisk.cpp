#include <iostream>
#include <queue>
using namespace std;

bool isInQueue(queue<int> q, int page) {
    while (!q.empty()) {
        if (q.front() == page)
            return true;
        q.pop();
    }
    return false;
}

int pageFaultsFIFO(const vector<int>& pages, int capacity) {
    queue<int> memory;
    int faults = 0;

    for (int i = 0; i < pages.size(); i++) {
        int page = pages[i];
    
        if (!isInQueue(memory, page)) {
            if (memory.size() == capacity) {
                memory.pop(); 
            }
            memory.push(page);
            faults++;
        }
    }

    return faults;
}

int main() {
    int n, capacity;
    cout << "Enter number of pages: ";
    cin >> n;

    vector<int> pages(n);
    cout << "Enter pages:\n";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << "Enter frame capacity: ";
    cin >> capacity;

    int faults = pageFaultsFIFO(pages, capacity);
    cout << "Total Page Faults: " << faults << endl;

    return 0;
}
