#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//21.合并两个有序链表（已通过）
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p = new ListNode(), * ans = p;
        while (list1 && list2 )
        {
            while (list1 && list2 && (list1->val <= list2->val))
            {
                p->next = list1;
                list1 = list1->next;
                p = p->next;
            }
            while (list1 && list2 && (list1->val > list2->val))
            {
                p->next = list2;
                list2 = list2->next;
                p = p->next;
            }
        }

        while (list1)
        {
            p->next = list1;
            list1 = list1->next;
            p = p->next;
        }
        while (list2)
        {
            p->next = list2;
            list2 = list2->next;
            p = p->next;
        }
        return ans->next;
    }
};