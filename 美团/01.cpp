/*
给定整型数组集合，找出数值最大且重复次数占比大于等于10%的数字。
例如{1,2,3,4,5,6,7,8,9,10,9,9,9,9}中返回9。
*/
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int func(const vector<int>& nums) {
    map<int, int> m;
    for(auto i: nums) {
        m[i]++;
    }
    for(auto it = m.rbegin(); it != m.rend(); it++) {
        if(it->second * 10 >= static_cast<int>(nums.size())) {
            return it->first;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10,9,9,9,9};
    cout << func(nums) << endl;
    return 0;
}