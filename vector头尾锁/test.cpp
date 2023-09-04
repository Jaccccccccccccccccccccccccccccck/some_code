#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;
// 多个线程尝试读一个vector，如果拿到读头锁就读头，如果拿到读尾锁就读尾，如果拿不到就放弃

/*
c语言中sleep函数使用方法：
    引入unistd.h
    sleep(1);
c++语言中的sleep函数使用方法：
    std::thread::sleep_for(std::chrono::seconds(1));
*/


mutex mtx_head;
mutex mtx_tail;

vector<int> vec = {1,2,3,4,5};

void read_from_vector() {
    while(true) {
        if(mtx_head.try_lock()) {
            this_thread::sleep_for(chrono::seconds(1));
            cout << this_thread::get_id() << " : " << vec.front() << endl;
            mtx_head.unlock();
        } else {
            if(mtx_tail.try_lock()) {
                this_thread::sleep_for(chrono::seconds(1));
                cout << this_thread::get_id() << " : " << vec.back() << endl;
                mtx_tail.unlock();
            }
        } 
    }

}

int main() {
    thread t1 = thread(read_from_vector);
    cout << "t1 tid:" << t1.get_id() << endl;
    thread t2 = thread(read_from_vector);
    cout << "t2 tid:" << t2.get_id() << endl;
    thread t3 = thread(read_from_vector);
    cout << "t3 tid:" << t3.get_id() << endl;
    t1.join();
    t2.join();
    t3.join();
    return 0;
}