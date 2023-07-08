
#include <vector>
using namespace std;


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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;

        int length = lists.size();
        while (length > 1){
            for (int i = 0; i < length / 2; ++i){
                lists[i] = MergeTwoLists(lists[i+(length+1)/2], lists[i]);
            }
            length = (length + 1) / 2;
        }

        return lists[0];

    }
    ListNode* MergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* res = new ListNode();
        ListNode* dummy = res;

        while (l1 != nullptr && l2 != nullptr){
            if (l1->val > l2->val){
                res->next = new ListNode(l2->val);
                res = res->next;
                l2 = l2->next;
            }
            else{
                res->next = new ListNode(l1->val);
                res = res->next;
                l1 = l1->next;
            }
        }
        if (l1 == nullptr){
            res->next = l2;
        }
        else{
            res->next = l1;
        }

        return dummy->next;
    }
};