


#include <map>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // hashtable store <index, head>
        map<int, ListNode*> dict;
        int index = 0;
        int total_num = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            dict[index] = temp;
            index++;
            total_num++;
            temp = temp->next;
        }

        int key = total_num - n;
        if (key == 0) return head->next;
        if (n == 1){
            dict[key-1]->next = nullptr;
        }
        else{
            dict[key-1]->next = dict[key]->next;
        }

        return head;
    }
};