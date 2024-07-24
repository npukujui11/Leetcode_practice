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
/*
 * 归并排序的递归解法
 * 时间复杂度：O(nlogn)
 * 检查链表是否为空或只有一个节点，如果是，则直接返回
 * 使用快慢指针找到链表的中点，将链表从中点处断开
 * 递归地对两个子链表进行排序
 * 合并两个已排序的子链表
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
/*
 * 合并两个有序链表
 * 先创建一个虚拟头节点dummy，然后用指针p指向dummy
 * 比较两个链表的节点值，将较小的节点接到p的后面
 * 当其中一个链表为空时，将另一个链表的剩余部分接到p的后面
 * 返回dummy->next
 */
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

