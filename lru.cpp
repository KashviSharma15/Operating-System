#include <iostream>
using namespace std;

const int MAX = 100;

int findInFrames(int frames[], int frameCount, int page) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == page)
            return i;
    }
    return -1;
}

void moveToEnd(int frames[], int& currentFrames, int index) {
    int temp = frames[index];
    for (int i = index; i < currentFrames - 1; i++) {
        frames[i] = frames[i + 1];
    }
    frames[currentFrames - 1] = temp;
}

int main() {
    int pages[MAX], totalPages, frames[MAX], frameCount;
    int hits = 0, currentFrames = 0;

    cout << "Enter number of pages: ";
    cin >> totalPages;

    cout << "Enter page reference string:\n";
    for (int i = 0; i < totalPages; i++)
        cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> frameCount;

    for (int i = 0; i < totalPages; i++) {
        int index = findInFrames(frames, currentFrames, pages[i]);

        if (index != -1) {
            hits++;
            moveToEnd(frames, currentFrames, index); 
        } else {
            if (currentFrames < frameCount) {
                frames[currentFrames++] = pages[i];
            } else {
                for (int j = 0; j < frameCount - 1; j++)
                    frames[j] = frames[j + 1];
                frames[frameCount - 1] = pages[i];
            }
        } 
    }

    cout << "\nTotal Page Hits: " << hits << endl;
    cout << "Total Page Faults: " << totalPages - hits << endl;

    return 0;
}
