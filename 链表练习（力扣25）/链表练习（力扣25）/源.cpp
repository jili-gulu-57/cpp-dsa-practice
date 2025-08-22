#include<iostream>
using namespace std;


//25.k个一组翻转链表（已通过）
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)
            return head;
        int n = 0, _k = k;
        ListNode* tmp = head;
        ListNode* newhead = new ListNode;
        while (tmp)
        {
            tmp = tmp->next;
            n++;
        }
        n /= k; //n为需要翻转的组数
        ListNode* cur = head;
        ListNode* next = cur->next;
        tmp = newhead;
        while (n--)
        {
            //头插法实现逆序
            while (_k--)
            {
                cur->next = tmp->next;
                tmp->next = cur;
                cur = next;
                if (next)
                    next = next->next;
            }
            _k = k;

            //每组翻转完，重新在最后位置尾插
            while (tmp->next)
                tmp = tmp->next;
        }
        while (cur)
        {
            tmp->next = cur;
            cur = cur->next;
            tmp = tmp->next;
        }
        return newhead->next;
    }
};
int main()
{
    ListNode* node1 = new ListNode;
    ListNode* node2 = new ListNode;
    ListNode* node3 = new ListNode;
    ListNode* node4 = new ListNode;
    ListNode* node5 = new ListNode;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;
    node1->val = 1;
    node2->val = 2;
    node3->val = 3;
    node4->val = 4;
    node5->val = 5;
    Solution s;
    s.reverseKGroup(node1, 1);

    return 0;
}