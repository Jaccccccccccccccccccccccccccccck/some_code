#include <bitset>
#include <iostream>
#include <string>
#include <vector>

class BloomFilter {
private:
    static const int size = 100; // 布隆过滤器的大小（位数）
    std::bitset<size> bitArray;

public:
    void insert(const std::string& item) {
        std::vector<int> hashValues = hash(item);
        for (int hashValue : hashValues) {
            bitArray[hashValue] = true;
        }
    }

    bool contains(const std::string& item) {
        std::vector<int> hashValues = hash(item);
        for (int hashValue : hashValues) {
            if (!bitArray[hashValue]) {
                return false;
            }
        }
        return true;
    }

private:
    // 使用简单的哈希函数生成多个哈希值
    std::vector<int> hash(const std::string& item) {
        std::vector<int> hashValues;
        // 这里使用简单的散列函数示例，实际应用中可以使用更强大的哈希函数
        // 也可以使用std::hash<std::string> str_hash 声明一个函数，然后使用str_hash进行调用
        int hash1 = std::hash<std::string>{}(item);
        int hash2 = std::hash<std::string>{}(item + "salt"); // 添加盐以改变哈希值
        hashValues.push_back(hash1 % size);
        hashValues.push_back(hash2 % size);
        return hashValues;
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