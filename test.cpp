#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BloomFilter {
private:
    const static int size = 100;
    bitset<100> bs;
public:
    void insert(string s) {
        vector<int> hs = muti_hash(s);
        for(auto i: hs) {
            bs[static_cast<size_t>(i)] = true;
        }
    }

    bool contains(string s) {
        vector<int> hs = muti_hash(s);
        for(auto i: hs) {
            if(!bs[static_cast<size_t>(i)]) {
                return false;
            }
        }
        return true;
    }
private:
    vector<int> muti_hash(string s) {
        vector<int> res;
        hash<string> str_hash;
        auto h1 = hash<string>{}(s);
        auto h2 = str_hash(s + "salt");
        res.push_back(h1%size);
        res.push_back(h2%size);
        return res;
    }
    
};

int main() {
    BloomFilter filter;

    // 添加元素到布隆过滤器
    filter.insert("apple");
    filter.insert("banana");
    filter.insert("cherry");

    // 检查元素是否存在于布隆过滤器中
    std::cout << "Contains apple: " << filter.contains("apple") << std::endl; // 可能存在
    std::cout << "Contains grape: " << filter.contains("grape") << std::endl; // 不存在
    std::cout << "Contains cherry: " << filter.contains("cherry") << std::endl; // 可能存在

    return 0;
}