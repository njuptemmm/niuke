


#include<bits/stdc++.h>
using namespace std;

// 单链表节点结构
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 辅助函数：翻转单链表
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

// 主合并函数
ListNode* mergeLists(ListNode* A, ListNode* B) {
    // 1. 将链表 B 翻转，这样 B 的尾节点就变成了头节点
    ListNode* bCurr = reverseList(B);
    ListNode* aCurr = A;

    // 虚拟头节点，方便串联新链表
    ListNode dummy(0);
    ListNode* tail = &dummy;

    // 2. 轮流从 A 的头部和 B 的“尾部”（现为 bCurr 的头部）取节点
    while (aCurr != nullptr || bCurr != nullptr) {
        // 规则一：A 非空，取 A 的头节点
        if (aCurr != nullptr) {
            tail->next = aCurr;      // 接到新链表尾部
            aCurr = aCurr->next;     // A 向后移动（相当于删除了原头节点）
            tail = tail->next;
        }
        // 规则二：B 非空，取 B 的尾节点（即当前 bCurr 的头节点）
        if (bCurr != nullptr) {
            tail->next = bCurr;      // 接到新链表尾部
            bCurr = bCurr->next;     // B 向后移动
            tail = tail->next;
        }
    }
    
    tail->next = nullptr; // 确保新链表尾部指向 nullptr
    return dummy.next;
}

// 辅助函数：打印链表
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "NULL\n";
}

int main() {
    // 创建链表 A: 1 -> 2 -> 3
    ListNode* A = new ListNode(1);
    A->next = new ListNode(2);
    A->next->next = new ListNode(3);

    // 创建链表 B: 4 -> 5 -> 6
    ListNode* B = new ListNode(4);
    B->next = new ListNode(5);
    B->next->next = new ListNode(6);

    std::cout << "Original A: "; printList(A);
    std::cout << "Original B: "; printList(B);

    ListNode* result = mergeLists(A, B);

    std::cout << "Merged List: "; printList(result);

    return 0;
}