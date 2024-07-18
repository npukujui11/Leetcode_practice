/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //递归退出条件
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *slow = head;
        ListNode *fast = head->next;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;    
        }
        
        //断开链表
        ListNode *mid = slow->next;
        slow->next = nullptr;

        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);

        return merge(left, right);
    }

private:
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;

        while(left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                p->next = left;
                left = left->next;
            } else {
                p->next = right;
                right = right->next;
            }
            p = p->next;
        }
        if (left != nullptr) {
            p->next = left;
        }else {
            p->next = right;
        }
        return dummy->next;
    }
};
// @lc code=end

