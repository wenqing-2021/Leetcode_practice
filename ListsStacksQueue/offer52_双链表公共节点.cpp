
#include <map>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A = headA, *B = headB;
        while (A != B) {
            A = A != nullptr ? A->next : headB;
            B = B != nullptr ? B->next : headA;
        }
        return A;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<int, ListNode*> m;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while (tempA != NULL){
            m.insert(make_pair(tempA->val, tempA));
            tempA = tempA->next;
        }
        while (tempB != NULL){
            int val = tempB->val;
            if (m.find(val) == m.end()){
                tempB = tempB->next;
                continue;
            }
            auto it = m.find(val);
            if (it->second == tempB){
                return it->second;
            }
            tempB = tempB->next;
        }

        return NULL;
    }
};