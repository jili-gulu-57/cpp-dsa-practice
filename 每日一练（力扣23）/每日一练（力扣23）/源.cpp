#include<iostream>
#include<vector>
using namespace std;

//23.合并k个升序链表（已通过）
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size())
        {
            return nullptr;
        }
        int k = lists.size();
        MergeSort(0, k - 1,lists);
        return lists[0];
    }
    void MergeSort(int left,int right, vector<ListNode*>& lists)
    {
        if (left == right)
            return;

        int mid = (left + right) >> 1;
        MergeSort(left, mid,lists);
        MergeSort(mid + 1, right,lists);
        ListNode* n1 = lists[left];
        ListNode* n2 = lists[right];
        ListNode* n3 = new ListNode;
        ListNode* cur = n3;
        while (n1 && n2)
        {
            if (n1 && n2 && n1->val <= n2->val)
            {
                n3->next = n1;
                n1 = n1->next;
                n3 = n3->next;
            }
            else
            {
                n3->next = n2;
                n2 = n2->next;
                n3 = n3->next;
            }
        }
        if (n1)
        {
            n3->next = n1;
        }
        if (n2)
        {
            n3->next = n2;
        }
        lists[left] = cur->next;
        lists[right] = cur->next;
    }
};

void Print(ListNode* l)
{
    while (l)
    {
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;
}

int main()
{
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(4);
    ListNode* n3 = new ListNode(5);
    ListNode* n4 = new ListNode(1);
    ListNode* n5 = new ListNode(3);
    ListNode* n6 = new ListNode(4);
    ListNode* n7 = new ListNode(2);
    ListNode* n8 = new ListNode(6);
    ListNode* n9 = new ListNode(4);
    ListNode* n10 = new ListNode(7);

    n1->next = n2;
    n2->next = n3;
    n4->next = n5;
    n5->next = n6;
    n7->next = n8;
    n9->next = n10;
    vector<ListNode*> lists;
    lists.push_back(n1);
    lists.push_back(n4);
    lists.push_back(n7);
    lists.push_back(n9);

    Solution s;
    s.mergeKLists(lists);
    Print(lists[0]);
    return 0;
}