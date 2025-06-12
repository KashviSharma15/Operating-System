#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <unistd.h>
using namespace std;

queue<int> buffer;
const int SIZE = 5;
mutex mtx;
int item = 0;

void producer() {
    while (true) {
        sleep(1); 
        unique_lock<mutex> lock(mtx);

        if (buffer.size() < SIZE) {
            buffer.push(++item);
            cout << "Produced: " << item << endl;
        }
    }
}

void consumer() {
    while (true) {
        unique_lock<mutex> lock(mtx);

        if (!buffer.empty()) {
            int val = buffer.front();
            buffer.pop();
            cout << "Consumed: " << val << endl;
            lock.unlock();
            sleep(2); 
        } else {
            lock.unlock();
            sleep(1); 
        }
    }
}

int main() {
    thread p(producer), c(consumer);
    p.join();
    c.join();
}
