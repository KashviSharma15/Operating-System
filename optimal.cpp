#include <iostream>
using namespace std;

const int MAX = 100;

bool isInFrames(int frames[], int frameCount, int page) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == page)
            return true;
    }
    return false;
}

int findReplaceIndex(int pages[], int totalPages, int frames[], int frameCount, int currentIndex) {
    int indexToReplace = -1, farthest = currentIndex;

    for (int i = 0; i < frameCount; i++) {
        int j;
        for (j = currentIndex; j < totalPages; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    indexToReplace = i;
                }
                break;
            }
        }

        if (j == totalPages)
            return i;
    } 

    return (indexToReplace == -1) ? 0 : indexToReplace;
}

int main() {
    int pages[MAX], totalPages, frames[MAX], frameCount;
    int hits = 0;

    cout << "Enter number of pages: ";
    cin >> totalPages;

    cout << "Enter page :\n";
    for (int i = 0; i < totalPages; i++)
        cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> frameCount;

    int currentFrames = 0;

    for (int i = 0; i < totalPages; i++) {
        if (isInFrames(frames, currentFrames, pages[i])) {
            hits++;
        } else {
            if (currentFrames < frameCount) {
                frames[currentFrames++] = pages[i];
            } else {
                int index = findReplaceIndex(pages, totalPages, frames, frameCount, i + 1);
                frames[index] = pages[i];
            }
        }
    } 

    cout << "\nTotal Page Hits: " << hits << endl;
    cout << "Total Page Faults: " << totalPages - hits << endl;

    return 0;
}
