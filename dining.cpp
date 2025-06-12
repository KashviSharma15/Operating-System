#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h> 
using namespace std;

const int N = 5;
mutex chopstick[N];

void philosopher(int i) {
    for (int round = 0; round < 3; ++round) {
        cout << "Philosopher " << i + 1 << " is Thinking\n";
        sleep(1);

        chopstick[i].lock();
        chopstick[(i + 1) % N].lock();

        cout << "Philosopher " << i + 1 << " is Eating\n";
        sleep(2);

        chopstick[i].unlock();
        chopstick[(i + 1) % N].unlock();
    }
}

int main() {
    thread philosophers[N];
    for (int i = 0; i < N; ++i)
        philosophers[i] = thread(philosopher, i);

    for (int i = 0; i < N; ++i)
    
        philosophers[i].join();

    return 0;
}
