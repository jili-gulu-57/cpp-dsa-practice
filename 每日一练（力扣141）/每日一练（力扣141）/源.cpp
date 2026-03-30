#include<iostream>
using namespace std;

//141.环形链表（已通过）
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* f = head, * s = head;
        while (f&&s)
        {
            s = s->next;
            if (!f->next)
                return false;
            f = f->next->next;
            if (f == nullptr)
                return false;
            if (f == s)
                return true;
        }
        return false;
    }
};

int main()
{
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    //ListNode* n5 = new ListNode(5);


    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    //n4->next = n5;

    Solution  s;
    cout<<s.hasCycle(n1);
    return 0;
}