#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
 
 //也能通过
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head==nullptr||head->next == nullptr)
            return false;
        ListNode* slow = head, * fast = head->next;
        while (slow != fast)
        {
            slow = slow->next;
            if (fast==nullptr||fast->next==nullptr)
                return false;
            fast = fast->next->next;
        }
        return true;
    }
};