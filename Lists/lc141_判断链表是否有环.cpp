
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
    bool hasCycle(ListNode *head) {
        ListNode * slow_node = head;
        ListNode * fast_node = head;
        // 此处的循环条件一定是fast_node在前面！不然会报错
        while (fast_node && fast_node->next ){
            slow_node = slow_node->next;
            fast_node = fast_node->next->next;
            if (fast_node == slow_node){
                return true;
            }
        }
        return false;
    }
};