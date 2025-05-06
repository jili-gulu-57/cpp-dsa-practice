#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//234.回文链表
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 //解法一：空间复杂度为O(n)
//class Solution {
//public:
//    bool isPalindrome(ListNode* head) {
//        ListNode* cur = head;
//        vector<int> nums;
//        while (cur != nullptr)
//        {
//            nums.push_back(cur->val);
//            cur = cur->next;
//        }
//        int left = 0, right = nums.size() - 1;
//        while (left < right)
//        {
//            if (nums[left] != nums[right])
//                return false;
//            left++;
//            right--;
//        }
//        return true;
//    }
//};

//解法二：
  class Solution {
  public:
      bool isPalindrome(ListNode* head) {
          ListNode* cur = head;
          while (cur->next)
              cur = cur->next;
          cur->next = head;

      }
  };