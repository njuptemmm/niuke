#include <bits/stdc++.h>
using namespace std;

// 定义链表节点结构
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 创建链表并返回头结点
ListNode* createLinkedList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;

    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < nums.size(); i++) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return head;
}

// 遍历链表并输出
void printLinkedList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        cout << curr->val << endl;
        curr = curr->next;
    }
}

int main() {
    int n;
    cin >> n;  // 读取数组长度

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];  // 读取数组元素
    }

    ListNode* head = createLinkedList(nums);  // 创建链表
    printLinkedList(head);  // 遍历链表并输出

    return 0;
}
