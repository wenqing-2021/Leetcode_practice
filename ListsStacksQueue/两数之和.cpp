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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* res = new ListNode(0);
        ListNode* dummpy = new ListNode(0, res);
        bool plus = 0; // 判断条件
        while (cur1 != nullptr || cur2 != nullptr){
            int val = 0;
            // 检查cur1是否空
            if (cur1 != nullptr){
                val += cur1->val;
                cur1 = cur1->next;
            }
            // 检查cur2是否空
            if (cur2 != nullptr){
                val += cur2->val;
                cur2 = cur2->next;
            }
            if (plus){
                val += 1;
                plus = 0;
            }
            if (val >= 10){
                res->next = new ListNode(val - 10);
                plus = 1;
            }
            else{
                res->next = new ListNode(val);
            }
            res = res->next;
        }
        if (plus){
            res->next = new ListNode(1);
            plus = 0;
        }

        return dummpy->next->next;
    }
};