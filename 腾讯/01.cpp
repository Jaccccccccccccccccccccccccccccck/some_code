/*
实现阻塞读且并发安全的map
*/
#include <iostream>
#include <map>
#include <mutex>
#include <thread>

using namespace std;

class safe_map {
private:
    map<int, int> m;
    mutex mtx;
public:
    int get(int k) {
        lock_guard<mutex> guard(mtx);
        this_thread::sleep_for(chrono::seconds(1));
        int res = m[k];
        return res;
    }
    void put(int k, int v) {
        lock_guard<mutex> guard(mtx);
        m[k] = v;
    }

};

safe_map sm;

void get_from_sm(int key) {
    cout << this_thread::get_id() << "thread get" << sm.get(key) << endl;
}

int main() {
    sm.put(1, 1);
    sm.put(2, 2);
    thread t1(get_from_sm, 1);
    thread t2(get_from_sm, 2);
    thread t3(get_from_sm, 3);
    cout << "t1 thread:" << t1.get_id() << endl;
    cout << "t2 thread:" << t2.get_id() << endl;
    cout << "t3 thread:" << t3.get_id() << endl;
    t1.join();
    t2.join();
    return 0;
}