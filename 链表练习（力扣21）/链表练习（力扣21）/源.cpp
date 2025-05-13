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

 //ÒÑÍ¨¹ý
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        ListNode* head = nullptr, * tail = nullptr;
        if (list1->val <= list2->val)
        {
            head = tail = list1;
            list1 = list1->next;
        }
        else
        {
            head = tail = list2;
            list2 = list2->next;
        }
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
                tail = tail->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
                tail = tail->next;
            }
        }
        if (list1)
            tail->next = list1;
        else
            tail->next = list2;
        return head;
    }
};

int main()
{
    ListNode* n1 = new ListNode;
    ListNode* n2 = new ListNode;
    ListNode* n3 = new ListNode;
    ListNode* n4 = new ListNode;
    ListNode* n5 = new ListNode;
    ListNode* n6 = new ListNode;
    n1->val = 1;
    n2->val = 2;
    n3->val = 4;
    n1->next = n2;
    n2->next = n3;
    n3->next = nullptr;
    n4->val = 1;
    n5->val = 3;
    n6->val = 4;
    n4->next = n5;
    n5->next = n6;
    n6->next = nullptr;
    Solution s;
    s.mergeTwoLists(n1, n4);
}