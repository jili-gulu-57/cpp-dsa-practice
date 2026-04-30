#include<iostream>
using namespace std;

//142.环形链表Ⅱ（已通过）
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//fast走两步，slow走一步，设无环部分长度为m，环长度为n，slow已走环的长度为l，fast走的总长度为x，slow为y
//则有：x=m+n+l，y=m+l，x=2y,解出m=n-l，此时一个节点回到head，另一个节点继续走，相遇节点即为入环节点
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        //节点为空或者只有一个节点直接返回
        if (!head || !head->next)
            return NULL;

        ListNode* slow = head->next, * fast = head->next->next;
        while (fast&&slow)
        {
            while (slow != fast)
            {
                if(!slow||!fast||!fast->next)
					return NULL;
				slow = slow->next;
                fast = fast->next->next;
            }
			//相遇说明有环，此时fast回到原点，slow继续走，直到相遇
            fast = head;
            while (fast != slow)
            {
                fast=fast->next;
				slow = slow->next;
            }
            return fast;
        }
		return NULL;
    }
};