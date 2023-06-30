
/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* temp = res;
        bool add_one = false;
        while (l1 != nullptr || l2 != nullptr){
            int v1 = 0, v2 = 0;
            if (l1 != nullptr){
                v1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr){
                v2 = l2->val;
                l2 = l2->next;
            }
            int res_val = v1 + v2;
            if (add_one){
                res_val += 1;
                add_one = false;
            }
            if (res_val >= 10){
                add_one = true;
            }
            temp->next = new ListNode(res_val % 10);
            temp = temp->next;
        }

        if (add_one){
            temp->next = new ListNode(1);
            temp = temp->next;
        }

        return res->next;
    }
};

ListNode* InitialLists(vector<int> vec){
    ListNode* res = new ListNode();
    ListNode* temp = res;
    for (auto& num : vec){
        temp->next = new ListNode(num);
        temp = temp->next;
    }
    
    return res->next;
}

int main(){
    std::vector<int> a = {2,4,3};
    std::vector<int> b = {5,6,4};

    ListNode* l1 = InitialLists(a);
    ListNode* l2 = InitialLists(b);

    Solution s1;
    ListNode* res = s1.addTwoNumbers(l1, l2);

    return 0;
}