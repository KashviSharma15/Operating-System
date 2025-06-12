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

int findMFUIndex(int freq[], int frameCount) {
    int maxFreq = -1, index = -1;
    for (int i = 0; i < frameCount; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            index = i;
        }
    }
    return index;
}

int main() {
    int pages[MAX], totalPages, frames[MAX], freq[MAX];
    int frameCount, hits = 0, currentFrames = 0;

    cout << "Enter number of pages: ";
    cin >> totalPages;

    cout << "Enter page sequence:\n";
    for (int i = 0; i < totalPages; i++)
        cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> frameCount;

    for (int i = 0; i < frameCount; i++) {
        frames[i] = -1;
        freq[i] = 0;
    }

    for (int i = 0; i < totalPages; i++) {
        int index = findInFrames(frames, currentFrames, pages[i]);

        if (index != -1) {
            hits++;
            freq[index]++;
        } else {
            if (currentFrames < frameCount) {
                frames[currentFrames] = pages[i];
                freq[currentFrames] = 1;
                currentFrames++;
            } else {
                int mfuIndex = findMFUIndex(freq, frameCount);
                frames[mfuIndex] = pages[i];
                freq[mfuIndex] = 1;
            }
        }
    }

    cout << "\nTotal Page Hits: " << hits << endl;
    cout << "Total Page Faults: " << totalPages - hits << endl;

    return 0;
}
