#include <iostream>

using namespace std;

int main() {
    int *raw;
    shared_ptr<int> p1(raw);
    cout << p1.use_count() << endl;
    cout << endl;
    {
        shared_ptr<int> p2 = p1;
        cout << p1.use_count() << endl;
        cout << p2.use_count() << endl;
        cout << endl;

        shared_ptr<int> p3(raw);
        cout << p1.use_count() << endl;
        cout << p2.use_count() << endl;
        cout << p3.use_count() << endl;
        cout << endl;

        shared_ptr<int> p4 = p2;
        cout << p1.use_count() << endl;
        cout << p2.use_count() << endl;
        cout << p3.use_count() << endl;
        cout << p4.use_count() << endl;
        cout << endl;
    }

}