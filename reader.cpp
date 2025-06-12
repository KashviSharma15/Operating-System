#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>
using namespace std;

mutex mtx, wrt;
int readcnt = 0;

void reader(int id) {
        while (true) {
            mtx.lock();
            readcnt++;
            if (readcnt == 1) wrt.lock();
            mtx.unlock();

        cout << "Reader " << id << " is reading\n";
        sleep(1);

        mtx.lock();
        if (--readcnt == 0) wrt.unlock();
        mtx.unlock();

        sleep(1);
    }
}

void writer(int id) {
    while (true) {
        wrt.lock();
        cout << "Writer " << id << " is writing\n";
        sleep(2);
        wrt.unlock();

        sleep(2);
    }
}

int main() {
    thread readers[5], writers[2];

    for (int i = 0; i < 5; ++i)
    readers[i] = thread(reader, i + 1);
    for (int i = 0; i < 2; ++i)
    writers[i] = thread(writer, i + 1);
    
    for (int i = 0; i < 5; ++i)
        readers[i].join();
    for (int i = 0; i < 2; ++i)
        writers[i].join();

    return 0;
}
