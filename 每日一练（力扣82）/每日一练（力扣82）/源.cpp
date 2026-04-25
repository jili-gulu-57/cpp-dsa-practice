#include<iostream>
using namespace std;

//82.删除排序链表中的重复元素Ⅱ（已通过）
//因为是排好序的，所以双指针即可，不用unordered_set
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head||!head->next)
            return head;//为空或者只用一个元素，直接返回

        int flag = 1;//标记是否有重复元素
        ListNode* cur = head, * next = cur->next;
        ListNode* tmp = new ListNode;
        ListNode* ans = tmp;
        while (cur)
        {
            while (next && next->val == cur->val)
            {
                cur = cur->next;
                next = next->next;
                flag = 0;
            }

            if (flag)
            {
                tmp->next = cur;
                tmp = tmp->next;
            }

            if (!next)
            {
                if (tmp)
                    tmp->next = nullptr;
                return ans->next;
            }

            if (!next->next)//next已经为空 或 next走到最后位置
            {
                if (cur->val != next->val)
                    tmp->next = next;
                return ans->next;
            }

            cur = cur->next;
            next = next->next;
            flag = 1;
        }
        return ans->next;
    }
};

class Solution2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // 处理空链表或只有一个节点的情况
        if (!head || !head->next) return head;

        // 1. 创建虚拟头节点，它的 next 指向 head
        // 这样即使 head 被删除了，我们也能通过 dummy->next 找到新的头节点
        ListNode* dummy = new ListNode(0, head);

        ListNode* prev = dummy; // prev 始终指向“已确认不重复区间”的最后一个节点
        ListNode* curr = head;  // curr 用于遍历链表探路

        while (curr && curr->next) {
            // 2. 如果发现重复元素
            if (curr->val == curr->next->val) {
                int duplicateVal = curr->val;
                // 跳过所有值等于 duplicateVal 的节点（全部删除，一个不留）
                while (curr && curr->val == duplicateVal) {
                    curr = curr->next;
                }
                // 将 prev 的 next 直接指向第一个不重复的节点
                // 这样就跳过了中间所有的重复节点
                prev->next = curr;
            }
            // 3. 如果没有重复，说明当前 curr 是安全的，prev 和 curr 正常同步后移
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        // 保存结果并释放 dummy 节点的内存
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

int main()
{
    //ListNode n7(4);
    //ListNode n6(4,&n7);
    //ListNode n5(4,&n6);
    //ListNode n4(3,&n5);
    ListNode n3(2);
    ListNode n2(2,&n3);
    ListNode n1(1,&n2);

    Solution s;
    s.deleteDuplicates(&n1);
    return 0;
}