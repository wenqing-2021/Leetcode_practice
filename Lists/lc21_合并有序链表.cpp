/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
*/

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 != nullptr) return list2;
        if (list1 != nullptr && list2 == nullptr) return list1;
        ListNode* res = new ListNode();
        if (list1 == nullptr && list2 == nullptr) return nullptr;
        // initial res
        if (list1->val >= list2->val){
            res->val = list2->val;
            list2 = list2->next;
        }
        else{
            res->val = list1->val;
            list1 = list1->next;
        }
        ListNode* dummy = res;
        // main loop
        while (list1 != nullptr && list2 != nullptr){
            if (list1->val >= list2->val){
                res->next = new ListNode(list2->val);
                res = res->next;
                list2 = list2->next;
            }
            else{
                res->next = new ListNode(list1->val);
                res = res->next;
                list1 = list1->next;
            }
        }
        if (list1 == nullptr){
            res->next = list2;
        }
        else{
            res->next = list1;
        }

        return dummy;
    }
};