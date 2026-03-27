#include<iostream>
using namespace std;

//92.反转链表Ⅱ（已通过）
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

//区间反转，注意起始位置，结束位置
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count = 1;
        ListNode* begin = head, * pre = head;
        //找到起始位置
        while (count < left)
        {
            pre = begin;//找到前一个位置
            begin = begin->next;
            count++;
        }
        ListNode* end = begin, * next = end->next;
        //定位结束位置
        while (count < right)
        {
            end = end->next;
            next = end->next;
            count++;
        }
        //开始反转
        ListNode* l1 = begin, * newnode = nullptr;
        while (l1 != next)
        {
            ListNode* tmp = l1->next;
            l1->next = newnode;
            newnode = l1;
            l1 = tmp;
        }
        
        if (begin != head)//说明起始位置不是在开始，需要拼接
        {
            pre->next = newnode;
        }
        else
        {
            head = newnode;
        }

        if(next!=nullptr)//说明结束位置不是在最后，需要拼接
        {
            while (right > left)
            {
                newnode = newnode->next;
                left++;
            }
            newnode->next = next;
        }
        return head;
    }
};

int main()
{
    ListNode* l1 = new ListNode;
    ListNode* l2 = new ListNode;
    //ListNode* l3 = new ListNode;
    //ListNode* l4 = new ListNode;
    //ListNode* l5 = new ListNode;

    l1->val = 1;
    l2->val = 2;
    //l3->val = 3;
    //l4->val = 4;
    //l5->val = 5;

    l1->next = l2;
    //l2->next = l3;
    //l3->next = l4;
    //l4->next = l5;

    Solution s;
    s.reverseBetween(l1, 1, 1);
    return 0;
}