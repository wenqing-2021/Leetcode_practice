/*
给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

返回删除后的链表的头节点。

注意：此题对比原题有改动
https://leetcode.cn/problems/shan-chu-lian-biao-de-jie-dian-lcof/
*/




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