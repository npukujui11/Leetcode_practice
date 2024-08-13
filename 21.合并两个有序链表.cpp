/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */
#include <iostream>
using namespace std;

//定义链表节点结构
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(-1), *p = &dummy;
        ListNode *p1 = list1, *p2 = list2;

        while (p1 != nullptr && p2 != nullptr){
            if (p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        } 

        if (p1 != nullptr) {
            p->next = p1;
        }
        if (p2 != nullptr) {
            p->next = p2;
        }

        return dummy.next;
    }
};
// @lc code=end

