/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        // 哑节点
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* lastSorted = head; // 指向已排序部分的最后一个节点
        ListNode* curr = head->next; // 指向待排序部分的第一个节点

        while (curr != nullptr) { // 遍历待排序部分
            if (lastSorted->val <= curr->val) {
                lastSorted = lastSorted->next; // 如果待排序节点大于已排序部分的最后一个节点，直接插入到已排序部分的最后
            } else {
                ListNode* prev = dummy; // 从头开始遍历已排序部分
                while (prev->next->val <= curr->val) {
                    prev = prev->next; // 找到第一个大于待排序节点的节点
                }
                lastSorted->next = curr->next; // 将待排序节点插入到prev之后
                curr->next = prev->next;
                prev->next = curr;    
            }        
            curr = lastSorted->next; // 更新待排序节点
        }
        return dummy->next;
    }
};
// @lc code=end

