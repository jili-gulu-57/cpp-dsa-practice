#include<iostream>
#include<vector>
using namespace std;

//148.排序链表（已通过）
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //节点为空或者只有一个，直接返回
        if (!head || !head->next)
            return head;
        return MergeSort(head, nullptr);
    }
    ListNode* MergeSort(ListNode*begin, ListNode*end)
    {
        //左闭右开区间
        if (begin == end)
            return nullptr;
        if (begin->next == end)
        {
            begin->next = nullptr;
            return begin;
        }
        ListNode* slow = begin, * fast = begin;
        //找到中间节点
        while (fast!=end && fast->next!=end)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //此时slow为中间节点
        ListNode* left = MergeSort(begin, slow);
        ListNode* right = MergeSort(slow, end);

        //合并
        ListNode newhead(0);
        ListNode* cur = &newhead;

        while(left  && right )
        {
            if (left->val <= right->val)
            {
                cur->next = left;
                left = left->next;
            }
            else
            {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        if(left)
        {
            cur->next = left;
        }
        if(right)
        {
            cur->next = right;
        }
        return newhead.next;
    }
};

ListNode* CreateList(vector<int>& nums)
{
    ListNode* head = new ListNode(0), * cur = head;
    for (int i = 0; i < nums.size(); i++)
    {
        ListNode* node = new ListNode(nums[i]);
        cur->next = node;
        cur = cur->next;
    }
    return head->next;
}

int main()
{
    vector<int> nums = { 7,9,3,1,2,8,4,5 };
    ListNode* head=CreateList(nums);
    Solution s;
    s.sortList(head);
    return 0;
}

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return MergeSort(head, nullptr);
    }

    // 排序 [begin, end)
    ListNode* MergeSort(ListNode* begin, ListNode* end)
    {
        // 空区间
        if (begin == end)
            return nullptr;

        // 只有一个节点
        if (begin->next == end)
        {
            begin->next = nullptr;
            return begin;
        }

        // 快慢指针找中点
        ListNode* slow = begin;
        ListNode* fast = begin;

        while (fast != end && fast->next != end)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow 即中点
        ListNode* mid = slow;

        // 递归排序左右部分
        ListNode* left = MergeSort(begin, mid);
        ListNode* right = MergeSort(mid, end);

        // 合并两个有序链表
        ListNode dummy(0);
        ListNode* cur = &dummy;

        while (left && right)
        {
            if (left->val <= right->val)
            {
                cur->next = left;
                left = left->next;
            }
            else
            {
                cur->next = right;
                right = right->next;
            }

            cur = cur->next;
        }

        if (left)
            cur->next = left;

        if (right)
            cur->next = right;

        return dummy.next;
    }
};