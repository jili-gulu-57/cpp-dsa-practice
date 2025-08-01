#include<iostream> 
#include<vector>
#include<queue>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

//23.合并K个升序链表
//解法一：类似合并两个链表，依次将多个链表合并
//解法二：利用堆做优化，找到k个链表中的较小值，加入链表（已通过）
class Solution {
public:
    struct cmp
    {
        bool operator()(const ListNode* l1, const ListNode* l2) {
            //大的时候返回true，代表此时需要交换，交换后小的在前面，实现小根堆
            return l1->val > l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode;
        ListNode* prev = ans;
        //C++中堆默认是大顶堆，小根堆要显示构造
        priority_queue<ListNode*,vector<ListNode*>,cmp> q;
        //所有头节点进堆
        for (auto l : lists)
            if (l)    //节点为空不能进堆，否则解引用会报错
                q.push(l);
        while (q.size())
        {
            ListNode* tmp = q.top();
            prev->next = tmp;
            prev = tmp;
            q.pop();
            if (tmp->next)
                q.push(tmp->next);
        }
        return ans->next;
    }
};
//解法三：分治递归合并（已通过）
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
    ListNode* merge(vector<ListNode*>& lists, int left, int right)
    {
        if (left > right)
            return nullptr;
        if (left == right)
            return lists[left];
        int mid = (left + right) >> 1;
        //[left,mid]  [mid+1,right]
        ListNode* l1 = merge(lists, left, mid);
        ListNode* l2 = merge(lists, mid + 1, right);
        return mergeList(l1, l2);
    }
    ListNode* mergeList(ListNode* l1, ListNode* l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        ListNode head;
        ListNode* cur1 = l1, * cur2 = l2, * prev = &head;
        head.next = nullptr;
        while (cur1 && cur2)
        {
            if (cur1->val <= cur2->val)
            {
                prev->next = cur1;
                prev = prev->next;
                cur1 = cur1->next;
            }
            else
            {
                prev->next = cur2;
                prev = prev->next;
                cur2 = cur2->next;
            }
        }
        while (cur1)
        {
            prev = prev->next = cur1;
            cur1 = cur1->next;
        }
        while (cur2)
        {
            prev = prev->next = cur2;
            cur2 = cur2->next;
        }
        return head.next;
    }
};