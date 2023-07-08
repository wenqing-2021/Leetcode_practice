#include <vector>
#include <algorithm>
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
    vector<int> reversePrint(ListNode* head) {
        vector<int> reuslt;
        ListNode *p = head;
        while(p){
            reuslt.push_back(p->val);
            p = p->next;
        }
        reverse(reuslt.begin(), reuslt.end());
        return reuslt;
    }
};