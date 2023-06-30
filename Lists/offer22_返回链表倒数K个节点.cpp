#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* res = head;
        int length = 0;
        while(head->next != NULL){
            head = head->next;
            length++;
        }
        for (int i = 0; i <= (length - k); i++){
            res = res->next;
        }
        return res;
    }
};