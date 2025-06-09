#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//2.两数相加（已通过）
// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };
//
//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        ListNode* cur1 = l1;
//        ListNode* cur2 = l2;
//        ListNode* head = new ListNode;
//        ListNode* ans = head;
//        int jinwei = 0, sum = 0;
//        while (cur1 != nullptr && cur2 != nullptr)
//        {
//            sum = cur1->val + cur2->val + jinwei;
//            jinwei = sum / 10;
//            sum %= 10;
//            ListNode* newnode = new ListNode;
//            newnode->val = sum;
//            head->next = newnode;
//            cur1 = cur1->next;
//            cur2 = cur2->next;
//            head = head->next;
//        }
//        while (cur1)
//        {
//            sum = jinwei + cur1->val;
//            jinwei = sum / 10;
//            sum %= 10;
//            ListNode* newnode = new ListNode;
//            newnode->val = sum;
//            head->next = newnode;
//            cur1 = cur1->next;
//            head = head->next;
//        }
//        while (cur2)
//        {
//            sum = jinwei + cur1->val;
//            jinwei = sum / 10;
//            sum %= 10;
//            ListNode* newnode = new ListNode;
//            newnode->val = sum;
//            head->next = newnode;
//            cur2 = cur2->next;
//            head = head->next;
//        }
//        if (jinwei != 0)
//        {
//            ListNode* newnode = new ListNode;
//            newnode->val = jinwei;
//            head->next = newnode;
//        }
//        return ans->next;
//    }
//};


//24.两两交换链表中的节点（已通过）
// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };
// 
//class Solution {
//public:
//    ListNode* swapPairs(ListNode* head) {
//        //链表为空或者只有一个结点，直接返回
//        if (head == nullptr || head->next == nullptr)
//            return head;
//
//        //引入一个虚拟头结点，方便操作
//        ListNode* newhead = new ListNode;
//        newhead->next = head;
//
//        ListNode* pre = newhead;
//        ListNode* cur = head;
//        ListNode* next = head->next;
//        ListNode* nn = head->next->next;
//        while (cur&&next)
//        {
//            //交换结点
//            pre->next = next;
//            next->next = cur;
//            cur->next = nn;
//            //修改指针
//            pre = cur;
//            cur = nn;
//            //检查是否出现访问空结点情况
//            if (!cur)
//                break;
//            next = cur->next;
//            if (!next)
//                break;
//            nn = next->next;
//        }
//        return newhead->next;
//    }
//};

int main()
{
    ListNode* n1 = new ListNode;
    ListNode* n2 = new ListNode;
    ListNode* n3 = new ListNode;
    ListNode* n4 = new ListNode;
    //ListNode* n5 = new ListNode;
    //ListNode* n6 = new ListNode;
    //ListNode* n7 = new ListNode;
    //ListNode* n8 = new ListNode;
    //ListNode* n9 = new ListNode;
    //ListNode* n10 = new ListNode;
    //ListNode* n11= new ListNode;
    n1->val = 1;
    n2->val = 2;
    n3->val = 3;
    n4->val = 4;
    //n5->val = 9;
    //n6->val = 9;
    //n7->val = 9;
    //n8->val = 9;
    //n9->val = 9;
    //n10->val = 9;
    //n11->val = 9;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = nullptr;
    //n5->next = n6;
    //n6->next = n7;
    //n7->next = nullptr;
    //n8->next = n9;
    //n9->next = n10;
    //n10->next = n11;
    //n11->next = nullptr;
    Solution s;
    s.swapPairs(n1);
    return 0;
}