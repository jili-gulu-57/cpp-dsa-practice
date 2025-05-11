#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

//解法一：三指针（已通过）
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return head;
        ListNode* n1 = nullptr, * n2 = head, * n3 = head->next;
        while (n2)
        {
            n2->next = n1;
            n1 = n2;
            n2 = n3;
            if (n3)
                n3 = n3->next;
        }
        return n1;
    }
};

//解法二：头插（已通过）
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* NewHead = nullptr;//直接创建新链表，在新链表头插
        ListNode* cur = head;
        while (cur)
        {
            ListNode* next = cur->next;
            cur->next = NewHead;
            NewHead = cur;
            cur = next;
        }
        return NewHead;
    }
};