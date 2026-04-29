#include<iostream>
using namespace std;

//19.删除链表的倒数第N个节点（已通过）
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head, * slow = head;

		//快指针先走n步，之后都只走一步，当快指针走到末尾时，慢指针就正好走到要删除的节点的前一个节点
        while (n--)
        {
			fast = fast->next;
        }

		if (!fast)//fast为空，说明要删除的是头节点，直接返回头节点的下一个节点
        {
			return head->next;
        }

        while (fast->next)
        {
			fast = fast->next;
			slow = slow->next;
        }
		//fast走到末尾了，slow下一个节点指向的就是要删除的节点
		ListNode* next = slow->next;
        slow->next = next->next;
        return head;
    }
};

//void func()
//{
//    static int count = 0;
//	count++;
//	cout << count << endl;
//}

ListNode*createList(int n)
{
    ListNode* head = new ListNode(0);
    ListNode* tail = head;
    for (int i = 1; i < n; i++)
    {
        tail->next = new ListNode(i);
        tail = tail->next;
    }
    return head;
}

int main()
{
  //  int num = 3;
  //  while (num)
  //  {
		//func();
		//num--;
  //  }
    ListNode* head=createList(2);

    Solution s;
	s.removeNthFromEnd(head, 1);

    return 0;
}