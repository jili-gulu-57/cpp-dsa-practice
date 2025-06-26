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

 //143.重排链表（已通过）
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head->next || !head->next->next)
            return;
        //通过快慢指针找到中间结点
        ListNode* slow = head, * fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //将中间结点及之后结点逆序（头插法）
        ListNode* newhead = new ListNode;

        //头插法构建新链表，将链表后半段逆序
        ListNode* cur = slow;
        while (slow)
        {
            ListNode* next = slow->next;
            slow->next = newhead->next;
            newhead->next = slow;
            slow = next;
        }

        ListNode* ans = new ListNode, * l1 = head, * l2 = newhead->next;
        ListNode* cur2 = ans;
        while (l1 != cur && l2)
        {
            cur2->next = l1;
            l1 = l1->next;
            cur2 = cur2->next;
            cur2->next = l2;
            l2 = l2->next;
            cur2 = cur2->next;
        }
        while (l1 != cur)
        {
            cur->next = l1;
            l1 = l1->next;
            cur2 = cur2->next;
        }
        while (l2)
        {
            cur2->next = l2;
            l2 = l2->next;
            cur2 = cur2->next;
        }
        head = ans->next;
    }
};

int main()
{
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    Solution s;
    s.reorderList(l1);
    return 0;
}