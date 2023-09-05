/*
链表去重，如 0 1 1 1 2 3 4 输出 0 2 3 4
*/
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(): val(-1), next(nullptr) {}
    Node(int v): val(v), next(nullptr) {}
    Node(int v, Node* n): val(v), next(n) {}
};

Node* deleteDup(Node* head) {
    Node* dummy_head = new Node();
    dummy_head->next = head;
    Node* pre = dummy_head;
    // 还有大于两个节点的情况
    while(pre->next && pre->next->next) {
        // 如果接下来两个node的val相同，进行去重行为
        if(pre->next->val == pre->next->next->val) {
            int val = pre->next->val; // 重复的值
            Node* tmp = pre->next->next; // 指向重复的最后一个节点后边一个节点
            while(tmp && tmp->val == val) {
                tmp = tmp->next;
            }
            pre->next = tmp; // 删除重复节点
        } else { // 不同
            pre = pre->next;
        }
    }
    return dummy_head->next;
}

void print_list(Node* head) {
    Node* tmp = head;
    while(tmp) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main() {

    Node* head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(1);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(4);
    print_list(head);
    Node* new_head = deleteDup(head);
    print_list(new_head);
    return 0;
}