#include<iostream>
#include<unordered_set>
using namespace std;

//160.相交链表（已通过）
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> hash;
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        while (l1||l2)
        {
            if (l1 && !hash.count(l1))
            {
                hash.insert(l1);
                l1 = l1->next;
            }
            else if(hash.count(l1))
                return l1;

            if (l2 && !hash.count(l2))
            {
                hash.insert(l2);
                l2 = l2->next;
            }
            else if(hash.count(l2))
                return l2;
        }
        return nullptr;
    }
};

int main()
{
    ListNode n1(1);
    ListNode n2(9);
    ListNode n3(1);
    ListNode n4(2);
    ListNode n5(4);
    ListNode n6(3);
    //ListNode n7(1);
    //ListNode n8(1);
    //ListNode n9(1);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n6.next = &n4;
    
    Solution s;
    s.getIntersectionNode(&n1, &n6);
}
