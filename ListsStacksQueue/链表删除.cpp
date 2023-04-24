#include <iostream>
using namespace std;

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
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val){
            return head->next;
        }
        ListNode* start = head;
        ListNode* previous = head;
        while(head->val != val){
            previous = head;
            head = head->next;
        }
        previous->next = head->next;
        return start;
    }
};