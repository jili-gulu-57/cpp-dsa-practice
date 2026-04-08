#include<iostream>
#include<deque>
using namespace std;

//143.重排链表（已通过）
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

//双端队列
class Solution {
public:
    void reorderList(ListNode* head) {
        deque<ListNode*> dq;
        ListNode* cur = head->next;
        //从第二个节点开始添加
        while (cur)
        {
            dq.push_back(cur);
            cur = cur->next;
        }
        //修改原链表
        cur = head;
        int count = 1;
        while (dq.size())
        {
            if (count % 2 == 1)
            {
                ListNode* tmp = dq.back();
                dq.pop_back();
                cur->next = tmp;
                cur = cur->next;
            }
            else
            {
                ListNode* tmp = dq.front();
                dq.pop_front();
                cur->next = tmp;
                cur = cur->next;
            }
            count++;
        }
        cur->next = nullptr;
    }
};

int main()
{
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    Solution s;
    s.reorderList(n1);
}

