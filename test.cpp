#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, int> m;
    m[0] = 3;
    m[1] = 4;
    m[3] = 5;
    m[5] = 5;
    m[6] = 5;
    for(auto &[k, v]: m) {
        cout << k << " : " << v << endl;
    }
    for(auto it = m.rbegin(); it != m.rend(); it++) {
        cout << it->first << " : " << it->second << endl;
    }
    return 0;
}