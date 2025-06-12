#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100;

void SCAN(int arr[], int size, int head, int prev, int disk_size) {
    int count = 0;
    int sequence[MAX], index = 0;
    int left[MAX], right[MAX];
    int left_count = 0, right_count = 0;

    string direction = (head < prev) ? "left" : "right";

    for (int i = 0; i < size; i++) {
        if (arr[i] < head) left[left_count++] = arr[i];
        else right[right_count++] = arr[i];
    }

    if (direction == "left") left[left_count++] = 0;
    else right[right_count++] = disk_size - 1;

    sort(left, left + left_count);
    sort(right, right + right_count);

    if (direction == "left") {
        for (int i = left_count - 1; i >= 0; i--) {
            sequence[index++] = left[i];
            count += abs(head - left[i]);
            head = left[i];
        }
        for (int i = 0; i < right_count; i++) {
            sequence[index++] = right[i];
            count += abs(head - right[i]);
            head = right[i];
        }
    } else {
        for (int i = 0; i < right_count; i++) {
            sequence[index++] = right[i];
            count += abs(head - right[i]);
            head = right[i];
        }
        for (int i = left_count - 1; i >= 0; i--) {
            sequence[index++] = left[i];
            count += abs(head - left[i]);
            head = left[i];
        }
    }

    cout << "\nTotal operations = " << count << endl;
    cout << "sequence: ";
    for (int i = 0; i < index; i++) {
        cout << sequence[i];
        if (i < index - 1) cout << " -> ";
    }
    cout << endl;
}

int main() {
    int arr[MAX], n, head, prev, disk_size;

    cout << "Enter number of cylinders: ";
    cin >> n;

    cout << "Enter the disk requests:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter initial head position: ";
    cin >> head;

    cout << "Enter previous head position: ";
    cin >> prev;

    cout << "Enter disk size : ";
    cin >> disk_size;

    SCAN(arr, n, head, prev, disk_size);
    return 0;
}
