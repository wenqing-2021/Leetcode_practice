/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

 #include <stack>
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* current = head;
        return recur(current, pre);
    }
private:
    ListNode* recur(ListNode* current, ListNode* pre){
        if (current == NULL) return pre;
        ListNode* res = recur(current->next, current);
        current->next = pre;
        return res;
    }
};